#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "drv_spi_ili9488.h"  // spi lcd driver
#include <lcd_spi_port.h>  // lcd ports
#include <logo.h>
#include <image_process.h>
#include <Position.h>

#include <rt_ai_parts_classification_model.h>
#include <rt_ai.h>
#include <rt_ai_log.h>
#include <backend_cubeai.h>

#define LED_PIN GET_PIN(I, 8)

struct rt_event ov2640_event;

extern int rt_gc0328c_init(void);
extern void DCMI_Start(void);

rt_ai_buffer_t ai_flag = 0;

int index_max, max;

int main(void)
{
//    rt_uint16_t i;
//    rt_uint8_t Threshold;
//    rt_uint8_t shuliang[3] = {0,0,0};
//    rt_uint16_t position[2];
//    rt_uint8_t* gray_image = rt_malloc(320*240*3);
//    rt_uint8_t* gray_1 = rt_malloc(320*240);
//    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
//
    lcd_show_image(0, 0, 320, 240, LOGO);
    lcd_show_string(45, 156, 16, "Identification preparating...");
//    rt_thread_mdelay(1000);
//
//    rt_event_init(&ov2640_event, "ov2640", RT_IPC_FLAG_FIFO);
//
//    struct drv_lcd_device *lcd;
//    struct rt_device_rect_info rect_info = {0, 0, LCD_WIDTH, 240};
//    lcd = (struct drv_lcd_device *)rt_device_find("lcd");
//
//    rt_thread_mdelay(1000);
//
//    static rt_ai_t model = NULL;
//    model = rt_ai_find(RT_AI_PARTS_CLASSIFICATION_MODEL_NAME);
//    if(!model) {rt_kprintf("ai model find err\r\n"); return -1;}//寻找模型
//
//    rt_ai_buffer_t *input_image = rt_malloc(RT_AI_PARTS_CLASSIFICATION_IN_1_SIZE_BYTES);
//    if (!input_image) {rt_kprintf("malloc err\n"); return -1;}//建立输入模型图像存储空间
//
//    rt_ai_buffer_t *work_buf = rt_malloc(RT_AI_PARTS_CLASSIFICATION_WORK_BUFFER_BYTES);
//    if (!work_buf) {rt_kprintf("malloc err\n"); return -1;}//建立模型推理运行空间
//
//    rt_ai_buffer_t *_out = rt_malloc(RT_AI_PARTS_CLASSIFICATION_OUT_1_SIZE_BYTES);//建立输出存储空间
//    if (!_out) {rt_kprintf("malloc err\n"); return -1;}//
//
//    rt_ai_buffer_t model_init = rt_ai_init(model, work_buf);//AI模型初始化
//    if (model_init != 0) {rt_kprintf("ai init err\n"); return -1;}
//    rt_ai_config(model, CFG_INPUT_0_ADDR, input_image);
//    rt_ai_config(model, CFG_OUTPUT_0_ADDR, _out);
//    ai_flag = 1;

//    rt_gc0328c_init();
//    DCMI_Start();
//
//    while(1)
//    {
//        rt_pin_write(LED_PIN, PIN_LOW);
//        rt_event_recv(&ov2640_event,
//                            1,
//                            RT_EVENT_FLAG_AND | RT_EVENT_FLAG_CLEAR,
//                            RT_WAITING_FOREVER,
//                            RT_NULL);
//        rt_pin_write(LED_PIN, PIN_HIGH);
//        lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info);
//        for(i=0;i<240;i++)
//        {
//            rgb888_to_gray(lcd->lcd_info.framebuffer+(i*320*3), gray_image+(i*320*3),320);
//        }//必须
//        for(i=0;i<240;i++)
//        {
//            gray_3_to_1(gray_image+(i*320*3), gray_1+(i*320), 320);
//        }//必须
//        Threshold = otsuThreshold(gray_1, 320, 240);//得到阈值后，直接用单通道灰度值与阈值进行比较
//        Find_Position(gray_1, 320, 240, Threshold, position);
//        if(position[0]>=31)
//        {
//            for(i=position[0]-31;i<position[0]+33;i++)
//            {
//                rgb888_to_ai(lcd->lcd_info.framebuffer+(i*320*3), input_image+((i-position[0]+31)*64*3), 64, position[1]);
//            }
//        }
//        lcd_draw_circle(position[1], position[0], 32);
//        lcd_show_image(160, 240, 160, 80, SHULIANG);
//        lcd_show_image(160, 360, 160, 80, WEIZHI);
//        lcd_show_num(185,430,position[0],3,32);
//        lcd_show_num(250,430,position[1],3,32);
//        if (ai_flag > 0)
//        {
//            rt_ai_run(model, NULL, NULL);
//            uint8_t *out = (uint8_t *)rt_ai_output(model, 0); //得到模型输出
//
//            max = out[0];index_max=0;
//            if(max < out[1])
//            {max = out[1];index_max=1;}
//            if(max < out[2])
//            {max = out[2];index_max=2;}
//
//            if (index_max ==0)
//            {
//                lcd_show_image(0, 240, 160, 240, CHILUN);
//                shuliang[0]++;
//                lcd_show_num(230,325,shuliang[0],3,32);
//            }
//            else if (index_max == 1)
//            {
//                lcd_show_image(0, 240, 160, 240, DIANPIAN);
//                shuliang[1]++;
//                lcd_show_num(230,325,shuliang[1],3,32);
//            }
//            else if(index_max == 2)
//            {
//                lcd_show_image(0, 240, 160, 240, LUOSHUAN);
//                shuliang[2]++;
//                lcd_show_num(230,325,shuliang[2],3,32);
//            }
//        }
//        DCMI_Start();
//    }
//    free(gray_1);
//    free(gray_image);
//    rt_free(input_image);
//    rt_free(work_buf);
//    rt_free(_out);//释放存储空间
//    return RT_EOK;
}

