#include "main.h"
/**
 * _percent - prints the symbol '%' to stdout
 * @types: array of args
 * @buffer: array to handle print
 * @flags:  gets active flag
 * @width: gets width
 * @precision: precision specifier
 * @size: size specifier
 * Return: num of chars
 */
int _percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

