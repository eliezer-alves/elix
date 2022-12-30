  #include <Arduino.h>
#include <string.h>
// #include "drivers/lcd/lcd.h"
#include "include/io/serial.h"
#include "include/shell/shell.h"

void setup()
{
  // lcd_init();
  serial_init();
  shell_init();
}

void loop()
{
  if (Serial.available())
  {
    String input_string = Serial.readStringUntil('\n');
    char *input = (char *)input_string.c_str();
    shell(input);
  }
}
