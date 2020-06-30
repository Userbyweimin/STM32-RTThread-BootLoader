/*
 * @Description: 
 * @Version: 1.0
 * @Autor: JunQi Liu
 * @Date: 2020-06-30 21:34:01
 * @LastEditors: JunQi Liu
 * @LastEditTime: 2020-06-30 21:37:58
 * @FilePath: \STM32-RTThread-BootLoader\applications\function.c
 */ 
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "function.h"
#define DBG_ENABLE
#define DBG_SECTION_NAME                    "function"

#ifdef RT_MAIN_DEBUG
#define DBG_LEVEL                           DBG_LOG
#else
#define DBG_LEVEL                           DBG_INFO
#endif

#define DBG_COLOR
#include <rtdbg.h>

/**
 * @description: 获取时间戳
 * @param {type} 
 * @return: 
 * @note: 
 * @author: JunQi Liu
 */
long iot_get_timestamp(void)
{
    time_t now;
    now = time(RT_NULL) - 8*60*60;
    return now;
}
