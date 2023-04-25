#include "main.h"
#include "parameters.c"
/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list valist;
	int *p,*start;

	parameters_t parameters = PARAM_INITIALS;

	va_start(valist, format);
	
        if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (!format || format[0] == '%' && format[1] == '\0')
		return (-1);
	for(p = (char *)format; *p; p++)
	{
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag character */
		{
			p++; /* next character */
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &params);
	}
	_putchar(-1);
	va_end(valist);
	return (sum);
}
