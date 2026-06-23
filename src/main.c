
#include "functionality.h"
#define BME280_ADDRESS 0x76

// stan do switcha i menu
uint8_t menu_mode = 0;


int main(void) {

	BUTTON_DIR |= BUTTON;
	BUTTON_ON;

	i2c_init();         // inicjalizacja magistrali I2C
	bme280_init(BME280_ADDRESS); 	// inicjalizacja bme280
   	SSD1306_Init(SSD1306_ADDR);     // inicjalizacja ssd1306
	initUSART();		// inicjalizacja USART
	initDS3231();     // inicjalizacja ds3231

	ds3231Use12HourMode(false);
	ds3231SetTime(15, 0, 0, false);  // ustawienie czasu
	ds3231SetFullDate(MONDAY, 20, APRIL, 26, 21); // ustawienie daty
	ds3231SetCentury(century); // ustawienie stulecia
	
	while(1){

		uint8_t hour = ds3231GetHour();
        uint8_t minute = ds3231GetMinute();
        uint8_t second = ds3231GetSecond();
 		uint8_t day     = ds3231GetDate();
        uint8_t month   = ds3231GetMonth();
        uint8_t year    = ds3231GetYear();

		char time_buffer[9]; // bufor na czas
		char date_buffer[11]; 	// Bufor na date

		//sprawdza gdy tryb jest powyzej 2 to wraca do 0
			if(is_button_pressed()){
				menu_mode++;
				if(menu_mode > 2){
				 menu_mode = 0;
				}
			}


	switch(menu_mode) {
		case 0:
			show_tph();
			break;
		case 1:
			show_time(time_buffer, sizeof(time_buffer), date_buffer, sizeof(date_buffer), hour, minute, second, day, month, year);
			break;
		case 2:
			sleep();
			menu_mode = 0;
			break;

	}
	_delay_ms(50);
return 0;
	}
}
