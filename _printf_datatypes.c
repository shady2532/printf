#include "main.h"

/**
 * print_int - prints integer
 * @valist: argument pointer
 * @parameter: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list valist, parameters_t *parameter)
{
	long l;

	if (parameter->l_modifier)
		l = va_arg(valist, long);
	else if (parameter->h_modifier)
		l = (short int)va_arg(valist, int);
	else
		l = (int)va_arg(valist, int);
	return (print_number(convert(l, 10, 0, parameter), parameter));
}

/**
 * print_percent - prints string
 * @valist: argument pointer
 * @parameter: the parameters struct
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
 * @valist: argument pointer
 * @parameter: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list valist, parameters_t *parameter)
{
	char *str = va_arg(valist, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts("(null)"));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, parameter);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @valist: argument pointer
 * @parameter: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list valist, parameters_t *parameter)
{
	unsigned long l;
	if (parameter->l_modifier)
		l = (unsigned long)va_arg(valist, long);
	else if (parameter->h_modifier)
		l = (unsigned short int)va_arg(valist, int);
	else
		l = (unsigned int)va_arg(valist, int);

	parameter->sign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, parameter), parameter));
}

/**
 * print_address - prints address
 * @valist: argument pointer
 * @parameter: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list valist, parameters_t *parameter)
{
	unsigned long int n = va_arg(valist, unsigned long int);
	char *s;
	if (!n)
		return (_puts("(nil)"));
	s = convert(n, 16, CONVERT_LOWERCASE | CONVERT_UNSIGNED, parameter);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, parameter));
}
