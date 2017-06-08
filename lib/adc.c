#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

#include "calc.h"
#include "adc.h"

/** Initialize the ADC */
void adc_init(enum ADC_Prescaller presc)
{
	ADCSRA |= presc;  // 128 prescaler -> 125 kHz
	ADMUX |= _BV(REFS0);  // Voltage reference
	sbi(ADCSRA, ADEN);  // Enable ADC
}

/** Disable ADC */
void adc_disable(void)
{
	cbi(ADCSRA, ADEN);
}

/** Enable ADC */
void adc_enable(void)
{
	sbi(ADCSRA, ADEN);
}

/** Start a new conversion */
void adc_start_conversion(uint8_t channel)
{
	set_low_nibble(ADMUX, channel);  // Select channel to sample
	cbi(ADMUX, ADLAR);  // Align result to right
	sbi(ADCSRA, ADSC);  // Start conversion
}

/** Check if ADC is done converting */
bool adc_ready(void)
{
	return bit_is_low(ADCSRA, ADSC);
}

/** Read the result of last conversion with 8bit precision */
uint8_t adc_read_8bit()
{
	uint8_t low = ADCL;
	uint8_t high = ADCH;
	return low >> 2 | high << 6;
}

/** Read the result of last conversion with 10bit precision */
uint16_t adc_read_10bit()
{
	uint8_t low = ADCL;
	uint8_t high = ADCH;
	return ((uint16_t) high << 8) | low;
}

/** Start ADC conversion and wait for the result */
static void adc_convert(uint8_t channel)
{
	adc_start_conversion(channel);
	while (!adc_ready()); // Wait for it...
}

/** Sample analog pin with 8-bit precision */
uint8_t adc_convert_8bit(uint8_t channel)
{
	adc_convert(channel);
	return adc_read_8bit();
}

/** Sample analog pin with 10-bit precision */
uint16_t adc_convert_10bit(uint8_t channel)
{
	adc_convert(channel);
	return adc_read_10bit();
}
