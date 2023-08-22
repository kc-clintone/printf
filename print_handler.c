#include "main.h"
/**
 * print_handler - prints args types to stdout
 * @format: standard format
 * @list: list of args
 * @flags: a list of all the flags
 * @index: index
 * @size: specifies sizes
 * @width: retrieves widths
 * @buffer: array to use while handling print
 * @precision: specifies precision for print
 * Return: ==> 1 or  2 otherwise
*/
int print_handler(const char *fmrt,
		int *index, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, _len = 0, counter = -1;
	fmrt_t f_types[] = {
		{'c', _character}, {'s', _string}, {'%', _percent},
		{'i', _integer}, {'d', _integer}, {'b', _binary},
		{'u', _unsigned}, {'o', _octal}, {'x', _hexadecimal},
		{'X', _uppercase_hex}, {'p', _pointer}, {'S', _forbidden},
		{'r', _reverse_print}, {'R', _rot13string}, {'\0', NULL},};
	for (i = 0; f_types[i].fmrt != '\0'; i++)
		if (fmrt[*index] == f_types[i].fmrt)
			return (f_types[i].fn(list, buffer,
				width, size, flags, precision));
	if (f_types[i].fmrt == '\0')
	{
		if (fmrt[*index] == '\0')
			return (-1);
		_len += write(1, "%%", 1);
		if (fmrt[*index - 1] == ' ')
			_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmrt[*index] != ' ' && fmrt[*index] != '%')
				--(*index);
			if (fmrt[*index] == ' ')
				--(*index);
			return (1);
	}
	_len += write(1, &fmrt[*index], 1);
	return (_len);
	}
	return (counter);
}
