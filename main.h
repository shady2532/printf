#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>



int _printf(const char *format, ...);

//funcs.c
int _strlen(char *s);
int _putchar(char c);

//numbers.c
char *convert(long int num, int base);

#endif /* MAIN_H */