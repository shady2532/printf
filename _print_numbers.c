#include "main.h"

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, parameters_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->sign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minusFlag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, parameters_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zeroFlag && !params->minusFlag)
		pad_char = '0';
	neg = neg2 = (!params->sign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minusFlag)
		str++;
	else
		neg = 0;
	if ((params->plusFlag && !neg2) ||
		(!params->plusFlag && params->spaceFlag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plusFlag && !neg2 && pad_char == '0' && !params->sign)
		n += _putchar('+');
	else if (!params->plusFlag && params->spaceFlag && !neg2 &&
		!params->sign && params->zeroFlag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plusFlag && !neg2 && pad_char == ' ' && !params->sign)
		n += _putchar('+');
	else if (!params->plusFlag && params->spaceFlag && !neg2 &&
		!params->sign && !params->zeroFlag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, parameters_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zeroFlag && !params->minusFlag)
		pad_char = '0';
	neg = neg2 = (!params->sign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minusFlag)
		str++;
	else
		neg = 0;

	if (params->plusFlag && !neg2 && !params->sign)
		n += _putchar('+'), i++;
	else if (params->spaceFlag && !neg2 && !params->sign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
