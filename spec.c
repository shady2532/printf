#include "main.h"

/**
 * get_specifier - finds the format function
 * @s: string of the format
 * Return: the number of bytes printed
 */

int (*get_specifier(char *s))(va_list valist, parameters_t *parameters)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"r", print_rev},
		{"R", print_rot13},
		{"s", print_string},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"d", print_int},
		{"i", print_int},
		{"%", print_percent},
		{"u", print_unsigned},
		{"p", print_address},
		{"S", print_S},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function
 * @s: string of the format
 * @valist: argument pointer
 * @parameters: the parameters struct
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list valist, parameters_t *parameters)
{
	int (*f)(va_list, parameters_t *) = get_specifier(s);

	if (f)
		return (f(valist, parameters));
	return (0);
}
