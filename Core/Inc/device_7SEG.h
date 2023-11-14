/*
 * device_7SEG.h
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */

#ifndef INC_DEVICE_7SEG_H_
#define INC_DEVICE_7SEG_H_

#include "display7seg.h"

extern int led_buffer[5];

void DISPLAYALL7SEG();
void update7SEGBufferTraffic1(int time);
void update7SEGBufferTraffic2(int time);
void update7SEGBufferMode(int time);

#endif /* INC_DEVICE_7SEG_H_ */
