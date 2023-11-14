/*
 * Nomal_mode.c
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */

#include "Nomal_mode.h"

int statusTraffic1 = INIT1;
int statusTraffic2 = INIT2;

int tempDurationLedRed = 7;
int tempDurationLedGreen = 5;
int tempDurationLedYellow = 2;

int durationLedRed = 7;
int durationLedGreen = 5;
int durationLedYellow = 2;

int counterLedRed1;
int counterLedRed2;
int counterLedGreen1;
int counterLedGreen2;
int counterLedYellow1;
int counterLedYellow2;

void normalModeFunction()
{
	switch (statusTraffic1)
	{
	case INIT1:
		counterLedRed1 = durationLedRed;
		statusTraffic1 = STATUS1_1;
		onSingleRedTraffic1();
		update7SEGBufferTraffic1(counterLedRed1);
		break;
	case STATUS1_1:
		if (counterLedRed1 > 0)
		{
			counterLedRed1--;
			if (counterLedRed1 <= 0)
			{
				counterLedGreen1 = durationLedGreen;
				statusTraffic1 = STATUS1_2;
				onSingleGreenTraffic1();
				update7SEGBufferTraffic1(counterLedGreen1);
			}
			else
			{
				onSingleRedTraffic1();
				update7SEGBufferTraffic1(counterLedRed1);
			}
		}
		break;
	case STATUS1_2:
		if (counterLedGreen1 > 0)
		{
			counterLedGreen1--;
			if (counterLedGreen1 <= 0)
			{
				counterLedYellow1 = durationLedYellow;
				statusTraffic1 = STATUS1_3;
				onSingleYellowTraffic1();
				update7SEGBufferTraffic1(counterLedYellow1);
			}
			else
			{
				onSingleGreenTraffic1();
				update7SEGBufferTraffic1(counterLedGreen1);
			}
		}
		break;
	case STATUS1_3:
		if (counterLedYellow1 > 0)
		{
			counterLedYellow1--;
			if (counterLedYellow1 <= 0)
			{
				counterLedRed1 = durationLedRed;
				statusTraffic1 = STATUS1_1;
				onSingleRedTraffic1();
				update7SEGBufferTraffic1(counterLedRed1);
			}
			else
			{
				onSingleYellowTraffic1();
				update7SEGBufferTraffic1(counterLedYellow1);
			}
		}
		break;
	default:
		break;
	}
	switch (statusTraffic2)
	{
	case INIT2:
		statusTraffic2 = STATUS2_1;
		counterLedGreen2 = durationLedGreen;
		onSingleGreenTraffic2();
		update7SEGBufferTraffic2(counterLedGreen2);
		break;
	case STATUS2_1:
		if (counterLedGreen2 > 0)
		{
			counterLedGreen2--;
			if (counterLedGreen2 <= 0)
			{
				onSingleYellowTraffic2();
				counterLedYellow2 = durationLedYellow;
				statusTraffic2 = STATUS2_2;
				update7SEGBufferTraffic2(counterLedYellow2);
			}
			else
			{
				onSingleGreenTraffic2();
				update7SEGBufferTraffic2(counterLedGreen2);
			}
		}
		break;
	case STATUS2_2:
		if (counterLedYellow2 > 0)
		{
			counterLedYellow2--;
			if (counterLedYellow2 <= 0)
			{
				counterLedRed2 = durationLedRed;
				statusTraffic2 = STATUS2_3;
				onSingleRedTraffic2();
				update7SEGBufferTraffic2(counterLedRed2);
			}
			else
			{
				onSingleYellowTraffic2();
				update7SEGBufferTraffic2(counterLedYellow2);
			}
		}
		break;
	case STATUS2_3:
		if (counterLedRed2 > 0)
		{
			counterLedRed2--;
			if (counterLedRed2 <= 0)
			{
				counterLedGreen2 = durationLedGreen;
				statusTraffic2 = STATUS2_1;
				onSingleGreenTraffic2();
				update7SEGBufferTraffic2(counterLedGreen2);
			}
			else
			{
				onSingleRedTraffic2();
				update7SEGBufferTraffic2(counterLedRed2);
			}
		}
		break;
	default:
		break;
	}
}
