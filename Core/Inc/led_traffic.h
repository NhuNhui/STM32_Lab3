/*
 * led_traffic.h
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */

#ifndef INC_LED_TRAFFIC_H_
#define INC_LED_TRAFFIC_H_

#include "main.h"

#define RED_NORMAL_MODE 0
#define GREEN_NORMAL_MODE 1
#define YELLOW_NORMAL_MODE 2
#define RED_ADVANCED_MODE 3
#define GREEN_ADVANCED_MODE 4
#define YELLOW_ADVANCED_MODE 5
#define OFF 6
#define ON 7
#define TRAFFIC1 8
#define TRAFFIC2 9

void controlSingleLed(int orderTraffic, int statusLed);


#endif /* INC_LED_TRAFFIC_H_ */
