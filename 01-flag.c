#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @index: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *index)
{
	int j, curr_index;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {1, 2, 4, 8, 16, 0};

	for (curr_index = *index + 1; format[curr_index] != '\0'; curr_index++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_index] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*index = curr_index - 1;

	return (flags);
}
