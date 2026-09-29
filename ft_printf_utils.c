/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:30 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/29 20:07:33 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

size_t ft_strlen(char *s, t_flags *flags)
{
    size_t len;
    
    len = 0;
    while (s[len])
        len++;
    if (flags->precision && len > flags->precision_len)
        len = flags->precision_len;
    return (len);
}