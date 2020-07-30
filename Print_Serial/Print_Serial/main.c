#include <atmel_start.h>

struct io_descriptor *uart_edbg_io; //making the io struct global

void UART_EDBG_init(void)
{
	struct io_descriptor *uart_edbg_io;
	usart_sync_get_io_descriptor(&USART_0, &uart_edbg_io);
	usart_sync_enable(&USART_0);

	//io_write(uart_edbg_io, (uint8_t *)"Hello World!\n", 14);
	//io_write(uart_edbg_io, (uint8_t *)"Hello WORLS!\n", 14);
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	struct io_descriptor *uart_edbg_io;
	usart_sync_get_io_descriptor(&USART_0, &uart_edbg_io);
	usart_sync_enable(&USART_0);
	
	/* Replace with your application code */
	while (1) {
		io_write(uart_edbg_io, (uint8_t *)"Hello WORLS!\n", 14);
		//UART_EDBG_init();
	}
}
