#include "main.h"
/**
 * getAllFlags - returns the current flag
 * @format: the printf standard format to
 * be used
 * @i: increment param
 * Return: cureent flag(s)
*/
int getAllFlags(const char *format, int *i)
{
	int index, j, flags = 0;
	const char FLAGS[] = {'-', '0', '#', ' ', '\0'};
	const int FLAG_LIST[] = {0, POS, MIN, ZERO,
		HASHTAG, SPACE};

	for (index = *i + 1; format[index] != '\0'; index++)
	{
		for (j = 0; FLAGS[j] != '\0'; j++)
			if (format[index] == FLAGS[j])
			{
				flags = FLAG_LIST[j];
				break;
			}
		if (FLAGS[j] == 0)
			break;
	}
	*i = index--;
	return (flags);
}
