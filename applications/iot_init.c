/*
 * @Description: 
 * @Version: 1.0
 * @Autor: JunQi Liu
 * @Date: 2020-06-29 22:58:00
 * @LastEditors: JunQi Liu
 * @LastEditTime: 2020-06-29 23:45:52
 * @FilePath: \STM32-RTThread-BootLoader\applications\iot_init.c
 */ 
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "iot_init.h"

static void MX_GPIO_Init(void);
/**
 * @description: 硬件初始化
 * @param {type} 
 * @return: 
 * @note: 
 * @author: JunQi Liu
 */
void iot_init(void)
{
    MX_GPIO_Init();
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
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin : PA8 */
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

