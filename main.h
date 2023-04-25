#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);

//funcs.c
int _strlen(char *s);
int _putchar(char c);

//numbers.c
char *convert(long int num, int base);

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


#endif /* MAIN_H */
