TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
	lib \
	/usr/avr/include

DEFINES += __AVR_ATmega328P__ F_CPU=16000000UL

DISTFILES += \
	style.astylerc \
	Makefile \
	README.md \
	LICENSE

HEADERS += \
	lib/calc.h \
	lib/iopins.h \
	lib/usart.h \
	lib/nsdelay.h \
	lib/spi.h

SOURCES += \
	lib/iopins.c \
	main.c \
	lib/usart.c \
	lib/spi.c

# === Flags for the Clang code model===
#
#-Weverything
#-Wno-c++98-compat
#-Wno-c++98-compat-pedantic
#-Wno-unused-macros
#-Wno-newline-eof
#-Wno-exit-time-destructors
#-Wno-global-constructors
#-Wno-gnu-zero-variadic-macro-arguments
#-Wno-documentation
#-Wno-missing-prototypes
#-std=gnu99
#-Wno-gnu
#-Wno-format-nonliteral
#-Wno-conversion
#-Wno-pointer-sign
#-Wno-unknown-attributes
#-Wno-main-return-type
#-Wno-missing-noreturn
