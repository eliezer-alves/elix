#include <Arduino.h>
#include <string.h>
#include <time.h>

#include "../../include/shell/shell.h"
#include "../../include/io/serial.h"
#include "../../include/common/common.h"

#include "commands/version/version.h"
#include "commands/clear/clear.h"
#include "commands/echo/echo.h"

const int MAX_BUFFER = 5;
const char *DELIMITER = " ";
char DEFAULT_MESSAGE[] = "> ",
     UNKNOWN_COMMAND_MESSAGE[] = "unknown command";

int handleInput(char *input, char *buffer[], char *args[], char *command);
void toDate(unsigned long timestamp, char *date);

void shell_init()
{
  serial_println(DEFAULT_MESSAGE);
}

void shell(char *input, volatile unsigned long clock_count)
{
  char date[20];
  toDate(clock_count, date);

  serial_println("");
  serial_print("[");
  serial_print(date);
  serial_print("] ");
  serial_print(DEFAULT_MESSAGE);
  serial_println(input);

  char *buffer[MAX_BUFFER] = {}, *args[MAX_BUFFER - 1] = {}, command[32] = "";
  int buffer_size = handleInput(input, buffer, args, command);

  if (strcmp(command, "version") == 0)
  {
    version();
  }
  else if (strcmp(command, "clear") == 0)
  {
    clear();
  }
  else if (strcmp(command, "echo") == 0)
  {
    echo(args);
  }
  else
  {
    serial_print(UNKNOWN_COMMAND_MESSAGE);
    serial_print(" ");
    serial_print("'");
    serial_print(command);
    serial_println("'");
  }
}

int handleInput(char *input, char *buffer[], char *args[], char *command)
{
  char *token = strtok(input, DELIMITER);
  int i = 0;
  while (token != NULL && i < MAX_BUFFER)
  {
    if (i > 0)
    {
      args[i - 1] = token;
    }

    buffer[i++] = token;
    token = strtok(NULL, DELIMITER);
  }

  strcpy(command, buffer[0]);

  return i;
}

void toDate(unsigned long timestamp, char *date) {
  time_t t = (time_t)timestamp;  // Converte o timestamp para o tipo time_t
  struct tm *tm = localtime(&t);  // Obtém a estrutura tm com a data e hora correntes

  // Gera a string no formato "d/m/Y H:m:s" usando a estrutura tm
  sprintf(date, "%d/%d/%d %02d:%02d:%02d", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);
}