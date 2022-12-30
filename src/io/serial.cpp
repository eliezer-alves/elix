#include <Arduino.h>
#include "../../include/io/serial.h"

// // Implementação das funções da interface Serial
void serial_init(void)
{
  // Inicializa a interface Serial
  Serial.begin(9600);
  Serial.print("$ init Serial\n");
}

int serial_read(char *buf, int len)
{
  // Lê dados da interface Serial e os armazena em buf
  int n = Serial.readBytes(buf, len);
  return n;
}

int serial_write(char *buf, int len)
{
  // Envia dados para a interface Serial a partir de buf
  int n = Serial.write(buf, len);
  return n;
}

void serial_print(const char buf[])
{
  // Envia dados para a interface Serial a partir de buf
  Serial.print(buf);
}

void serial_println(const char buf[])
{
  // Envia dados para a interface Serial a partir de buf
  Serial.println(buf);
}

void serial_clear()
{
  // Limpa a interface Serial
  Serial.flush();

  // Envia uma quantidade suficiente de caracteres de espaço em branco para "sobrepor" os caracteres existentes na tela
  for (int i = 0; i < 25; i++)
  {
    Serial.println("");
  }

  // Reposiciona o cursor na primeira posição da tela
  Serial.println("\r->");
}