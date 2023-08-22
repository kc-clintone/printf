#include "main.h"
/**
 * log_to_console - prints a character to the
 * standard output
 * @bfr: array buffer of the charactr to print
 * @index: index of the caracter to print
 * Return: if success ==> chr
*/
void log_to_console(char bfr[], int *index)
{
	if (*index > 0)
		write(1, &bfr[0], *index);
	*index = 0;
}
