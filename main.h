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
/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, parameters_t *);
} specifier_t;

//_print_string
int print_char(va_list valist, parameters_t *parameters);
int print_string(va_list valist, parameters_t *parameters);
int print_rev(va_list valist, parameters_t *parameters);
int print_rot13(va_list valist, parameters_t *parameters);

//_print_base
int print_hex(va_list valist, parameters_t *parameters);
int print_HEX(va_list valist, parameters_t *parameters);
int print_binary(va_list valist, parameters_t *parameters);
int print_octal(va_list valist, parameters_t *parameters);

#endif /* MAIN_H */
