
#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int count;
    va_list args;
    
    va_start(args, s);
    while (*s)
    {
        s++;
    }
    va_end(args);
    return (count);
}

int is_converter(char c)
{
    
}
