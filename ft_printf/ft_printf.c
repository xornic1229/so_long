#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            count += process(args, format[i]);
        }
        else
        {
            ft_putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(args);
    return count;
}
