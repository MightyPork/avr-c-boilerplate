cmake_minimum_required(VERSION 3.7)
project(firmware)

# Fake CMake config for CLion

set(CMAKE_CXX_STANDARD GNU99)

set(SOURCE_FILES
        main.c
        lib/calc.h
        lib/iopins.c
        lib/iopins.h
        lib/nsdelay.h
        lib/spi.c
        lib/spi.h
        lib/adc.c
        lib/adc.h
        lib/usart.c
        lib/usart.h
        )

include_directories(lib
        /usr/avr/include/)

add_definitions(-D__AVR_ATmega328P__)

add_executable(firmware ${SOURCE_FILES})
