
#include "ft_printf.h"

int ft_putchar(char value)
{
	write(1, &value, 1);
	return (1);    
}

int ft_putstr(const char *value, t_flags *flags)
{
    size_t i;
    int count;
    
    i = 0;
    count = 0;
    if (value == NULL)
    {
        if (flags->precision_len >= 6 || !flags->precision)
        {
            write(1, "(null)", 6);
            count += 6;
        }
        else
            return (count);
    }
    else
    {
        while (value[i] && (!flags->precision || i < flags->precision_len))
        {
            count += ft_putchar(value[i]);
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