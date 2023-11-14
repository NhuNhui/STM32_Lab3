/*
 * display7seg.h
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "main.h"

extern int led_buffer[5];

void display7SEG(int count);
void Scan7SEG();

#endif /* INC_DISPLAY7SEG_H_ */
