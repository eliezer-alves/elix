#include <Arduino.h>
#include <string.h>

#include "../../include/shell/shell.h"
#include "../../include/io/serial.h"
#include "../../include/common/common.h"

#include "commands/version.c"
#include "commands/clear.c"

const int MAX_TOKENS = 10;
const char *DELIMITER = " ";
char MESSAGE_INIT[] = "$ init Shell\n",
     DEFAULT_MESSAGE[] = "$ ",
     UNKNOWN_COMMAND_MESSAGE[] = "unknown command";

int handleInput(char *input, char *tokens[]);

void shell_init()
{
  serial_println(MESSAGE_INIT);
}

void shell(char *input)
{
  char *tokens[10];
  int tokens_size = handleInput(input, tokens);
  char *command = tokens[0];
  serial_print("-> ");
  serial_println(command);

  if (strcmp(tokens[0], "version") == 0)
  {
    version();
  }
  else if (strcmp(tokens[0], "clear") == 0)
  {
    clear();
  }
  else
  {
    serial_println(UNKNOWN_COMMAND_MESSAGE);
  }
}

int handleInput(char *input, char *tokens[])
{
  char *token = strtok(input, DELIMITER);
  int i = 0;
  while (token != NULL && i < MAX_TOKENS)
  {
    tokens[i++] = token;
    token = strtok(NULL, DELIMITER);
  }

  return i;
}