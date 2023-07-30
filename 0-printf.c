#include "main.h"
/**
 * _printf - Prints the output according to a certain format
 * @format: The format to be followed
 * @...: The arguments to be passed
 *
 * Return: length of printed string
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, len = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list ap;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%' || (format[i] == '%' && format[i + 1] == '%'))
		{
			if (format[i] == '%' && format[i + 1] == '%')
				i++;
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			len++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			i++;
			printed = handle_print(format, &i, ap, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			len += printed;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(ap);
	return (len);
}
