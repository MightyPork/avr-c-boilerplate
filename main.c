#include <avr/io.h>          // register definitions
#include <avr/pgmspace.h>    // storing data in program memory
#include <avr/interrupt.h>   // interrupt vectors
#include <util/delay.h>      // delay functions

#include <stdint.h>          // C header for int types like uint8_t
#include <stdbool.h>         // C header for the bool type

// Include stuff from the library
#include "lib/iopins.h"
#include "lib/usart.h"


// Pins
#define LED 13


// UART receive handler
ISR(USART_RX_vect)
{
	// "ECHO" function:
	uint8_t b = usart_rx();
	usart_tx(b); // send back
}


void main()
{
	usart_init(BAUD_115200);
	usart_isr_rx_enable(true); // enable RX interrupt handler

	// configure pins
	as_output(LED);

	// globally enable interrupts (for the USART_RX handler)
	sei();

	while (1) {
		usart_puts("Hello World!\r\n");

		pin_toggle(13); // blink the LED

		_delay_ms(500);
	}
}
