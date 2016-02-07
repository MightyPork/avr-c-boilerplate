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

The provided main.c is a good starting point - it contains some simple demo code.

You can compile it with `make` and flash with `make flash`.

If you *add a new C file* to the project, add an entry for it's `.o` (object file,
created by the compiler before linking) to the `OBJS` list in the Makefile.

Similarly, if you *add a new folder with header files*, add it to `INCL_DIRS`.

In case you need `printf` (or `printf` with floats), enable the appropriate LD_FLAGS in the Makefile (it's well
commented). Code size will - obviously - grow quite a bit.
