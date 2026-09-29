
#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int count;
    t_flags flags;
    va_list args;
    
    count = 0;
    va_start(args, s);
    while (*s)
    {
        if (*s == '%' && *(s + 1))
        {
            flags = init_flags();
            parser(&s, &flags);
            printer_manager(flags, &args, &count);
        }
        else
        {
            count += ft_putchar(*s);
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
    flags.converter = '\0';
    return (flags);
}

void parser(const char **s, t_flags *flags)
{
    (*s)++;
    while (**s && is_flag(**s))
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
        (*s)++;
    }
    min_width_precison_len(flags, s);
    flags->converter = **s;
    (*s)++;
}

void printer_manager(t_flags flags, va_list *args, int *count)
{
    if (flags.converter == '%')
        *count += ft_putchar('%');
    else if (flags.converter == 'c')
        *count += ft_putchar(va_arg(*args, int)); 
}

