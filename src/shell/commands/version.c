#include "../../../include/common/common.h"
#include "../../../include/io/serial.h"

void version()
{
  char version_str[] = VERSION_STR;
  serial_print(version_str);
}
