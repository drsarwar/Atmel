/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

struct usart_sync_descriptor USART_0;

void USART_0_PORT_init(void)
{

	gpio_set_pin_function(PA24, PINMUX_PA24C_SERCOM3_PAD2);

	gpio_set_pin_function(PA25, PINMUX_PA25C_SERCOM3_PAD3);
}

void USART_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM3);
	_gclk_enable_channel(SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC);
}

void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_sync_init(&USART_0, SERCOM3, (void *)NULL);
	USART_0_PORT_init();
}

void system_init(void)
{
	init_mcu();

	USART_0_init();
}
