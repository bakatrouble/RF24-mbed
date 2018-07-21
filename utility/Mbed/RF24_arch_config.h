
#ifndef __ARCH_CONFIG_H__
#define __ARCH_CONFIG_H__

#include "mbed.h"
#include "spi.h"
#include "millis.h"

#define _BV(x) (1<<(x))
#define _SPI spi

#undef SERIAL_DEBUG
#ifdef SERIAL_DEBUG
#define IF_SERIAL_DEBUG(x) ({x;})
#else
#define IF_SERIAL_DEBUG(x)
#endif

typedef uint16_t prog_uint16_t;
#define PSTR(x) (x)
#define printf_P printf
#define strlen_P strlen
#define PROGMEM
#define pgm_read_word(p) (*(p))
#define PRIPSTR "%s"
#define pgm_read_byte(p) (*(p))

// Function, constant map as a result of migrating from Arduino
#define LOW 0
#define HIGH 1
#define delay(milisec) wait_ms(milisec)
#define delayMicroseconds(usec) wait_us(usec)

#endif // __ARCH_CONFIG_H__

