#include "main.h"
/**
 * print_hexa_upper - prints an unsigned number in
 * upper hexadecimal notation to stdout
 * @types: array of args
 * @buffer: array to handle print
 * @flags:  gets active flag
 * @width: gets width
 * @precision: precision specifier
 * @size: size specifier
 * Return: num of chars
 */
int _uppercase_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

