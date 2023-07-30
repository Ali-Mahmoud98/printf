#include "main.h"
/**
 * get_precision - Calculates the precision for printing float
 * @format: Formatted string
 * @index: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: how many nums after decimal point.
 */
int get_precision(const char *format, int *index, va_list list)
{
	int curr_index = *index + 1;
	int precision = -1;

	if (format[curr_index] != '.')
		return (precision);

	precision = 0;

	for (curr_index += 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_digit(format[curr_index]))
		{
			precision *= 10;
			precision += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*index = curr_index - 1;

	return (precision);
}
