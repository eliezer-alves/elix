#include <string.h>
#include "../../../../include/io/serial.h"

void echo(char *buff[])
{
  int i = 0;
  char str[1000] = ""; // inicializa uma string vazia
  while (buff[i] != NULL)
  {                       // enquanto o elemento atual não for NULL
    strcat(str, buff[i]); // concatena o elemento atual na string
    strcat(str, " ");     // concatena um espaço
    i++;                  // avança para o próximo elemento
  }

  serial_println(str);
}