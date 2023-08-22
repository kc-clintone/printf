#include "main.h"
/**
 * _octal - prints an unsigned octal value to stdout
 * @types: array of args
 * @buffer: array to handle print
 * @flags: gets active flag
 * @width: gets width
 * @precision: precision specifier
 * @size: size specifier
 * Return: num of chars
 */
int _octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & HASHTAG && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
