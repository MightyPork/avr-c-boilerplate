#include <avr/io.h>
#include <stdint.h>

#include "calc.h"
#include "adc.h"

/** Initialize the ADC */
void adc_init(enum ADC_Prescaller presc)
{
	ADCSRA |= presc;  // 128 prescaler -> 125 kHz
	ADMUX  |= _BV(REFS0);  // Voltage reference
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

static void adc_convert(uint8_t channel)
{
	set_low_nibble(ADMUX, channel);  // Select channel to sample
	sbi(ADMUX, ADLAR);  // Align result to left
	sbi(ADCSRA, ADSC);  // Start conversion

	while (bit_is_high(ADCSRA, ADSC)); // Wait for it...
}

/** Sample analog pin with 8-bit precision */
uint8_t adc_read_byte(uint8_t channel)
{
	adc_convert(channel);
	return ADCH;  // The upper 8 bits of ADC result
}


/** Sample analog pin with 10-bit precision */
uint16_t adc_read_word(uint8_t channel)
{
	adc_convert(channel);
	return ADCW;  // The whole ADC word (10 bits)
}
