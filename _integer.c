#include "main.h"
/**
 * _integer - prints an int to stdout
 * @types: array of args
 * @buffer: array to handle print
 * @flags:  gets active flag
 * @width: gets width
 * @precision: precision specifier
 * @size: size specifier
 * Return: num of chars
 */
int _integer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(
			is_negative, i, buffer,
			flags, width, precision, size));
}
