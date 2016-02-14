#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

#include "iopins.h"
#include "spi.h"


/** Init SPI (for SD card communication) */
void spi_init_master(enum SPI_order order, enum SPI_cpol cpol, enum SPI_cpha cpha, enum SPI_clk_div clkdiv)
{
	as_output(PIN_SS); // SS output - we control slave
	as_output(PIN_MOSI); // MOSI output - we talk to slave
	as_output(PIN_SCK); // SCK output - we're generating clock
	// MISO is configured automatically as input

	SPCR = 0;
	SPCR |= (1 << MSTR);
	SPCR |= (order << DORD);
	SPCR |= (cpol << CPOL);
	SPCR |= (cpha << CPHA);

	// speed
	SPCR |= (clkdiv & 0b11);
	SPSR = (bool)(clkdiv & 0b100); // write SPI2X flag

	// enable SPI
	SPCR |= (1 << SPE);
}


/** Init SPI (for SD card communication) */
void spi_init_slave(enum SPI_order order, enum SPI_cpol cpol, enum SPI_cpha cpha)
{
	as_output(PIN_MISO); // we're listening to master
	// MOSI, SS, SCK are configured automatically

	SPCR = 0;
	SPCR |= (order << DORD);
	SPCR |= (cpol << CPOL);
	SPCR |= (cpha << CPHA);

	// enable SPI
	SPCR |= (1 << SPE);
}

/** Write a byte to SPI. Returns received byte. */
uint8_t spi_send(uint8_t byte)
{
	SPDR = byte;
	while (bit_is_low(SPSR, SPIF));

	return SPDR;
}

/** Receive (as slave). Blocking. */
uint8_t spi_receive(uint8_t reply)
{
	SPDR = reply;
	while (bit_is_low(SPSR, SPIF));
	return SPDR;
}
