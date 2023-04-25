#include "main.h"
/**
 * _strlen - gets character string
 *
 * @s: character to getstring
 * Return: returns length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{}
	return (i);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 *
 * Return: string
 */
char *convert(long int num, int base)
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