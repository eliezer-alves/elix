#include "../../../../include/common/common.h"
#include "../../../../include/io/serial.h"

void version()
{
  serial_println(VERSION_STR);
}
