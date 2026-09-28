
#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int count;
    t_flags flags;
    va_list args;
    size_t i;
    
    va_start(args, s);
    i = 0;
    while (*s)
    {
        if (*s == '%')
        {
            flags = init_flags();
            flags = parser(&s, &count);
            printer_manager(flags, args[i]);
            i++;
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
    
    flags.left_align = 0;
    flags.zero_padding = 0;
    flags.positive_sign = 0;
    flags.alt_hexa = 0;
    flags.spaces = 0;
    flags.min_width = 0;
    flags.precision_len = 0;
    flags.type = NULL;
    return (flags);
}

t_flags parser(const char **s, int *count)
{
    t_flags flags;
    
    (*s)++;
    while (**s != is_converter(**s))
    {
        if (**s == '-')
            flags.left_align = 1;
        else if (**s == '0')
            flags.zero_padding = 1;
        else if (**s == '+')
            flags.positive_sign = 1;
        else if (**s == '#')
            flags.alt_hexa = 1;
        else if (**s == ' ')
            flags.spaces = 1;
        else if ()
            flags.min_width = ... ;
        else if ()
            flags.precision_len = ... ;
        (*s)++;
        (*count)++;
    }
    return (flags);
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