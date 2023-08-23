#include "main.h"
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER - 2;
	unsigned long int long_number = va_arg(types, unsigned long int);

	long_number = convert_size_unsgnd(long_number, size);

	if (long_number == 0)
		buffer[i--] = '0';
	buffer[BUFFER - 1] = '\0';

	while (long_number > 0)
	{
		buffer[i--] = (long_number % 10) + '0';
		long_number /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER - 2;
	unsigned long int long_number = va_arg(types, unsigned long int);
	unsigned long int initial = long_number;

	UNUSED(width);

	long_number = convert_size_unsgnd(long_number, size);

	if (long_number == 0)
		buffer[i--] = '0';
	buffer[BUFFER - 1] = '\0';

	while (long_number > 0)
	{
		buffer[i--] = (long_number % 8) + '0';
		long_number /= 8;
	}
	if (flags & HASHTAG && initial != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFFER - 2;
	unsigned long int long_number = va_arg(types, unsigned long int);
	unsigned long int initial = long_number;

	UNUSED(width);

	long_number = convert_size_unsgnd(long_number, size);
	if (long_number == 0)
		buffer[i--] = '0';
	buffer[BUFFER - 1] = '\0';

	while (long_number > 0)
	{
		buffer[i--] = map_to[long_number % 16];
		long_number /= 16;
	}
	if (flags & HASHTAG && initial != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
