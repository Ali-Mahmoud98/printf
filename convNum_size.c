#include "main.h"
/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == SL)
		return (num);
	else if (size == SSHORT)
		return ((short)num);

	return ((int)num);
}
