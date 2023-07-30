#include "main.h"
/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @index: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *index)
{
	enum SIZE size = DEF;
	int curr_index = *index + 1;

	if (format[curr_index] == 'l')
		size = SL;
	else if (format[curr_index] == 'h')
		size = SSHORT;

	if (size == 0)
		*index = curr_index - 1;
	else
		*index = curr_index;

	return (size);
}
