/*
 * device_singleLED.c
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */

#include "device_singleLED.h"

void blinkingYELLOW()
{
	controlSingleLed(TRAFFIC1, YELLOW_ADVANCED_MODE);
	controlSingleLed(TRAFFIC2, YELLOW_ADVANCED_MODE);
}

void blinkingRED()
{
	controlSingleLed(TRAFFIC1, RED_ADVANCED_MODE);
	controlSingleLed(TRAFFIC2, RED_ADVANCED_MODE);
}
void blinkingGREEN()
{
	controlSingleLed(TRAFFIC1, GREEN_ADVANCED_MODE);
	controlSingleLed(TRAFFIC2, GREEN_ADVANCED_MODE);
}
void offAllSingLEDs()
{
	controlSingleLed(TRAFFIC1, OFF);
	controlSingleLed(TRAFFIC2, OFF);
}
void onAllSingLEDs()
{
	controlSingleLed(TRAFFIC1, ON);
	controlSingleLed(TRAFFIC2, ON);
}
void onSingleRedTraffic1()
{
	controlSingleLed(TRAFFIC1, RED_NORMAL_MODE);
}
void onSingleYellowTraffic1()
{
	controlSingleLed(TRAFFIC1, YELLOW_NORMAL_MODE);
}

void onSingleGreenTraffic1()
{
	controlSingleLed(TRAFFIC1, GREEN_NORMAL_MODE);
}

void onSingleRedTraffic2()
{
	controlSingleLed(TRAFFIC2, RED_NORMAL_MODE);
}
void onSingleYellowTraffic2()
{
	controlSingleLed(TRAFFIC2, YELLOW_NORMAL_MODE);
}

void onSingleGreenTraffic2()
{
	controlSingleLed(TRAFFIC2, GREEN_NORMAL_MODE);
}
