
#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    va_list args;
    
    va_start(args, s);
    while (*s)
    {
        s++;
    }
}

int is_converter(char c)
{
    
}
