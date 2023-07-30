#include "main.h"
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: An array of characters
 * @buff_index: Index add next char, means the length of buffer.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
