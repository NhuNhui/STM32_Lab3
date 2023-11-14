/*
 * device_7SEG.c
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */


#include "device_7SEG.h"

void update7SEGBuffer(int time, int index_traffic)
{
	switch (index_traffic)
	{
	case 1:
		led_buffer[0] = time / 10;
		led_buffer[1] = time % 10;
		break;
	case 2:
		led_buffer[2] = time / 10;
		led_buffer[3] = time % 10;
		break;
	case 3:
		led_buffer[4] = time;
		break;
	default:
		break;
	}
}

void update7SEGBufferTraffic1(int time)
{
	update7SEGBuffer(time, 1);
}

void update7SEGBufferTraffic2(int time)
{
	update7SEGBuffer(time, 2);
}

void update7SEGBufferMode(int time)
{
	update7SEGBuffer(time, 3);
}

void DISPLAYALL7SEG()
{
	Scan7SEG();
}