#include "stm32h7xx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal QSPI_FLASH */
    SCB->VTOR = QSPI_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);

int AI_sample()
{
    rt_uint16_t i, flag = 0;
        rt_uint8_t Threshold;
        rt_uint8_t shuliang[3] = {0,0,0};
        rt_uint16_t position[2];
        rt_uint8_t* gray_image = rt_malloc(320*240*3);
        rt_uint8_t* gray_1 = rt_malloc(320*240);
        rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);


        rt_event_init(&ov2640_event, "ov2640", RT_IPC_FLAG_FIFO);

        struct drv_lcd_device *lcd;
        struct rt_device_rect_info rect_info = {0, 0, LCD_WIDTH, 240};
        lcd = (struct drv_lcd_device *)rt_device_find("lcd");

        rt_thread_mdelay(1000);

        static rt_ai_t model = NULL;
        model = rt_ai_find(RT_AI_PARTS_CLASSIFICATION_MODEL_NAME);
        if(!model) {rt_kprintf("ai model find err\r\n"); return -1;}//寻找模型

        rt_ai_buffer_t *input_image = rt_malloc(RT_AI_PARTS_CLASSIFICATION_IN_1_SIZE_BYTES);
        if (!input_image) {rt_kprintf("malloc err\n"); return -1;}//建立输入模型图像存储空间

        rt_ai_buffer_t *work_buf = rt_malloc(RT_AI_PARTS_CLASSIFICATION_WORK_BUFFER_BYTES);
        if (!work_buf) {rt_kprintf("malloc err\n"); return -1;}//建立模型推理运行空间

        rt_ai_buffer_t *_out = rt_malloc(RT_AI_PARTS_CLASSIFICATION_OUT_1_SIZE_BYTES);//建立输出存储空间
        if (!_out) {rt_kprintf("malloc err\n"); return -1;}//

        rt_ai_buffer_t model_init = rt_ai_init(model, work_buf);//AI模型初始化
        if (model_init != 0) {rt_kprintf("ai init err\n"); return -1;}
        rt_ai_config(model, CFG_INPUT_0_ADDR, input_image);
        rt_ai_config(model, CFG_OUTPUT_0_ADDR, _out);
        ai_flag = 1;
        rt_gc0328c_init();
        DCMI_Start();

        while(1)
        {
            rt_pin_write(LED_PIN, PIN_LOW);
            rt_event_recv(&ov2640_event,
                                1,
                                RT_EVENT_FLAG_AND | RT_EVENT_FLAG_CLEAR,
                                RT_WAITING_FOREVER,
                                RT_NULL);
            rt_pin_write(LED_PIN, PIN_HIGH);
            lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info);
            for(i=0;i<240;i++)
            {
                rgb888_to_gray(lcd->lcd_info.framebuffer+(i*320*3), gray_image+(i*320*3),320);
            }//必须
            for(i=0;i<240;i++)
            {
                gray_3_to_1(gray_image+(i*320*3), gray_1+(i*320), 320);
            }//必须
            Threshold = otsuThreshold(gray_1, 320, 240);//得到阈值后，直接用单通道灰度值与阈值进行比较
            Find_Position(gray_1, 320, 240, Threshold, position);
            if(position[0]>=31)
            {
                for(i=position[0]-31;i<position[0]+33;i++)
                {
                    rgb888_to_ai(lcd->lcd_info.framebuffer+(i*320*3), input_image+((i-position[0]+31)*64*3), 64, position[1]);
                }
            }
            lcd_draw_circle(position[1], position[0], 32);
            lcd_show_image(160, 240, 160, 80, SHULIANG);
            lcd_show_image(160, 360, 160, 80, WEIZHI);
            lcd_show_num(185,430,position[0],3,32);
            lcd_show_num(250,430,position[1],3,32);
            if (ai_flag > 0)
            {
                rt_ai_run(model, NULL, NULL);
                uint8_t *out = (uint8_t *)rt_ai_output(model, 0); //得到模型输出

                max = out[0];index_max=0;
                if(max < out[1])
                {max = out[1];index_max=1;}
                if(max < out[2])
                {max = out[2];index_max=2;}

                if (index_max ==0)
                {
                    lcd_show_image(0, 240, 160, 240, LUOSHUAN);
                    shuliang[0] = 1;
                    lcd_show_num(230,325,shuliang[0],3,32);
                }
                else if (index_max == 1)
                {
                    lcd_show_image(0, 240, 160, 240, DIANPIAN);
                    shuliang[1] = 1;
                    lcd_show_num(230,325,shuliang[1],3,32);
                }
                else if(index_max == 2)
                {
                    lcd_show_image(0, 240, 160, 240, LUOSHUAN);
                    shuliang[2] = 1;
                    lcd_show_num(230,325,shuliang[2],3,32);
                }
            }
            DCMI_Start();
            flag++;
            if(flag == 2)
                break;
        }
        free(gray_1);
        free(gray_image);
        rt_free(input_image);
        rt_free(work_buf);
        rt_free(_out);//释放存储空间
        while(1);
        return RT_EOK;
}

MSH_CMD_EXPORT(AI_sample, AI sample);

