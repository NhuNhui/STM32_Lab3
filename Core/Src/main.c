/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "display7seg.h"
#include "led_traffic.h"
#include "button.h"
#include "timer.h"
#include "Nomal_mode.h"
#include "device_singleLED.h"
#include "device_7SEG.h"
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define INITMODE 0
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
int modeStatus = MODE1;
int flagAdvancedMode = 0;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);

  /* USER CODE END 2 */
  /* USER CODE BEGIN WHILE */
  	offAllSingLEDs();
  	normalModeFunction();
  	setTimer2(100);
  	DISPLAYALL7SEG();
  	setTimer4(20);
  	setTimer1(1);
  	while (1)
  	{
  		if (flag1 == 1) // flag for button
  		{
  			setTimer1(1);
  			getInput();
  			if (flagButton[0] == PRESSED_STATE)
  			{
  				flagButton[0] = NORMAL_STATE;
  				switch (modeStatus)
  				{
  				case INITMODE:
  					modeStatus = MODE1;
  					flagAdvancedMode = 0;
  					tempDurationLedGreen = durationLedGreen;
  					tempDurationLedRed = durationLedRed;
  					tempDurationLedYellow = durationLedYellow;
  					offAllSingLEDs();
  					update7SEGBufferMode(MODE1);
  					normalModeFunction();
  					setTimer2(100);
  					DISPLAYALL7SEG();
  					setTimer4(20);
  					break;
  				case MODE1:
  					modeStatus = MODE2;
  					flagAdvancedMode = 1;
  					offAllSingLEDs();
  					blinkingRED();
  					setTimer3(50);
  					update7SEGBufferTraffic1(durationLedRed);
  					update7SEGBufferTraffic2(durationLedRed);
  					update7SEGBufferMode(MODE2);
  					break;
  				case MODE2:
  					modeStatus = MODE3;
  					flagAdvancedMode = 1;
  					offAllSingLEDs();
  					blinkingYELLOW();
  					setTimer3(50);
  					update7SEGBufferTraffic1(durationLedYellow);
  					update7SEGBufferTraffic2(durationLedYellow);
  					update7SEGBufferMode(MODE3);
  					break;
  				case MODE3:
  					modeStatus = MODE4;
  					flagAdvancedMode = 1;
  					offAllSingLEDs();
  					blinkingGREEN();
  					setTimer3(50);
  					update7SEGBufferTraffic1(durationLedGreen);
  					update7SEGBufferTraffic2(durationLedGreen);
  					update7SEGBufferMode(MODE4);
  					break;
  				case MODE4:
  					modeStatus = MODE1;
  					flagAdvancedMode = 0;
  					tempDurationLedGreen = durationLedGreen;
  					tempDurationLedRed = durationLedRed;
  					tempDurationLedYellow = durationLedYellow;
  					offAllSingLEDs();
  					update7SEGBufferMode(MODE1);
  					normalModeFunction();
  					setTimer2(100);
  					break;
  				default:
  					break;
  				}
  			}
  			if (flagButton[1] == PRESSED_STATE)
  			{
  				flagButton[1] = NORMAL_STATE;
  				switch (modeStatus)
  				{
  				case MODE2:
  					tempDurationLedRed++;
  					if (tempDurationLedRed > 99)
  					{
  						tempDurationLedRed = 0;
  					}
  					update7SEGBufferTraffic1(tempDurationLedRed);
  					update7SEGBufferTraffic2(tempDurationLedRed);
  					break;
  				case MODE3:
  					tempDurationLedYellow++;
  					if (tempDurationLedYellow > 99)
  					{
  						tempDurationLedYellow = 0;
  					}
  					update7SEGBufferTraffic1(tempDurationLedYellow);
  					update7SEGBufferTraffic2(tempDurationLedYellow);
  					break;
  				case MODE4:
  					tempDurationLedGreen++;
  					if (tempDurationLedGreen > 99)
  					{
  						tempDurationLedGreen = 0;
  					}
  					update7SEGBufferTraffic1(tempDurationLedGreen);
  					update7SEGBufferTraffic2(tempDurationLedGreen);
  					break;
  				default:
  					break;
  				}
  			}
  			if (flagButton[2] == PRESSED_STATE)
  			{
  				flagButton[2] = NORMAL_STATE;
  				if (tempDurationLedRed != tempDurationLedYellow + tempDurationLedGreen)
  				{
  					switch (modeStatus)
  					{
  					case MODE4:
  						update7SEGBufferTraffic1(88);
  						update7SEGBufferTraffic2(88);
  						update7SEGBufferMode(8);
  						onAllSingLEDs();
  						modeStatus = INITMODE;
  						break;
  					default:
  						break;
  					}
  				}
  				else
  				{
  					durationLedGreen = tempDurationLedGreen;
  					durationLedRed = tempDurationLedRed;
  					durationLedYellow = tempDurationLedYellow;
  					statusTraffic1 = INIT1;
  					statusTraffic2 = INIT2;
  					if (modeStatus == 1 || modeStatus == 0)
  					{
  						normalModeFunction();
  						setTimer2(1000);
  					}
  				}
  			}
  		}
  		if (flag2 == 1) // flag normal led
  		{
  			setTimer2(100);
  			if (flagAdvancedMode == 0)
  			{
  				normalModeFunction();
  			}
  		}
  		if (flag3 == 1) // flag for model modify
  		{
  			setTimer3(50);
  			if (flagAdvancedMode == 1)
  			{
  				switch (modeStatus)
  				{
  				case MODE2:
  					blinkingRED();
  					break;
  				case MODE3:
  					blinkingYELLOW();
  					break;
  				case MODE4:
  					blinkingGREEN();
  					break;
  				default:
  					break;
  				}
  			}
  		}
  		if (flag4 == 1)
  		{
  			DISPLAYALL7SEG();
  			setTimer4(20);
  		}



  	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_TEST_Pin|EN0_Pin|EN1_Pin|EN2_Pin
                          |EN3_Pin|LED_RED_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_1_Pin
                          |LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|EN4_Pin
                          |D_Pin|E_Pin|F_Pin|G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BUTTON_1_Pin BUTTON_2_Pin BUTTON_3_Pin */
  GPIO_InitStruct.Pin = BUTTON_1_Pin|BUTTON_2_Pin|BUTTON_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_TEST_Pin EN0_Pin EN1_Pin EN2_Pin
                           EN3_Pin LED_RED_1_Pin LED_YELLOW_1_Pin LED_GREEN_1_Pin
                           LED_RED_2_Pin LED_YELLOW_2_Pin LED_GREEN_2_Pin */
  GPIO_InitStruct.Pin = LED_TEST_Pin|EN0_Pin|EN1_Pin|EN2_Pin
                          |EN3_Pin|LED_RED_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_1_Pin
                          |LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin EN4_Pin
                           D_Pin E_Pin F_Pin G_Pin */
  GPIO_InitStruct.Pin = A_Pin|B_Pin|C_Pin|EN4_Pin
                          |D_Pin|E_Pin|F_Pin|G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	runTimer();

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
