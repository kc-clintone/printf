#include "main.h"
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & ZERO) && !(flags & MIN))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & POS)
		extra_ch = '+';
	else if (flags & SPACE)
		extra_ch = ' ';
	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}
