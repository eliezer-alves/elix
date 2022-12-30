#include <Arduino.h>
#include <string.h>

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

void shell_init()
{
  serial_println(DEFAULT_MESSAGE);
}

void shell(char *input)
{
  serial_println("");
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