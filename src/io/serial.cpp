#include <Arduino.h>

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

void serial_print(char *buf)
{
  // Envia dados para a interface Serial a partir de buf
  Serial.print(buf);
}
