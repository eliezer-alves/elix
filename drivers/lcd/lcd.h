#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal.h>

extern LiquidCrystal lcd;

const int pinRS = 8; // Pino de controle de registro de dados
const int pinE = 9;  // Pino de habilitação de escrita
const int pinD4 = 4; // Pino D4 do display LCD
const int pinD5 = 5; // Pino D5 do display LCD
const int pinD6 = 6; // Pino D6 do display LCD
const int pinD7 = 7; // Pino D7 do display LCD

LiquidCrystal lcd(pinRS, pinE, pinD4, pinD5, pinD6, pinD7); // Cria um objeto do tipo

void lcd_init()
{
  lcd.begin(16, 2);
}

#endif
