#include "ft_printf.h"

int ft_putchar(const char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *s)
{
    int i = 0;
    if (!s)
        return ft_putstr("(null)");
    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    return (i);
}

int ft_puthex(unsigned long nbr, char *base)
{
    int count = 0;
    if (nbr >= 16)
        count += ft_puthex(nbr / 16, base);
    count += ft_putchar(base[nbr % 16]);
    return (count);
}

int ft_putptr(void *ptr)
{
    unsigned long nbr;

    if (!ptr)
        return ft_putstr("(nil)");
    nbr = (unsigned long)ptr;
    write(1, "0x", 2);
    return (ft_puthex(nbr, "0123456789abcdef") + 2);
}
