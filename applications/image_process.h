/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-05-26     zqe       the first version
 */
#ifndef APPLICATIONS_IMAGE_PROCESS_H_
#define APPLICATIONS_IMAGE_PROCESS_H_

void rgb888_to_gray(rt_uint8_t *rgb888Color, rt_uint8_t *gray, int col);
rt_uint16_t otsuThreshold(rt_uint8_t *image, rt_uint16_t col, rt_uint16_t row);
void gray_3_to_1(rt_uint8_t* gray_3, rt_uint8_t* gray_1, rt_uint16_t col);
void gray_to_binary(rt_uint8_t* gray, rt_uint8_t* binary, rt_uint16_t col, rt_uint8_t threshold);
void Find_Position(rt_uint8_t *image, rt_uint16_t col, rt_uint16_t row, rt_uint8_t threshold, rt_uint16_t *position);
void rgb888_to_ai(rt_uint8_t *rgb888Color, rt_uint8_t *ai, rt_uint16_t col, rt_uint16_t col_position);

#endif /* APPLICATIONS_IMAGE_PROCESS_H_ */
