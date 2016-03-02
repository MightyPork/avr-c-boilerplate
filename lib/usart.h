#pragma once

//
// Utilities for UART communication.
//
// First, init uart with usart_init().
// Then enable interrupts you want with usart_XXX_isr_enable().
//

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdbool.h>
#include <stdint.h>

#include "calc.h"


/* USART BAUD RATE REGISTER values at 16 MHz */
enum {
	BAUD_9600 = 103,
	BAUD_14400 = 68,
	BAUD_19200 = 51,
	BAUD_28800 = 34,
	BAUD_38400 = 25,
	BAUD_57600 = 16,
	BAUD_76800 = 12,
	BAUD_115200 = 8,
	BAUD_250k = 3,
	BAUD_500k = 1,
	BAUD_1M = 0,
};

/** Init UART with a UBRR value - can use the BAUD_* constants for 16 MHz */
void usart_init(uint16_t ubrr);


/** Set Double Speed Asynchronous mode on or off */
void usart_set_2x(bool set);


/** Check if there's a byte in the RX register */
#define usart_rx_ready() bit_is_high(UCSR0A, RXC0)


/** Check if USART is ready to accept new byte to send */
#define usart_tx_ready() bit_is_high(UCSR0A, UDRE0)


// ---- Enable UART interrupts ------------

/** Enable or disable RX ISR */
#define usart_isr_rx_enable(yes) set_bit(UCSR0B, RXCIE0, (yes))


/** Enable or disable TX ISR (all data sent) */
#define usart_isr_tx_enable(yes) set_bit(UCSR0B, TXCIE0, (yes))


/** Enable or disable DRE ISR (data register empty) */
#define usart_isr_dre_enable(yes) set_bit(UCSR0B, UDRIE0, (yes))


// ---- Basic IO --------------------------

/** Send byte over USART */
void usart_tx(uint8_t data);


/** Receive one byte over USART */
uint8_t usart_rx(void);


/** Clear receive buffer */
void usart_flush_rx(void);


// ---- Strings ---------------------------

/** Send string over UART */
void usart_puts(const char* str);


/** Send progmem string `PSTR("foobar")` over UART  */
void usart_puts_P(const char* str);
