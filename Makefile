#############################################

# CPU type
MCU   = atmega328p

# CPU frequency [Hz]
F_CPU = 16000000

# Fuses (refer to datasheet)
LFUSE = 0xFF
HFUSE = 0xDE
EFUSE = 0x05

# AVRDUDE settings
PROG_BAUD = 57600
PROG_DEV  = /dev/ttyUSB0
PROG_TYPE = arduino

# Build the final AVRDUDE arguments
PROG_ARGS = -c $(PROG_TYPE) -p $(MCU) -b $(PROG_BAUD) -P $(PROG_DEV)

#############################################

# Main file
BINARY = main

# Obj files to be built <- add .o for any .c files you add!
OBJS  = $(BINARY).o
OBJS += lib/usart.o
OBJS += lib/iopins.o
OBJS += lib/spi.o
OBJS += lib/adc.o

# Dirs with header files
INCL_DIRS = . lib/

# Pre-defined macros
DEFS = -DF_CPU=$(F_CPU)UL

#############################################

# C flags
CFLAGS = -std=gnu99 -mmcu=$(MCU) $(DEFS) $(INCL_DIRS:%=-I%)
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffreestanding
CFLAGS += -Wall -Wno-main -Wno-strict-prototypes -Wno-comment
CFLAGS += -g2 -Wextra -Wfatal-errors -Wno-unused-but-set-variable
CFLAGS += -ffunction-sections -fdata-sections -Os

LDFLAGS = -Wl,--gc-sections -Wl,--relax -lm

#LD_FLAGS += -Wl,-u,vfprintf -lprintf_flt -lm  ## for floating-point printf
#LD_FLAGS += -Wl,-u,vfprintf -lprintf_min      ## for smaller printf

#############################################

## Defined programs / locations
CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude

JUNK = *.o *.d *.elf *.bin *.hex *.srec *.list *.lst *.map *.dis *.disasm *.eep *.eeprom *.lss

.SUFFIXES: .elf .bin .hex .lst .map .eeprom .pre
.SECONDEXPANSION:
.SECONDARY:

.PHONY: all elf bin hex lst pre ee eeprom dis size clean flash flashe shell fuses show_fuses set_default_fuses

all: hex size

elf: $(BINARY).elf
bin: $(BINARY).bin
hex: $(BINARY).hex
lst: $(BINARY).lst
pre: $(BINARY).pre
ee: $(BINARY).eeprom
eeprom: $(BINARY).eeprom
dis: lst

# Show how big the resulting program is
size: elf
	$(AVRSIZE) -C --mcu=$(MCU) $(BINARY).elf



# --- Magic build targets ----------------

%.hex: %.elf
	$(OBJCOPY) -R .eeprom -O ihex $< $@

%.elf %.map: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(*).elf

%.pre: %.c
	$(CC) $(CFLAGS) -E $(*).c --output $@

%.eeprom: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@

%.lst: %.elf
	$(Q)$(OBJDUMP) -S $(*).elf > $(*).lst

%.o: %.c
	$(CC) $(CFLAGS) -o $(*).o -c $(*).c

%.o: %.s
	$(CC) $(CFLAGS) -o $(*).o -c $(*).s


# Clean all produced trash
clean:
	rm -f $(JUNK)
	cd lib && rm -f $(JUNK)


## === avrdude ===

flash: $(BINARY).hex
	$(AVRDUDE) $(PROG_ARGS) -U flash:w:$<

flashe: $(BINARY).eeprom
	$(AVRDUDE) $(PROG_ARGS) -U eeprom:w:$<

shell:
	$(AVRDUDE) $(PROG_ARGS) -nt

# === fuses ===

# this may not work with the arduino programmer, I haven't tried.

FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m

fuses:
	$(AVRDUDE) $(PROG_ARGS) $(FUSE_STRING)

show_fuses:
	$(AVRDUDE) $(PROG_ARGS) -nv
