#include "main.h"

#define PARAM_INITIALS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * init_params - clears struct fields and reset buf
 * @parameter: the parameters struct
 * @valist: the argument pointer
 * Return: void
 */
void init_parameter(parameters_t *parameter, va_list valist)
{
	parameter->sign = 0;
	
	parameter->hashFlag = 0;
	parameter->plusFlag = 0;
	parameter->zeroFlag = 0;
	parameter->minusFlag = 0;
	parameter->spaceFlag = 0;
	
	parameter->width = 0;
	parameter->precision = UINT_MAX;
	
	parameter->l_modifier = 0;
	parameter->h_modifier = 0;
	
	(void)valist;
}

/**
 * get_flag - finds the flag functions
 * @s: the format string
 * @parameter: the parameters struct
 * Return: if flag was valid
 */
int get_flag(char *s, parameters_t *parameter)
{
	int i = 0;
	
	switch (*s)
	{
		case '+':
			i = parameter->plusFlag = 1;
			break;
		case '-':
			i = parameter->minusFlag = 1;
			break;
		case ' ':
			i = parameter->spaceFlag = 1;
			break;
		case '#':
			i = parameter->hashFlag = 1;
			break;
		case '0':
			i = parameter->zeroFlag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier function
 * @s: string for format
 * @parameter: parameter structure
 * Return: if modifier was valid
 */
int get_modifier(char *s, parameters_t *parameter)
{
	int i = 0;
	
	switch (*s)
	{
		case 'h':
			i = parameter->h_modifier = 1;
			break;
		case 'l':
			i = parameter->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @parameter: the parameters struct
 * @valist: the argument pointer
 * Return: new pointer
 */
char *get_width(char *s, parameters_t *parameter, va_list valist)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(valist, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	parameter->width = d;
	return (s);
}
