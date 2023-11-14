/*
 * led_traffic.c
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */

#include "led_traffic.h"

void led_red_1_on() {
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port,LED_RED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
}

void led_yellow_1_on() {
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port,LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
}

void led_green_1_on() {
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port,LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
}

void led_red_2_on() {
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port,LED_RED_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
}

void led_yellow_2_on() {
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port,LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
}

void led_green_2_on() {
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port,LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
}

void on_traffic_1() {
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port,LED_RED_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
}

void off_traffic_1() {
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port,LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
}

void on_traffic_2() {
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port,LED_RED_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
}

void off_traffic_2() {
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port,LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
}

void controlSingleLed(int orderTraffic, int statusLed)
{
	switch (orderTraffic)
	{
	case TRAFFIC1:
		switch (statusLed)
		{
		case RED_NORMAL_MODE:
			led_red_1_on();
			break;
		case GREEN_NORMAL_MODE:
			led_green_1_on();
			break;
		case YELLOW_NORMAL_MODE:
			led_yellow_1_on();
			break;
		case RED_ADVANCED_MODE:
			HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
			break;
		case YELLOW_ADVANCED_MODE:
			HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
			break;
		case GREEN_ADVANCED_MODE:
			HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
			break;
		case OFF:
			off_traffic_1();
			break;
		case ON:
			on_traffic_1();
			break;
		default:
			break;
		}
		break;
	case TRAFFIC2:
		switch (statusLed)
		{
		case RED_NORMAL_MODE:
			led_red_2_on();
			break;
		case GREEN_NORMAL_MODE:
			led_green_2_on();
			break;
		case YELLOW_NORMAL_MODE:
			led_yellow_2_on();
			break;
		case RED_ADVANCED_MODE:
			HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
			break;
		case YELLOW_ADVANCED_MODE:
			HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
			break;
		case GREEN_ADVANCED_MODE:
			HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
			break;
		case OFF:
			off_traffic_2();
			break;
		case ON:
			on_traffic_2();
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
