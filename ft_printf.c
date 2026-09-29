/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:26 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/29 17:53:36 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            printer_manager(&flags, &args, &count);
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

void printer_manager(t_flags *flags, va_list *args, int *count)
{
    char *s;
    long n;
    
    if (flags->converter == '%')
        *count += ft_putchar('%');
    else if (flags->converter == 'c')
    {
        if (!flags->left_align)
            padding(flags, &c);
        *count += ft_putchar(va_arg(*args, int));
        if (flags->left_align)
            padding(flags, &c);
    }
    else if (flags->converter == 's')
    {
        s = va_arg(*args, char *);
        if (!left_align)
            padding(flags, s)
        *count += ft_putstr(s, flags);
        if (left_align)
            padding(flags, s)
    }
}

