#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

#include "calc.h"
#include "iopins.h"


void set_dir_n(uint8_t pin, uint8_t d)
{
	switch(pin) {
		case 0: set_dir(0, d); return;
		case 1: set_dir(1, d); return;
		case 2: set_dir(2, d); return;
		case 3: set_dir(3, d); return;
		case 4: set_dir(4, d); return;
		case 5: set_dir(5, d); return;
		case 6: set_dir(6, d); return;
		case 7: set_dir(7, d); return;
		case 8: set_dir(8, d); return;
		case 9: set_dir(9, d); return;
		case 10: set_dir(10, d); return;
		case 11: set_dir(11, d); return;
		case 12: set_dir(12, d); return;
		case 13: set_dir(13, d); return;
		case 14: set_dir(14, d); return;
		case 15: set_dir(15, d); return;
		case 16: set_dir(16, d); return;
		case 17: set_dir(17, d); return;
		case 18: set_dir(18, d); return;
		case 19: set_dir(19, d); return;
		case 20: set_dir(20, d); return;
		case 21: set_dir(21, d); return;
	}
}


void as_input_n(uint8_t pin)
{
	switch(pin) {
		case 0: as_input(0); return;
		case 1: as_input(1); return;
		case 2: as_input(2); return;
		case 3: as_input(3); return;
		case 4: as_input(4); return;
		case 5: as_input(5); return;
		case 6: as_input(6); return;
		case 7: as_input(7); return;
		case 8: as_input(8); return;
		case 9: as_input(9); return;
		case 10: as_input(10); return;
		case 11: as_input(11); return;
		case 12: as_input(12); return;
		case 13: as_input(13); return;
		case 14: as_input(14); return;
		case 15: as_input(15); return;
		case 16: as_input(16); return;
		case 17: as_input(17); return;
		case 18: as_input(18); return;
		case 19: as_input(19); return;
		case 20: as_input(20); return;
		case 21: as_input(21); return;
	}
}


void as_input_pu_n(uint8_t pin)
{
	switch(pin) {
		case 0: as_input_pu(0); return;
		case 1: as_input_pu(1); return;
		case 2: as_input_pu(2); return;
		case 3: as_input_pu(3); return;
		case 4: as_input_pu(4); return;
		case 5: as_input_pu(5); return;
		case 6: as_input_pu(6); return;
		case 7: as_input_pu(7); return;
		case 8: as_input_pu(8); return;
		case 9: as_input_pu(9); return;
		case 10: as_input_pu(10); return;
		case 11: as_input_pu(11); return;
		case 12: as_input_pu(12); return;
		case 13: as_input_pu(13); return;
		case 14: as_input_pu(14); return;
		case 15: as_input_pu(15); return;
		case 16: as_input_pu(16); return;
		case 17: as_input_pu(17); return;
		case 18: as_input_pu(18); return;
		case 19: as_input_pu(19); return;
		case 20: as_input_pu(20); return;
		case 21: as_input_pu(21); return;
	}
}


void as_output_n(uint8_t pin)
{
	switch(pin) {
		case 0: as_output(0); return;
		case 1: as_output(1); return;
		case 2: as_output(2); return;
		case 3: as_output(3); return;
		case 4: as_output(4); return;
		case 5: as_output(5); return;
		case 6: as_output(6); return;
		case 7: as_output(7); return;
		case 8: as_output(8); return;
		case 9: as_output(9); return;
		case 10: as_output(10); return;
		case 11: as_output(11); return;
		case 12: as_output(12); return;
		case 13: as_output(13); return;
		case 14: as_output(14); return;
		case 15: as_output(15); return;
		case 16: as_output(16); return;
		case 17: as_output(17); return;
		case 18: as_output(18); return;
		case 19: as_output(19); return;
		case 20: as_output(20); return;
		case 21: as_output(21); return;
	}
}

void pin_set_n(uint8_t pin, uint8_t v)
{
	switch(pin) {
		case 0: pin_set(0, v); return;
		case 1: pin_set(1, v); return;
		case 2: pin_set(2, v); return;
		case 3: pin_set(3, v); return;
		case 4: pin_set(4, v); return;
		case 5: pin_set(5, v); return;
		case 6: pin_set(6, v); return;
		case 7: pin_set(7, v); return;
		case 8: pin_set(8, v); return;
		case 9: pin_set(9, v); return;
		case 10: pin_set(10, v); return;
		case 11: pin_set(11, v); return;
		case 12: pin_set(12, v); return;
		case 13: pin_set(13, v); return;
		case 14: pin_set(14, v); return;
		case 15: pin_set(15, v); return;
		case 16: pin_set(16, v); return;
		case 17: pin_set(17, v); return;
		case 18: pin_set(18, v); return;
		case 19: pin_set(19, v); return;
		case 20: pin_set(20, v); return;
		case 21: pin_set(21, v); return;
	}
}

