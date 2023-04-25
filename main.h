#ifndef _PRINT_F
#define _PRINT_F

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define PARAM_INITIALS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
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
    unsigned int sign           : 1;

    unsigned int plusFlag       : 1;
    unsigned int minusFlag      : 1;
    unsigned int hashFlag       : 1;
    unsigned int spaceFlag      : 1;
    unsigned int zeroFlag       : 1;

    unsigned int precision;
    unsigned int width;

    unsigned int l_modifier     : 1;
    unsigned int h_modifier     : 1;
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

//_printf.c
int _printf(const char *format, ...);

//funcs.c
int _strlen(char *s);
int _putchar(char c);
int print_from_to(char *star, char *stop, char *except);

//numbers.c
char *convert(long int num, int base, int flags, parameters_t *parameter);
int _isdigit(int c);

//parameters.c
void init_param(parameters_t *parameter, va_list valist);
char *get_width(char *s, parameters_t *parameter, va_list valist);
int get_flag(char *s, parameters_t *parameter);
int get_modifier(char *s, parameters_t *parameter);

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

//_printf_datatypes
int print_int(va_list valist, parameters_t *parameter);
int print_percent(va_list valist, parameters_t *parameter);
int print_S(va_list valist, parameters_t *parameter);
int print_unsigned(va_list valist, parameters_t *parameter);
int print_address(va_list valist, parameters_t *parameter);

#endif /* _PRINT_F */
