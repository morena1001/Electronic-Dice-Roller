/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f3xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f3xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
char msg[10];

bool toggle = false;

uint8_t generated_number = 0;
uint8_t previous_generated_number = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim6;
/* USER CODE BEGIN EV */
extern TIM_HandleTypeDef htim2;
extern UART_HandleTypeDef huart2;
static void NumberOne(void);
static void NumberTwo(void);
static void NumberThree(void);
static void NumberFour(void);
static void NumberFive(void);
static void NumberSix(void);
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F3xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f3xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(Roll_Pin);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global interrupt, DAC interrupts.
  */
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */
	if (!HAL_GPIO_ReadPin(Roll_GPIO_Port, Roll_Pin)) {
		if (!toggle) {
			toggle = true;

			srand(__HAL_TIM_GET_COUNTER(&htim2));
			generated_number = (rand() % 6) + 1;

			while (generated_number == previous_generated_number) {
				generated_number = (rand() % 6) + 1;
			}

			sprintf(msg, "%d\r\n", generated_number);
			HAL_UART_Transmit(&huart2, (uint8_t*) msg, 3, 100);
			previous_generated_number = generated_number;

			switch(generated_number) {
			case 1:
				NumberOne();
				break;
			case 2:
				NumberTwo();
				break;
			case 3:
				NumberThree();
				break;
			case 4:
				NumberFour();
				break;
			case 5:
				NumberFive();
				break;
			case 6:
				NumberSix();
				break;
			}
		}
	} else {
		toggle = false;
	}
  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}

/* USER CODE BEGIN 1 */
static void NumberOne(void) {
	HAL_GPIO_WritePin(GPIOA, TL_Pin | ML_Pin | BL_Pin | TR_Pin | MR_Pin | BR_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MC_Pin, GPIO_PIN_SET);
}

static void NumberTwo(void) {
	HAL_GPIO_WritePin(GPIOA, TL_Pin | ML_Pin | MC_Pin | MR_Pin | BR_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, BL_Pin | TR_Pin, GPIO_PIN_SET);
}

static void NumberThree(void) {
	HAL_GPIO_WritePin(GPIOA, TL_Pin | ML_Pin | MR_Pin | BR_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, BL_Pin | MC_Pin | TR_Pin, GPIO_PIN_SET);
}

static void NumberFour(void) {
	HAL_GPIO_WritePin(GPIOA, ML_Pin | MC_Pin | MR_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, TL_Pin | BL_Pin | TR_Pin | BR_Pin, GPIO_PIN_SET);
}

static void NumberFive(void) {
	HAL_GPIO_WritePin(GPIOA, ML_Pin | MR_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, TL_Pin | BL_Pin | MC_Pin | TR_Pin | BR_Pin, GPIO_PIN_SET);
}

static void NumberSix(void) {
	HAL_GPIO_WritePin(GPIOA, MC_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, TL_Pin | ML_Pin | BL_Pin | TR_Pin | MR_Pin | BR_Pin, GPIO_PIN_SET);
}

//	for (int i = 0; i < 16383; i++);
//
//	if (HAL_GPIO_ReadPin(Roll_GPIO_Port, Roll_Pin)) {
//		srand(__HAL_TIM_GET_COUNTER(&htim2));
//		generated_number = (rand() % 6) + 1;
//
//		while (generated_number == previous_generated_number) {
//			generated_number = (rand() % 6) + 1;
//		}
//
//		sprintf(msg, "%d\r\n", generated_number);
//		HAL_UART_Transmit(&huart2, (uint8_t*) msg, 3, 100);
//		previous_generated_number = generated_number;
//
//		switch(generated_number) {
//		case 1:
//			NumberOne();
//			break;
//		case 2:
//			NumberTwo();
//			break;
//		case 3:
//			NumberThree();
//			break;
//		case 4:
//			NumberFour();
//			break;
//		case 5:
//			NumberFive();
//			break;
//		case 6:
//			NumberSix();
//			break;
//		}
//	}

//	 if (HAL_GPIO_ReadPin(Roll_GPIO_Port, Roll_Pin)) {
//		  for (int i = 0; i < 65535; i++);
//		  if (!toggle && !firstTime) {
//			  toggle = 1;
//			  srand(__HAL_TIM_GET_COUNTER(&htim2));
//			  int generatedNumber = (rand() % 6) + 1;
//			  while (generatedNumber == previousGeneratedNumber) {
//				  generatedNumber = (rand() % 6) + 1;
//			  }
//			  sprintf(msg, "%d\r\n", generatedNumber);
//			  HAL_UART_Transmit(&huart2, (uint8_t*) msg, 10, 100);
//			  previousGeneratedNumber = generatedNumber;
//
//			  switch(generatedNumber) {
//			  case 1:
//				  NumberOne();
//				  break;
//			  case 2:
//				  NumberTwo();
//				  break;
//			  case 3:
//				  NumberThree();
//				  break;
//			  case 4:
//				  NumberFour();
//				  break;
//			  case 5:
//				  NumberFive();
//				  break;
//			  case 6:
//				  NumberSix();
//				  break;
//			  }
//		  }
//	  } else {
//		  toggle = 0;
//		  firstTime = 0;
//	  }
/* USER CODE END 1 */
