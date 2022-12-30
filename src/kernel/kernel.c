#include <string.h>
#include "../../include/kernel/kernel.h"

// Implementação das funções do kernel
int run_command(char *command)
{
  // Executa o comando especificado e retorna o resultado
  if (strcmp(command, "hello") == 0)
  {
    // serial_write("Hello, world!\n", 14);
    return 0;
  }
  else if (strcmp(command, "echo") == 0)
  {
    char buf[128];
    // int n = serial_read(buf, 128);
    // serial_write(buf, n);
    return 0;
  }
  else
  {
    // serial_write("Unknown command\n", 16);
    return 1;
  }
}
