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
	int i = 0;
	
	va_start(valist, format);
	
	if (!format || format[0] == '%' && format[1] == '\0')
		return (-1);
	while (format != NULL && format[i] != '\0')
	{
		
	}

	va_end(valist);
	return (sum);
}
