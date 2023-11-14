/*
 * display7seg.c
 *
 *  Created on: Nov 14, 2023
 *      Author: QUI
 */

#include "display7seg.h"

#define INIT 0
#define SEG7_1ON 1
#define SEG7_2ON 2
#define SEG7_3ON 3
#define SEG7_4ON 4
#define SEG7_5ON 5

int status7SEG = INIT;
int led_buffer[5] = {1, 2, 3, 4, 1};

void display7SEG(int count) {
	if(count == 0) {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,RESET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,RESET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,RESET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,RESET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,RESET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,RESET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,SET);
	}
	else if(count == 1) {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,SET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,RESET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,RESET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,SET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,SET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,SET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,SET);
	}
	else if(count == 2) {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,RESET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,RESET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,SET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,RESET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,RESET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,SET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,RESET);
	}
	else if(count == 3) {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,RESET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,RESET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,RESET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,RESET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,SET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,SET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,RESET);
	}
	else if(count == 4) {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,SET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,RESET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,RESET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,SET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,SET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,RESET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,RESET);
	}
	else if(count == 5) {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,RESET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,SET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,RESET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,RESET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,SET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,RESET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,RESET);
	}
	else if(count == 6) {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,RESET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,SET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,RESET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,RESET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,RESET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,RESET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,RESET);
	}
	else if(count == 7) {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,RESET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,RESET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,RESET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,SET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,SET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,SET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,SET);
	}
	else if(count == 8) {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,RESET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,RESET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,RESET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,RESET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,RESET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,RESET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,RESET);
	}
	else {
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,RESET);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,RESET);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,RESET);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,RESET);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,SET);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,RESET);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,RESET);
	}
}

void Scan7SEG()
{
	switch (status7SEG)
	{
	case INIT:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 1);
		display7SEG(led_buffer[0]);
		status7SEG = SEG7_1ON;
		break;
	case SEG7_1ON:
		HAL_GPIO_TogglePin(EN0_GPIO_Port, EN0_Pin);
		HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);
		display7SEG(led_buffer[1]);
		status7SEG = SEG7_2ON;
		break;
	case SEG7_2ON:
		HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);
		HAL_GPIO_TogglePin(EN2_GPIO_Port, EN2_Pin);
		display7SEG(led_buffer[2]);
		status7SEG = SEG7_3ON;
		break;
	case SEG7_3ON:
		HAL_GPIO_TogglePin(EN2_GPIO_Port, EN2_Pin);
		HAL_GPIO_TogglePin(EN3_GPIO_Port, EN3_Pin);
		status7SEG = SEG7_4ON;
		display7SEG(led_buffer[3]);
		break;
	case SEG7_4ON:
		HAL_GPIO_TogglePin(EN3_GPIO_Port, EN3_Pin);
		HAL_GPIO_TogglePin(EN4_GPIO_Port, EN4_Pin);
		status7SEG = SEG7_5ON;
		display7SEG(led_buffer[4]);
		break;
	case SEG7_5ON:
		HAL_GPIO_TogglePin(EN4_GPIO_Port, EN4_Pin);
		HAL_GPIO_TogglePin(EN0_GPIO_Port, EN0_Pin);
		status7SEG = SEG7_1ON;
		display7SEG(led_buffer[0]);
		break;
	default:
		break;
	}
}