void pin_down_n(uint8_t pin)
{
	switch(pin) {
		case 0: pin_down(0); return;
		case 1: pin_down(1); return;
		case 2: pin_down(2); return;
		case 3: pin_down(3); return;
		case 4: pin_down(4); return;
		case 5: pin_down(5); return;
		case 6: pin_down(6); return;
		case 7: pin_down(7); return;
		case 8: pin_down(8); return;
		case 9: pin_down(9); return;
		case 10: pin_down(10); return;
		case 11: pin_down(11); return;
		case 12: pin_down(12); return;
		case 13: pin_down(13); return;
		case 14: pin_down(14); return;
		case 15: pin_down(15); return;
		case 16: pin_down(16); return;
		case 17: pin_down(17); return;
		case 18: pin_down(18); return;
		case 19: pin_down(19); return;
		case 20: pin_down(20); return;
		case 21: pin_down(21); return;
	}
}

void pin_up_n(uint8_t pin)
{
	switch(pin) {
		case 0: pin_up(0); return;
		case 1: pin_up(1); return;
		case 2: pin_up(2); return;
		case 3: pin_up(3); return;
		case 4: pin_up(4); return;
		case 5: pin_up(5); return;
		case 6: pin_up(6); return;
		case 7: pin_up(7); return;
		case 8: pin_up(8); return;
		case 9: pin_up(9); return;
		case 10: pin_up(10); return;
		case 11: pin_up(11); return;
		case 12: pin_up(12); return;
		case 13: pin_up(13); return;
		case 14: pin_up(14); return;
		case 15: pin_up(15); return;
		case 16: pin_up(16); return;
		case 17: pin_up(17); return;
		case 18: pin_up(18); return;
		case 19: pin_up(19); return;
		case 20: pin_up(20); return;
		case 21: pin_up(21); return;
	}
}


void pin_toggle_n(uint8_t pin)
{
	switch(pin) {
		case 0: pin_toggle(0); return;
		case 1: pin_toggle(1); return;
		case 2: pin_toggle(2); return;
		case 3: pin_toggle(3); return;
		case 4: pin_toggle(4); return;
		case 5: pin_toggle(5); return;
		case 6: pin_toggle(6); return;
		case 7: pin_toggle(7); return;
		case 8: pin_toggle(8); return;
		case 9: pin_toggle(9); return;
		case 10: pin_toggle(10); return;
		case 11: pin_toggle(11); return;
		case 12: pin_toggle(12); return;
		case 13: pin_toggle(13); return;
		case 14: pin_toggle(14); return;
		case 15: pin_toggle(15); return;
		case 16: pin_toggle(16); return;
		case 17: pin_toggle(17); return;
		case 18: pin_toggle(18); return;
		case 19: pin_toggle(19); return;
		case 20: pin_toggle(20); return;
		case 21: pin_toggle(21); return;
	}
}


bool pin_read_n(uint8_t pin)
{
	switch(pin) {
		case 0: return pin_read(0);
		case 1: return pin_read(1);
		case 2: return pin_read(2);
		case 3: return pin_read(3);
		case 4: return pin_read(4);
		case 5: return pin_read(5);
		case 6: return pin_read(6);
		case 7: return pin_read(7);
		case 8: return pin_read(8);
		case 9: return pin_read(9);
		case 10: return pin_read(10);
		case 11: return pin_read(11);
		case 12: return pin_read(12);
		case 13: return pin_read(13);
		case 14: return pin_read(14);
		case 15: return pin_read(15);
		case 16: return pin_read(16);
		case 17: return pin_read(17);
		case 18: return pin_read(18);
		case 19: return pin_read(19);
		case 20: return pin_read(20);
		case 21: return pin_read(21);
	}
	return false;
}


bool pin_is_low_n(uint8_t pin)
{
	return !pin_read_n(pin);
}


bool pin_is_high_n(uint8_t pin)
{
	return pin_read_n(pin);
}
