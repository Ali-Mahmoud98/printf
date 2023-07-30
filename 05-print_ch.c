#include "main.h"
/**
 * print_char - Prints a character
 * @types: List a of args
 * @buffer: Buffer array to handle print
 * @flags: active flags
 * @width: Width (length of string to be printed)
 * @precision: Precision specification
 * @size: Size specifier of the (int)
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
