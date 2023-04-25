#include "main.h"
#include "parameters.c"
/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, parameters_t *parameter)
{
        static char *array = "0123456789abcdef";
        static char buffer[50];
        char sign = 0;
        char *ptr;
        unsigned long n = num;

        if (num < 0)
        {
                n = -num;
                sign = '-';
        }
        ptr = &buffer[49];
        *ptr = '\0';

        do      {
                *--ptr = array[n % base];
                n /= base;
        } while (n != 0);

        if (sign)
                *--ptr = sign;
        return (ptr);
}

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
