
#include "ft_printf.h"

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_flag(char c)
{
    char *s;
    
    s = "-0+# ";
    while (*s)
    {
        if (*s == c)
            return (1);
        s++;
    }
    return (0);
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

void min_width_precison_len(t_flags *flags, const char **s)
{
	if (is_num(**s))
    {
        while (is_num(**s))
        {
            flags->min_width = flags->min_width * 10 + (**s - 48);
            (*s)++;
        }
    }
    if (**s == '.')
    {
        (*s)++;
        while (is_num(**s))
        {
            flags->precision_len = flags->precision_len * 10 + (**s - 48);
            (*s)++;
        }
    }
}

int min_width()
{
    
}

int positive_sign()
{
    
}

int space()
{
    
}

int left_align()
{
    
}

int zero_padding()
{
    
}

int precision()
{
    
}

int alt_hexa()
{
    
}
