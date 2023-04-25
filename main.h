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

//parameters.c
void init_param(parameters_t *parameter, va_list valist);
int get_flag(char *s, parameters_t *parameter);

#endif /* MAIN_H */
