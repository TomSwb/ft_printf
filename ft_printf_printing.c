
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
    
    s = (char *)value;
    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    return (i - 1);
}

int puthexa(void *value)
{
    
}