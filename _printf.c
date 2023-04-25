#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)

{

	int sum = 0;
	va_list valist;
	char *p, *start;

	parameters_t parameter = parameter_INIT;
	va_start(valist, format);

	if (!format || (format[0] == '%' && !format[1]))/* checking for NULL char */
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_parameter(&parameter, valist);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &parameter))
		{
			p++;
		}
		
		p = get_width(p, &parameter, valist);
		p = get_precision(p, &parameter, valist);
		if (get_modifier(p, &parameter))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					parameter.l_modifier || parameter.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, valist, &parameter);
	}
	_putchar(-1);
	va_end(valist);
	return (sum);
}
