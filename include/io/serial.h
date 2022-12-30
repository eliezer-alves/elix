#ifndef SERIAL_H
#define SERIAL_H

// Declarações de funções para a interface Serial
void serial_init(void);
int serial_read(char *buf, int len);
int serial_write(char *buf, int len);
void serial_print(char *buf);

#endif // SERIAL_H
