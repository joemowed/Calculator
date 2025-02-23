/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f7xx_hal.h"

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
#define ENABLE_13V_Pin GPIO_PIN_2
#define ENABLE_13V_GPIO_Port GPIOE
#define KEY_TEST_Pin GPIO_PIN_0
#define KEY_TEST_GPIO_Port GPIOA
#define CS_DISP_R_Pin GPIO_PIN_1
#define CS_DISP_R_GPIO_Port GPIOA
#define RST_DISP_R_Pin GPIO_PIN_2
#define RST_DISP_R_GPIO_Port GPIOA
#define CS_DISP_L_Pin GPIO_PIN_3
#define CS_DISP_L_GPIO_Port GPIOA
#define RST_DISP_L_Pin GPIO_PIN_4
#define RST_DISP_L_GPIO_Port GPIOA
#define KEY_F4_Pin GPIO_PIN_4
#define KEY_F4_GPIO_Port GPIOC
#define KEY_F3_Pin GPIO_PIN_5
#define KEY_F3_GPIO_Port GPIOC
#define KEY_SUB_Pin GPIO_PIN_0
#define KEY_SUB_GPIO_Port GPIOB
#define KEY_ADD_Pin GPIO_PIN_1
#define KEY_ADD_GPIO_Port GPIOB
#define KEY_RTN_Pin GPIO_PIN_2
#define KEY_RTN_GPIO_Port GPIOB
#define KEY_MUL_Pin GPIO_PIN_7
#define KEY_MUL_GPIO_Port GPIOE
#define KEY_9_Pin GPIO_PIN_8
#define KEY_9_GPIO_Port GPIOE
#define KEY_6_Pin GPIO_PIN_9
#define KEY_6_GPIO_Port GPIOE
#define KEY_3_Pin GPIO_PIN_10
#define KEY_3_GPIO_Port GPIOE
#define KEY_DEL_Pin GPIO_PIN_11
#define KEY_DEL_GPIO_Port GPIOE
#define KEY_2_Pin GPIO_PIN_12
#define KEY_2_GPIO_Port GPIOE
#define KEY_5_Pin GPIO_PIN_13
#define KEY_5_GPIO_Port GPIOE
#define KEY_8_Pin GPIO_PIN_14
#define KEY_8_GPIO_Port GPIOE
#define KEY_DIV_Pin GPIO_PIN_15
#define KEY_DIV_GPIO_Port GPIOE
#define KEY_0_Pin GPIO_PIN_10
#define KEY_0_GPIO_Port GPIOB
#define KEY_1_Pin GPIO_PIN_11
#define KEY_1_GPIO_Port GPIOB
#define KEY_4_Pin GPIO_PIN_12
#define KEY_4_GPIO_Port GPIOB
#define KEY_7_Pin GPIO_PIN_13
#define KEY_7_GPIO_Port GPIOB
#define KEY_NUM_Pin GPIO_PIN_14
#define KEY_NUM_GPIO_Port GPIOB
#define KEY_F2_Pin GPIO_PIN_15
#define KEY_F2_GPIO_Port GPIOB
#define KEY_F1_Pin GPIO_PIN_8
#define KEY_F1_GPIO_Port GPIOD
#define VBUS_DETECT_Pin GPIO_PIN_10
#define VBUS_DETECT_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
