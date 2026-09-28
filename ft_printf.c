
#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int count;
    t_flags flags;
    va_list args;
    
    va_start(args, s);
    count = 0;
    while (*s)
    {
        if (*s == '%')
        {
            flags = init_flags();
            parser(&s, &flags);
            printer_manager(flags, &args, &count);
        }
        else
        {
            putchar(*s);
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

void parser(const char **s, t_flags *flags)
{
    (*s)++;
    while (!is_converter(**s))
    {
        if (**s == '-')
            flags->left_align = 1;
        else if (**s == '0')
            flags->zero_padding = 1;
        else if (**s == '+')
            flags->positive_sign = 1;
        else if (**s == '#')
            flags->alt_hexa = 1;
        else if (**s == ' ')
            flags->spaces = 1;
        else if (isnum(**s))
        {
            while (isnum(**s))
            {
                flags->min_width = flags->min_width * 10 + (**s - 48);
                (*s)++;
            }
        }
        else if (**s == '.')
        {
            (*s)++;
            while (isnum(**s))
            {
                flags->precision_len = flags->precision_len * 10 + (**s - 48);
                (*s)++;
            }
        break ;
        }
        (*s)++;
    }
    flags->type = **s;
    (*s)++;
}

int printer_manager(t_flags flags, va_list *args, int *count)
{
    
}

int is_converter(char c)
{
    char *s;
    
    s = "cspdiuxX%";
    while (*s)
    {
        if (*s == c)
            return (1);
        s++;
    }
    return (0);
}