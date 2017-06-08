#pragma once

//
// Utilities for build-in A/D converter
//

#include <stdint.h>

enum ADC_Prescaller {
	ADC_PRESC_2 = 1,
	ADC_PRESC_4 = 2,
	ADC_PRESC_8 = 3,
	ADC_PRESC_16 = 4,
	ADC_PRESC_32 = 5,
	ADC_PRESC_64 = 6,
	ADC_PRESC_128 = 7,
};

/** Initialize the ADC and enable it */
void adc_init(enum ADC_Prescaller presc);

/** Disable ADC (for power saving) */
void adc_disable(void);

/** Enable (already initialized) ADC */
void adc_enable(void);

/** Start a new conversion */
void adc_start_conversion(uint8_t channel);

/** Check if ADC is done converting */
bool adc_ready(void);

/** Read the result of last conversion with 8bit precision */
uint8_t adc_read_8bit(void);

/** Read the result of last conversion with 10bit precision */
uint16_t adc_read_10bit(void);

/** Sample analog pin with 8-bit precision. Blocking! */
uint8_t adc_convert_8bit(uint8_t channel);

/** Sample analog pin with 10-bit precision. Blocking! */
uint16_t adc_convert_10bit(uint8_t channel);
