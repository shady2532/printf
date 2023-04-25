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

	parameters_t parameters = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	va_start(valist, format);

	if (!format || format[0] == '%' && format[1] == '\0')
		return (-1);
	for(p = (char *)format; *p; p++)
	{
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}

	}

	va_end(valist);
	return (sum);
}
