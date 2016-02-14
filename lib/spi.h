#pragma once

#include <avr/io.h>
#include <stdint.h>

#include "calc.h"
#include "iopins.h"

#define PIN_MISO 12
#define PIN_MOSI 11
#define PIN_SCK 13
#define PIN_SS 10

/** Bit order */
enum SPI_order {
	SPI_LSB_FIRST = 0,
	SPI_MSB_FIRST = 1
};

/** Clock polarity */
enum SPI_cpol {
	CPOL_0 = 0,
	CPOL_1 = 1
};

/** Clock phase */
enum SPI_cpha {
	CPHA_0 = 0,
	CPHA_1 = 1
};

/** Clock prescaller <SPI2X><SPR1><SPR0> */
enum SPI_clk_div {
	SPI_DIV_2   = 0b100, // 2x (master only, can't receive at this speed)
	SPI_DIV_4   = 0b000,
	SPI_DIV_8   = 0b101, // 2x
	SPI_DIV_16  = 0b001,
	SPI_DIV_32  = 0b110, // 2x
	SPI_DIV_64  = 0b010,
	SPI_DIV_128 = 0b011
};


/** Set SS to active state (LOW) */
#define spi_ss_enable()  pin_down(PIN_SS)


/** Set SS to disabled state (HIGH) */
#define spi_ss_disable() pin_up(PIN_SS)


/** Enable SPI ISR */
#define spi_isr_enable(yes) set_bit(SPCR, SPIE, yes)


/** Init SPI (for SD card communication) */
void spi_init_master(enum SPI_order order, enum SPI_cpol cpol, enum SPI_cpha cpha, enum SPI_clk_div clkdiv);


/** Init SPI (for SD card communication) */
void spi_init_slave(enum SPI_order order, enum SPI_cpol cpol, enum SPI_cpha cpha);


/** Write a byte to SPI. Returns received byte. */
uint8_t spi_send(uint8_t byte);


/** Receive (as slave). Blocking. */
uint8_t spi_receive(uint8_t reply);
