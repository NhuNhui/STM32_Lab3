/*
 * button.h
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

//extern int button1_flag;
//extern int button2_flag;
//extern int button3_flag;


//void getKey1Input();
//void getKey2Input();
//void getKey3Input();
//
//extern int isButton2Pressed();
//extern int isButton3Pressed();

extern int flagButton[3];
void getInput();


#endif /* INC_BUTTON_H_ */
