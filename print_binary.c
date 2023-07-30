#include "main.h"
/**
 * print_bin - brint binary
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int num, i, bin[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(types, unsigned int);

	if (num == 0)
	{
		count = 1;
		bin[0] = '0';
		write(1, &bin[0], 1);
	}
	else
	{
		for (i = 0; (num >= ((unsigned int) (1 << i))) &&  i < 32; i++)
		{
			if (num & (1 << i))
				bin[i] = '1';
			else
				bin[i] = '0';
		}
		count = i--;
		while (i > 0)
		{
			write(1, &bin[i], 1);
			i--;
		}
		write(1, &bin[i], 1);
	}

	return (count);
}
