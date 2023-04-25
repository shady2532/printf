#include "main.h"

#define PARAM_INITIALS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
    unsigned int sign           : 1;

    unsigned int plusFlag       : 1;
    unsigned int minusFlag      : 1;
    unsigned int hashFlag       : 1;
    unsigned int spaceFlag      : 1;
    unsigned int zeroFlag       : 1;

    unsigned int precision;
    unsigned int width;

    unsigned int l_modifier     : 1;
    unsigned int h_modifier     : 1;
} parameters_t;

/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
 * @ap: the argument pointer
 * Return: void
 */
void init_param(parameters_t *parameter, va_list valist)
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