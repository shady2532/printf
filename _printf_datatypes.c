#include "main.h"
#include "parameters.c"
/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list valist, parameters_t *parameter)
{
    long l;

    if(parameter->l_modifier)
        l = va_arg(valist, long);
    else if(parameter->h_modifier)
        l = (short int)va_arg(valist, int);
    else
        l = (int)va_arg(valist, int);

    return (print_number(convert(l, 10, 0, parameter), parameter));
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list valist, parameters_t *parameter)
{
	(void)valist;
	(void)parameter;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list valist, parameters_t *parameter)
{
    
}