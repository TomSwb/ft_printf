
#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int count;
    t_flags flags;
    va_list args;
    
    va_start(args, s);
    while (*s)
    {
        if (*s == '%')
        {
            flags = init_flags();
            flags = parser(&s, &count);
            printer_manager();
        }
        else
        {
            putchar(s);
            count++;
            s++;
        }
    }
    va_end(args);
    return (count);
}

t_flags init_flags(void)
{
    t_flags flags;
    
    flags.left_padding = 0;
    flags.spaces = 0;
    flags.alt_hexa = 0;
    ...
}

t_flags parser(const char **s, int *count)
{
    t_flags flags;
    
    while (**s != is_converter(**s))
    {
        if (**s == '-')
            flags.left_align = 1;
        else if (**s == ' ')
            flags.spaces = 1;
        else if (**s == '0')
            flags.zero_padding = 1;
            
        (*s)++
        (*count)++;
    }
}

int printer_manager()
{
    
}

char is_converter(char c)
{
    char *s;
    
    s = "cspdiuxX%";
    while (*s)
    {
        if (*s == c)
            return ((char)s)
        s++;
    }
    return (NULL);
}