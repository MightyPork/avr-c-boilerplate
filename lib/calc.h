#pragma once

//
// Bit and byte manipulation utilities
//

#include <stdint.h>


// --- Increment in range ---
// when overflown, wraps within range. Lower bound < upper bound.
// ..., upper bound excluded
#define inc_wrap(var, min, max) \
    do {                             \
        if ((var) >= ((max) - 1)) {  \
            (var) = (min);           \
        } else {                     \
            (var)++;                 \
        }                            \
    } while(0)

// ..., upper bound included
#define inc_wrapi(var, min, max) inc_wrap((var), (min), (max) + 1)


// --- Decrement in range ---
// when underflown, wraps within range. Lower bound < upper bound.
// ..., upper bound excluded
#define dec_wrap(var, min, max) \
    do {                             \
        if ((var) <= (min)) {        \
            (var) = (max) - 1;       \
        } else {                     \
            (var)--;                 \
        }                            \
    } while(0)


// ..., upper bound included
#define dec_wrapi(var, min, max) dec_wrap((var), (min), (max) + 1)


// --- Bit manipulation --

// Set bit
#define sbi(reg, n)  do { (reg) |=  (1 << (uint8_t)(n)); } while(0)

// Clear bit
#define cbi(reg, n)  do { (reg) &= ~(1 << (uint8_t)(n)); } while(0)

// Get n-th bit
#define get_bit(reg, n) (((reg) >> (uint8_t)(n)) & 1)


// Test n-th bit (Can't use bit_is_set, as it's defined in sfr_def.h)
#define bit_is_high(reg, n) get_bit((reg), (n))
#define bit_is_low(reg, n)  (!get_bit((reg), (n)))

// Write value to n-th bit
#define set_bit(reg, n, val) \
    do {                                          \
        (reg) = ((reg) & ~(1 << (uint8_t)(n)))    \
              | (((val) & 1) << (uint8_t)(n));    \
    } while(0)

// Invert n-th bit
#define toggle_bit(reg, n) do { (reg) ^= (1 << (uint8_t)(n)); } while(0)


// --- Bit manipulation with pointer to variable ---

// Set n-th bit in pointee
#define sbi_p(reg_p, n) do { (*(reg_p)) |=  (1 << (uint8_t)(n)); } while(0)
// Clear n-th bit in pointee
#define cbi_p(reg_p, n) do { (*(reg_p)) &= ~(1 << (uint8_t)(n)); } while(0)

// Get n-th bit in pointee
#define get_bit_p(reg_p, n) ((*(reg_p) >> (uint8_t)(n)) & 1)

// Test n-th bit in pointee (Can't use bit_is_set, as it's redefined in sfr_def.h)
#define bit_is_high_p(reg_p, bit) get_bit_p(reg_p, bit)
#define bit_is_low_p(reg_p, bit) (!get_bit_p(reg_p, bit))


// Write value to a bit in pointee
#define set_bit_p(reg_p, n, value) \
    do {                                             \
        *(reg_p) = (*(reg_p) & ~(1 << (uint8_t)(n))) \
                 | (((value) & 1) << (uint8_t)(n));  \
    } while(0)


#define toggle_bit_p(reg_p, n) do { *(reg_p) ^= (1 << (uint8_t)(n)); } while(0)


// --- Nibble manipulation ---

// Replace nibble in a byte
#define set_low_nibble(reg, value) \
    do {                                    \
        (reg) = ((reg) & 0xF0)              \
              | ((uint8_t)(value) & 0xF);   \
    } while(0)


#define set_high_nibble(reg, value) \
    do {                                            \
        (reg) = ((reg) & 0x0F)                      \
              | (((uint8_t)(value) & 0xF) << 4);    \
    } while(0)


#define set_low_nibble_p(reg_p, value) \
    do {                                            \
        *(reg_p) = (*(reg_p) & 0xF0)                \
                 | ((uint8_t)(value) & 0xF);        \
    } while(0)


#define set_high_nibble_p(reg_p, value) \
    do {                                            \
        *(reg_p) = (*(reg_p) & 0x0F)                \
                 | (((uint8_t)(value) & 0xF) << 4); \
    } while(0)


#define low_nibble(x)   ((uint8_t)(x) & 0x0F)
#define high_nibble(x) (((uint8_t)(x) & 0xF0) >> 4)


// --- Range tests ---

// Test if X is within low..high, regardless of bounds order
#define in_range(x, low, high) \
    ((low) < (high) ? ((x) >= (low) && (x) < (high))  \
                    : ((x) >= (high) && (x) < (low)))  \


// ..., include greater bound
#define in_rangei(x, low, high) \
    ((low) < (high) ? ((x) >= (low) && (x) <= (high))  \
                    : ((x) >= (high) && (x) <= (low)))  \


// Test if X in low..high, wrap around ends if needed.
#define in_range_wrap(x, low, high) \
    (((low) < (high)) ? ((x) >= (low) && (x) < (high))  \
                      : ((x) >= (low) || (x) < (high)))


// ..., include upper bound
#define in_range_wrapi(x, low, high) \
    (((low) <= (high)) ? ((x) >= (low) && (x) <= (high))  \
                       : ((x) >= (low) || (x) <= (high)))
