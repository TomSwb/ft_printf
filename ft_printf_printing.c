
#include "ft_printf.h"

int ft_putchar(char value)
{
	write(1, &value, 1);
	return (1);    
}

int putnbr(void *value)
{
    
}

int ft_putstr(void *value)
{
    char *s;
    size_t i;
    int count;
    
    s = (char *)value;
    while (s[i])
    {
        count += ft_putchar(s[i]);
        i++;
    }
    return (count);
}

int puthexa(t_flags *flags, void *value)
{
    char *hexa_low;
    char *heca_up;
    char *base;
    
    hexa_low = "0123456789abcdef";
    hexa_up = "0123456789ABCDEF";
    if (flags->convert == 'X')
        base = hexa_up;
    else if (flags->convert == 'x')
        base = hexa_low;
}