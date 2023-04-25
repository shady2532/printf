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
void init_param(parameters_t *parameter, va_list valist)
int get_flag(char *s, parameters_t *parameter)

#endif /* MAIN_H */
