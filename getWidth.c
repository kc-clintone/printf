#include "main.h"
/**
 * getWidth - calculates the required width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int getWidth(const char *format, int *i, va_list list)
{
	int width = 0;
	int index;

	for (index = *i + 1; format[index] != '\0'; index++)
	{
		if (is_digit(format[index]))
		{
			width *= 10;
			width += format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = index - 1;

	return (width);
}
