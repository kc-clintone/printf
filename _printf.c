#include "main.h"

int _printf(const char *format, ...)
{
    int i, counter = 0, current_bfr = 0;
    int _size, flags, _len, _prec, index = 0;
    va_list list;
    char bfr[BUFFER_SIZE];

    if (format == NULL)
        return (-1);
    va_start(list, format);
    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            bfr[index++] = format[i];
            if (index == BUFFER_SIZE)
            {
                log_to_console(bfr, &index);
            }
            counter++;
        }
        else
        {
            log_to_console(bfr, &index);
            _size = getSize(format, &i);
            _prec = getPrec(format, &i, list);
            flags = getAllFlags(format, &i);
            _len = getWidth(format, &i, list);
            ++i;
            current_bfr = print_handler(format, &i, list, bfr,
                                         flags, _len, _size, _prec);
            if (current_bfr == -1)
            {
                va_end(list);
                return (-1);
            }
            counter += current_bfr;
        }
    }
    log_to_console(bfr, &index);
    va_end(list);
    return (counter);
}
