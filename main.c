#include <avr/io.h>          // register definitions
#include <avr/pgmspace.h>    // storing data in program memory
#include <avr/interrupt.h>   // interrupt vectors
#include <util/delay.h>      // delay functions

#include <stdint.h>          // C header for int types like uint8_t
#include <stdbool.h>         // C header for the bool type

// Include stuff from the library
#include "lib/iopins.h"
#include "lib/usart.h"

void main() __attribute__ ((noreturn));

// Pins
#define LED 13


// UART receive handler
ISR(USART_RX_vect)
{
	uint8_t b = usart_rx();
	usart_tx(b); // send back
}


void main()
{
	usart_init(8); // set usart @ 115200 (8 is a UBRR value)
	usart_rx_isr_enable(true); // enable RX interrupt handler

	// configure pins
	as_output(LED);

	// globally enable interrupts (for the USART_RX handler)
	sei();

	while (1) {
		// This string is in the program memory
		// PSTR is a special macro that puts it there.
		// That means it does not waste ram space, but
		// needs special treatment when being read.
		// (avr-gcc is a bit dumb in this)
		usart_puts_P( PSTR("Hello World\r\n") ); // Print a string to USART

		// This one is copied to RAM before being printed = bad.
		usart_puts("Wastin' RAM!\r\n");

		pin_toggle(13);

		_delay_ms(500);
	}
}
