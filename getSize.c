#include "main.h"
/**
 * getSize - evaluates args size
 * @format: standard format
 * @i: array of args
 * Return: size
*/
int getSize(const char *format, int *i)
{
	int size = 0;
	int index = *i + 1;

	if (format[index] == 'l')
		size = S_LONG;
	else if (format[index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = index - 1;
	else
		*i = index;
	return (size);
}
