/*
 * button.c
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */

#include "button.h"

GPIO_TypeDef *buttonPort[3] = {BUTTON_1_GPIO_Port, BUTTON_2_GPIO_Port, BUTTON_3_GPIO_Port};
uint16_t buttonPin[3] = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin};

int state0Button[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int state1Button[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int state2Button[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int state3Button[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int flagButton[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int durationPressLongButton[3] = {100, 100, 100};
int durationPressShortButton[3] = {20, 20, 20};

void getInput()
{
	for (int i = 0; i < 3; i++)
	{
		state1Button[i] = state2Button[i];
		state2Button[i] = state3Button[i];
		state3Button[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
		if ((state1Button[i] == state2Button[i]) && (state2Button[i] == state3Button[i]))
		{
			if (state0Button[i] != state1Button[i])
			{
				switch (state0Button[i])
				{
				case PRESSED_STATE:
					state0Button[i] = NORMAL_STATE;
					if (durationPressShortButton[i] > 0)
					{
						flagButton[i] = PRESSED_STATE;
					}
					break;
				case NORMAL_STATE:
					state0Button[i] = PRESSED_STATE;
					durationPressLongButton[i] = 100;
					durationPressShortButton[i] = 20;
					break;
				default:
					break;
				}
			}
			else
			{
				switch (state0Button[i])
				{
				case NORMAL_STATE:
					break;
				case PRESSED_STATE:
					if (durationPressLongButton[i] > 0)
					{
						durationPressLongButton[i]--;
						if (durationPressLongButton[i] <= 0)
						{
							flagButton[i] = PRESSED_STATE;
							if (i == 1)
							{
								durationPressLongButton[i] = 10;
							}
						}
					}
					if (durationPressShortButton[i] > 0)
					{
						durationPressShortButton[i]--;
					}
					break;
				default:
					break;
				}
			}
		}
	}
}


