#include "main.h"
/**
 * _hexadecimal - prints unsigned hex to stdout
 * @types: array of args
 * @buffer: array to handle print
 * @flags:  gets active flag
 * @width: gets width
 * @precision: precision specifier
 * @size: size specifier
 * Return: num of chars
 */
int _hexadecimal(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
