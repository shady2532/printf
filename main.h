#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define parameter_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @sign: flag if unsigned value
 *
 * @plusFlag: on if plus_flag specified
 * @spaceFlag: on if hashtag_flag specified
 * @hashFlag: on if _flag specified
 * @zeroFlag: on if _flag specified
 * @minusFlag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int sign			: 1;

	unsigned int plusFlag		: 1;
	unsigned int spaceFlag		: 1;
	unsigned int hashFlag	: 1;
	unsigned int zeroFlag		: 1;
	unsigned int minusFlag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} parameters_t;

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

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list valist, parameters_t *parameter);
int print_int(va_list valist, parameters_t *parameter);
int print_string(va_list valist, parameters_t *parameter);
int print_percent(va_list valist, parameters_t *parameter);
int print_S(va_list valist, parameters_t *parameter);

/* number.c module */
char *convert(long int num, int base, int flags, parameters_t *parameter);
int print_unsigned(va_list ap, parameters_t *parameter);
int print_address(va_list ap, parameters_t *parameter);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, parameters_t *parameter);
int get_print_func(char *s, va_list ap, parameters_t *parameter);
int get_flag(char *s, parameters_t *parameter);
int get_modifier(char *s, parameters_t *parameter);
char *get_width(char *s, parameters_t *parameter, va_list ap);

/* convert_number.c module */
int print_hex(va_list ap, parameters_t *parameter);
int print_HEX(va_list ap, parameters_t *parameter);
int print_binary(va_list ap, parameters_t *parameter);
int print_octal(va_list ap, parameters_t *parameter);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, parameters_t *parameter);
int print_rot13(va_list ap, parameters_t *parameter);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, parameters_t *parameter);
int print_number_right_shift(char *str, parameters_t *parameter);
int print_number_left_shift(char *str, parameters_t *parameter);

/* parameter.c module */
void init_parameter(parameters_t *parameter, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, parameters_t *parameter, va_list ap);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif /*_MAIN_H_*/
