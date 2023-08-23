#include "main.h"
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	char spacer = ' ';
	int i = 0;

	UNUSED(precision);
	UNUSED(size);

	if (flags & ZERO)
		spacer = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER - i - 2] = spacer;
		if (flags & NEG)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFFER - i - 1],
				width - 1));
		else
			return (write(1, &buffer[BUFFER - i - 1],
				width - 1) + write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
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
	int length = BUFFER - ind - 1;
	char spacer = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & ZERO) && !(flags & NEG))
		spacer = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & POS)
		extra_char = '+';
	else if (flags & SPACE)
		extra_char = ' ';
	return (write_num(ind, buffer, flags, width, precision,
		length, spacer, extra_char));
}
/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @spacer: Pading char
 * @extra_chr: Extra char
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[], int flags, int width,
	int prec, int length, char spacer, char extra_chr)
{
	int i, initial_spacer = 1;

	if (prec == 0 && ind == BUFFER - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFFER - 2 && buffer[ind] == '0')
		buffer[ind] = spacer = ' ';
	if (prec > 0 && prec < length)
		spacer = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_chr != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = spacer;
		buffer[i] = '\0';
		if (flags & NEG && spacer == ' ')
		{
			if (extra_chr)
				buffer[--ind] = extra_chr;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & NEG) && spacer == ' ')
		{
			if (extra_chr)
				buffer[--ind] = extra_chr;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & NEG) && spacer == '0')
		{
			if (extra_chr)
				buffer[--initial_spacer] = extra_chr;
			return (write(1, &buffer[initial_spacer], i
- initial_spacer) + write(1, &buffer[ind], length - (1 - initial_spacer)));
		}
	}
	if (extra_chr)
		buffer[--ind] = extra_chr;
	return (write(1, &buffer[ind], length));
}
/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER - ind - 1, i = 0;
	char spacer = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFFER - 2 &&
		buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		spacer = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & ZERO) && !(flags & NEG))
		spacer = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = spacer;
		buffer[i] = '\0';
		if (flags & NEG)
		{
			return (write(1, &buffer[ind], length)
				+ write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i)
				+ write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}
/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & NEG && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length)
				+ write(1, &buffer[3], i - 3));
		}
		else if (!(flags & NEG) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & NEG) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start)
+ write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFFER - ind - 1));
}
