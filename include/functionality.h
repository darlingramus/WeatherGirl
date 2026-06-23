/*
 * functiotality.h
 *
 *  Created on: 6 kwi 2026
 *      Author: olek
 */


#ifndef __FUNCTIONALITY_H__
#define __FUNCTIONALITY_H__

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/power.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <util/delay.h>
#include <inttypes.h>
#include "bme280.h"
#include "ssd1306.h"
#include "font.h"
#include "DS3231.h"
#include "USART.h"



// przycisk
#define BUTTON          (1<<PD2)
#define BUTTON_DIR      DDRD
#define BUTTON_PORT     PORTD
#define BUTTON_PIN      PIND

#define BUTTON_OFF      BUTTON_PORT &= ~BUTTON
#define BUTTON_ON       BUTTON_PORT |= BUTTON
#define IS_BUTTON_PRESSED   (!(BUTTON_PIN & BUTTON))

// adres dla oleda
#define SSD1306_ADDR 0x3C

// funkcje
uint8_t is_button_pressed(void);
void show_tph(void);
void show_time(char *time_buffer, size_t time_size,
               char *date_buffer, size_t date_size,
               uint8_t hour, uint8_t minute, uint8_t second,
               uint8_t day, uint8_t month, uint8_t year);
void sleep(void);

#endif
