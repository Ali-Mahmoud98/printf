#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @index: index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1, 2, or -1;
 */
int handle_print(const char *format, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	/* "specifier" -> function*/
	specifier_t specifier_types[] = {
		{'c', print_char},
		{'s', printStr},
		{'i', print_int},
		{'d', print_int},
		{'b', print_bin},
		{'\0', NULL}
	};

	for (i = 0; specifier_types[i].specifier != '\0'; i++)
		if (format[*index] == specifier_types[i].specifier)
			return (specifier_types[i].ptr2func(list,
						buffer, flags,
						width, precision, size));

	if (specifier_types[i].specifier == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_len += write(1, &format[*index], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
