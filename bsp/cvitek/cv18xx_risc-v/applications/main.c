/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023/06/25     flyingcys    first version
 */

#include <rtthread.h>
#include <stdio.h>
#include <drivers/dev_pin.h>

#if defined(BOARD_TYPE_MILKV_DUO256M)
#define LED_PIN     "E02" /* Onboard LED pins */
#elif defined(BOARD_TYPE_MILKV_DUO)
#define LED_PIN     "C24" /* Onboard LED pins */
#elif defined(BOARD_TYPE_MILKV_DUOS)
#define LED_PIN     "A29" /* Onboard LED pins */
#endif

int main(void)
{
    rt_kprintf("Hello RISC-V/C906B !\n");

    /* LED pin: C24 */
    rt_uint16_t led = rt_pin_get(LED_PIN);

    /* set LED pin mode to output */
    rt_pin_mode(led, PIN_MODE_OUTPUT);

    while (1)
    {
        rt_pin_write(led, PIN_HIGH);

        rt_thread_mdelay(500);

        rt_pin_write(led, PIN_LOW);

        rt_thread_mdelay(500);
    }

    return 0;
}
