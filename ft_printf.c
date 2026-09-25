
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
            flags = parser(&s);
            
        }
        else
        {
            putchar(s);
            flags.print_count++;
            s++;
        }
    }
    va_end(args);
    return (flags.print_count);
}

t_flags parser(const char **s)
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