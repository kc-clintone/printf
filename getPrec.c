#include "main.h"
/**
 * getPrec - gets the precisions need
 * @format: standard printf format
 * @i: args to be retrieved
 * @list: array of args
 * Return: returns precisons
*/
int getPrec(const char *format, int *i, va_list list)
{
	int prec = -1;
	int index = *i + 1;

	if (format[index] != '.')
		return (prec);

	prec = 0;
	for (index += -1; format[index] != '\0'; index++)
	{
		if (is_digit(format[index]))
		{
			prec *= 10;
			prec += format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index++;
			prec = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = index - 1;
	return (prec);
}
