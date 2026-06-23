#include "functionality.h"
#include <util/delay.h>
#include <stdio.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

volatile uint8_t wake_up_flag = 0;

// Przerwanie od przycisku (INT0 na PD2)
ISR(INT0_vect) {
    wake_up_flag = 1;
}

// wartosci dla bme280
float temperature = 0.0;
float pressure = 0.0; 
float humidity = 0.0;     

uint8_t is_button_pressed(void) {
    if (IS_BUTTON_PRESSED) {
        _delay_ms(25);
        if (IS_BUTTON_PRESSED) {
            while(IS_BUTTON_PRESSED);
            return 1;
        }
    }
    return 0;
}

void show_tph(void) {
    char buffer[30];

    temperature = bme280_readTemperature(0);
    pressure = bme280_readPressure(0);
    humidity = bme280_readHumidity(0);
    
    SSD1306_ClearScreen();
    
    SSD1306_SetPosition(0, 0);
    snprintf(buffer, sizeof(buffer), "Temperatura: %.1f C", temperature);
    SSD1306_DrawString(buffer);
    
    SSD1306_SetPosition(0, 2);
    snprintf(buffer, sizeof(buffer), "Cisnienie: %.1f hPa", pressure);
    SSD1306_DrawString(buffer);
    
    SSD1306_SetPosition(0, 4);
    snprintf(buffer, sizeof(buffer), "Wilgotnosc: %.1f %%", humidity);
    SSD1306_DrawString(buffer);
    
    SSD1306_UpdateScreen(SSD1306_ADDR);
}
void show_time(char *time_buffer, size_t time_size,
               char *date_buffer, size_t date_size,
               uint8_t hour, uint8_t minute, uint8_t second,
               uint8_t day, uint8_t month, uint8_t year) {
    
    SSD1306_ClearScreen();
    
    // Formatowanie czasu
    snprintf(time_buffer, time_size, "%02u:%02u:%02u", hour, minute, second);
    SSD1306_SetPosition(0, 0);
    SSD1306_DrawString(time_buffer);
    
    // Formatowanie daty
    snprintf(date_buffer, date_size, "%02u/%02u/%04u", day, month, year);
    SSD1306_SetPosition(0, 2);
    SSD1306_DrawString(date_buffer);
    
    SSD1306_UpdateScreen(SSD1306_ADDR);
}

void sleep(void) {
    SSD1306_ClearScreen();
    SSD1306_UpdateScreen(SSD1306_ADDR);
    
    EICRA |= (1 << ISC01);  //przerwanie 
    EIMSK |= (1 << INT0);   
    
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sei();
    
    // Do przerwania
    while (!wake_up_flag) {
        sleep_cpu();
    }
    
    sleep_disable();
    wake_up_flag = 0;
    
    _delay_ms(200);  
}
