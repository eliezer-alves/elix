#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include <string.h>

// #include "drivers/lcd/lcd.h"
#include "include/io/serial.h"
#include "include/shell/shell.h"

volatile unsigned long clock_count = 0;

ISR(TIMER1_OVF_vect)                              //interrupção do TIMER1 
{
  TCNT1 = 0xC2F7;                                 // Renicia TIMER
  clock_count++;
} 

void init_timer() {
  // Configuração do timer1 
  TCCR1A = 0;                        //confira timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;                        //limpa registrador
  TCCR1B |= (1<<CS10)|(1 << CS12);   // configura prescaler para 1024: CS12 = 1 e CS10 = 1
 
  TCNT1 = 0xC2F7;                    // incia timer com valor para que estouro ocorra em 1 segundo
                                     // 65536-(16MHz/1024/1Hz) = 49911 = 0xC2F7
  
  TIMSK1 |= (1 << TOIE1);           // habilita a interrupção do TIMER1
}

void setup()
{
  init_timer();
  serial_init();
  shell_init();
  // lcd_init();
}

void loop()
{
  if (Serial.available())
  {
    String input_string = Serial.readStringUntil('\n');
    char *input = (char *)input_string.c_str();
    shell(input, clock_count);
  }
}
