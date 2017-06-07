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

/** Sample analog pin with 8-bit precision */
uint8_t adc_read_byte(uint8_t channel);

/** Sample analog pin with 10-bit precision */
uint16_t adc_read_word(uint8_t channel);
