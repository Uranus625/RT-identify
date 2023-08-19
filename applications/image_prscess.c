/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-05-26     zqe       the first version
 */

#include <rtthread.h>
#include <math.h>
#include <stdlib.h>

void rgb888_to_gray(rt_uint8_t *rgb888Color, rt_uint8_t *gray, rt_uint16_t col)
{
    rt_uint8_t gray_color;
    rt_uint32_t i, n;
    for(n=0, i=0; n<col; n++, i+=3)
    {
        gray_color = (rt_uint8_t)(rgb888Color[i]*0.299+rgb888Color[i+1]*0.587+rgb888Color[i+2]*0.114);
        gray[i] = gray[i+1] = gray[i+2] = gray_color;
    }
}

void gray_3_to_1(rt_uint8_t* gray_3, rt_uint8_t* gray_1, rt_uint16_t col)
{
    rt_uint32_t i, n;
    for(i=0,n=0;n<col;n++, i+=3)
        gray_1[n]=gray_3[i];
}

void gray_to_binary(rt_uint8_t* gray, rt_uint8_t* binary, rt_uint16_t col, rt_uint8_t threshold)
{
    rt_uint32_t i, n;
    for(n=0, i=0; n<col; n++, i+=3)
    {
        if(gray[i]<=threshold)
            binary[i]=binary[i+1]=binary[i+2]=0;
        else
            binary[i]=binary[i+1]=binary[i+2]=255;
    }
}

//w0为背景像素点占整幅图像的比例
//u0为w0平均灰度
//w1为前景像素点占整幅图像的比例
//u1为w1平均灰度
//u为整幅图像的平均灰度
//类间方差公式 g = w1 * w2 * (u1 - u2) ^ 2

rt_uint8_t otsuThreshold(rt_uint8_t *image, rt_uint16_t col, rt_uint16_t row)
{
    #define GrayScale 256
    rt_uint16_t width = col;
    rt_uint16_t height = row;
    rt_uint16_t pixelCount[GrayScale] = {0}; //每个灰度值所占像素个数
    rt_uint16_t i, j;   //总像素
    rt_uint32_t pixelSum = width * height;
    rt_uint8_t threshold = 0;
    rt_uint8_t* data = image;  //指向像素数据的指针

    for(i=0;i<GrayScale;i++)
    {
        pixelCount[i]=0;
    }

    //统计灰度级中每个像素在整幅图像中的个数
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            pixelCount[(rt_uint8_t)data[i * width + j]]++;  //将像素值作为计数数组的下标
        }
    }
    //rt_kprintf("%x \n", pixelCount[124]);
    //遍历灰度级[0,255]
    rt_uint32_t n0, n1, u0tmp, u1tmp;
    double w0, w1, u0, u1, deltaTmp, deltaMax = 0;
    for (i = 0; i < GrayScale; i++)     // i作为阈值
    {
        n0 = n1 =0;
        w0 = w1 = u0tmp = u1tmp = u0 = u1 = deltaTmp = 0;
        for (j = 0; j < GrayScale; j++)
        {
             if (j <= i)   //背景部分
             {
                n0 += pixelCount[j];
                u0tmp += j * pixelCount[j];
             }
             else   //前景部分
             {
                n1 += pixelCount[j];
                u1tmp += j * pixelCount[j];
             }
        }
        w0 = (double)n0*10000 / pixelSum;
        w1 = (double)n1*10000 / pixelSum;
        u0 = (double)u0tmp / n0;//背景平均灰度μ0
        u1 = (double)u1tmp / n1;//前景平均灰度μ1
        deltaTmp = (double)(w0 *w1* pow((u0 - u1), 2)); //类间方差公式 g = w1 * w2 * (u1 - u2) ^ 2
        if (deltaTmp >= deltaMax)
        {
            deltaMax = deltaTmp;
            threshold = i;
        }
    }
    return threshold;
}

void Find_Position(rt_uint8_t *image, rt_uint16_t col, rt_uint16_t row, rt_uint8_t threshold, rt_uint16_t *position)
{
    rt_uint16_t i, j;
    rt_uint16_t first_row = 0, second_row = 0;
    rt_uint16_t first_col = 0, second_col = 0;
    rt_uint8_t next_part_flag = 0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(image[i*col+j]<=threshold)
                continue;
            else if(image[i*col+j]>threshold && next_part_flag==0)
            {
                first_row = i;
                next_part_flag = 1;
                break;
            }
            else if(image[i*col+j]>threshold && next_part_flag==1)
                break;
        }
        if(j==col&&next_part_flag==1)
        {
            second_row = i-1;
            next_part_flag = 0;
            break;
        }
    }
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            if(image[j*col+i]<=threshold)
                continue;
            else if(image[j*col+i]>threshold && next_part_flag==0)
            {
                first_col = i;
                next_part_flag = 1;
                break;
            }
            else if(image[j*col+i]>threshold && next_part_flag==1)
                break;
        }
        if(j==row&&next_part_flag == 1)
        {
            second_col = i-1;
            next_part_flag = 0;
            break;
        }
    }
    position[0] = (first_row + second_row)/2;
    position[1] = (first_col + second_col)/2;
}

void rgb888_to_ai(rt_uint8_t *rgb888Color, rt_uint8_t *ai, rt_uint16_t col, rt_uint16_t col_position)
{
    rt_uint8_t n;
    rt_uint16_t m, i = col_position-31;
    for(n=0,m=0;n<col;n++,m+=3)
    {
        ai[m]=rgb888Color[i*3+m];
        ai[m+1]=rgb888Color[i*3+m];
        ai[m+2]=rgb888Color[i*3+m];
    }
}
