#include "main.h"

/**
 * print_char - prints character
 * @valist: argument pointer
 * @parameters: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list valist, parameters_t *parameters)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(valist, int);

	if (parameters->minusFlag)
		sum += _putchar(ch);
	while (pad++ < parameters->width)
		sum += _putchar(pad_char);
	if (!parameters->minusFlag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_string - prints string
 * @valist: argument pointer
 * @parameters: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list valist, parameters_t *parameters)
{
	char *str = va_arg(valist, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)parameters;
	switch ((int)(!str))
		case 1:
			str = "(null)";

	j = pad = _strlen(str);
	if (parameters->precision < pad)
		j = pad = parameters->precision;

	if (parameters->minusFlag)
	{
		if (parameters->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < parameters->width)
		sum += _putchar(pad_char);
	if (!parameters->minusFlag)
	{
		if (parameters->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @valist: string
 * @parameters: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list valist, parameters_t *parameters)
{
	int len, sum = 0;
	char *str = va_arg(valist, char *);
	(void)parameters;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @valist: string
 * @parameters: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list valist, parameters_t *parameters)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(valist, char *);
	(void)parameters;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
