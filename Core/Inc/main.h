/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TL_Pin GPIO_PIN_1
#define TL_GPIO_Port GPIOA
#define ML_Pin GPIO_PIN_4
#define ML_GPIO_Port GPIOA
#define BL_Pin GPIO_PIN_5
#define BL_GPIO_Port GPIOA
#define MC_Pin GPIO_PIN_6
#define MC_GPIO_Port GPIOA
#define BR_Pin GPIO_PIN_7
#define BR_GPIO_Port GPIOA
#define MR_Pin GPIO_PIN_8
#define MR_GPIO_Port GPIOA
#define TR_Pin GPIO_PIN_9
#define TR_GPIO_Port GPIOA
#define Roll_Pin GPIO_PIN_10
#define Roll_GPIO_Port GPIOA
#define Roll_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
