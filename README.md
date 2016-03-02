# AVR C Boilerplate

This is a basic boilerplate for programming AVRs in C.

The project aims to make programming Arduinos in C fun by
providing support for basic functionality like GPIO and USART,
so you can start developing without having the datasheet open
all the time.

It is intended for **ATmega328P** (the chip in Arduinos),
but can be easily adapted to other parts.

## Requirements

Before you can start coding, you need to install a few software packages:

- `avrdude` - the flash tool
- `avr-gcc` - compiler
- `avr-libc` - libc implementation for AVR
- `avr-binutils` - utils for manipulating AVR binaries
- `make` - to run the Makefile

There's a good chance you already have `make`, the rest should be in your
distribution's repos.

If you're on Arch:

```
# pacman -S base-devel avr-gcc avr-binutils avr-libc avrdude
```

If you're on Mac, you should be able to pull the stuff with *brew*.

## Getting started

The provided `main.c` is a good starting point - it contains some simple demo code.

You can compile it with `make` and flash with `make flash`.

### Before you can flash

First, check that the `avrdude` options in the file are correct for your system - especially
the device and speed.

```ini
# AVRDUDE settings
PROG_BAUD = 57600
PROG_DEV  = /dev/ttyUSB0
PROG_TYPE = arduino

# Build the final AVRDUDE arguments
PROG_ARGS = -c $(PROG_TYPE) -p $(MCU) -b $(PROG_BAUD) -P $(PROG_DEV)
```

- Adjust `PROG_DEV` to the device your board is connected to. On Linux it's usually
  `/dev/ttyUSB0`, but it can also be `/dev/ttyACM0` or something else. On Mac, it'll be
  `/dev/cu.xxx`. On Windows it's some `COMx`.<br>
  Linux and Mac users can use `ls /dev` to see their devices. Windows users will find
  this in their Device Manager.
- You may also adjust the baudrate (`PROG_BAUD`). Some boards need `115200`.

**TIP:** You can look what the Arduino IDE is using - it's running avrdude too.

### Adding new files

- If you *add a new C file* to the project, add an entry for it's `.o` (object file,
created by the compiler before linking) to the `OBJS` list in the Makefile.
- Similarly, if you *add a new folder with header files*, add it to `INCL_DIRS`.
- In case you need `printf` (or `printf` with floats), enable the appropriate LD_FLAGS
  in the Makefile (it's well commented). Code size will - obviously - grow quite a bit.

## Notes

- The **Arduino UNO** bootloader has a quirk where `Double Speed Asynchronous Mode` for USART
  is enabled by default, so if you set your baud rate to 9600, you'd really get 19200.<br>
  We correct this in the `usart_init()` function to keep things consistent and to avoid
  confusion.<br>
  *If you wish to turn this on* however, you can do so by using `usart_set_2x(true)`.
