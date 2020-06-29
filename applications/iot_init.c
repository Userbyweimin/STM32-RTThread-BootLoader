/*
 * @Description: 
 * @Version: 1.0
 * @Autor: JunQi Liu
 * @Date: 2020-06-29 22:58:00
 * @LastEditors: JunQi Liu
 * @LastEditTime: 2020-06-30 04:04:25
 * @FilePath: \STM32-RTThread-BootLoader\applications\iot_init.c
 */ 
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "iot_init.h"
#include "spi_flash.h"
#include "spi_flash_sfud.h"
#include "drv_spi.h"

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
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}


#include <board.h>

#define RESET_IO GET_PIN(C, 0)

void phy_reset(void)
{
    rt_pin_write(RESET_IO, PIN_LOW);
    rt_thread_mdelay(50);
    rt_pin_write(RESET_IO, PIN_HIGH);
}

int phy_init(void)
{
    rt_pin_mode(RESET_IO, PIN_MODE_OUTPUT);
    rt_pin_write(RESET_IO, PIN_HIGH);
    return RT_EOK;
}
INIT_BOARD_EXPORT(phy_init);

/**
 * @description: 添加 spi flash 的初始化
 * @param {type} 
 * @return: 
 * @note: CS 引脚为 PB14
 * @author: JunQi Liu
 */
#if defined(BSP_USING_SPI_FLASH)
static int rt_hw_spi_flash_init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
    rt_hw_spi_device_attach("spi1", "spi10", GPIOB, GPIO_PIN_14);

    if (RT_NULL == rt_sfud_flash_probe("W25Q128", "spi10"))
    {
        return -RT_ERROR;
    };

    return RT_EOK;
}
INIT_COMPONENT_EXPORT(rt_hw_spi_flash_init);
#endif