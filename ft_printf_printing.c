
#include "ft_printf.h"

int ft_putchar(char value)
{
	write(1, &value, 1);
	return (1);    
}

int ft_putstr(const char *value, t_flags *flags)
{
    char *s;
    size_t i;
    int count;
    
    s = (char *)value;
    count = 0;
    if (flags->precision_len)
    {
        while (i < flags->precision_len && s[i])
        {
            count += ft_putchar(s[i]);
            i++;
        }
    }
    else
    {
        while (s[i])
        {
            count += ft_putchar(s[i]);
            i++;
        }
    }
    return (count);
}

int putnbr(int value)
{
    int count;
    
    return (count);
}

int puthexa(t_flags *flags, int value)
{
    char *hexa_low;
    char *heca_up;
    char *base;
    int count;
    
    hexa_low = "0123456789abcdef";
    hexa_up = "0123456789ABCDEF";
    if (flags->convert == 'X')
        base = hexa_up;
    else if (flags->convert == 'x')
        base = hexa_low;
    
    
    
    return (count);
}

int ft_putaddress(void *value)
{
    
}