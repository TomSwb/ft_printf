/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:54:13 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/30 03:20:43 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char value)
{
	write(1, &value, 1);
	return (1);
}

int	print_s(const char *value, t_flags *flags)
{
	int	i;
	int		count;

	i = 0;
	count = 0;
	if (value == NULL)
	{
		if (!flags->precision || flags->precision_len >= 6)
		{
			write(1, "(null)", 6);
			count += 6;
		}
		else
			return (count);
	}
	else
	{
		while (value[i] && (!flags->precision || i < flags->precision_len))
		{
			count += print_char(value[i]);
			i++;
		}
	}
	return (count);
}

int print_deci(long long value, int len, int sign, t_flags *flags)
{
	int count;
	int	div;

	count = 0;
	div = 1;
	while (value / div >= 10)
		div *= 10;
	if (flags->zero_padding && !flags->precision && !flags->left_align
		&& (flags->converter == 'd' || flags->converter == 'i'))
		count += print_sign(sign, flags);
	if (!flags->left_align && flags->min_width > 0)
		count += print_padding(flags, len + pr_len(len, sign, flags));
	if ((!flags->zero_padding || flags->precision || flags->left_align)
		&& (flags->converter == 'd' || flags->converter == 'i'))
		count += print_sign(sign, flags);
	if (flags->precision)
		count += print_precision(pr_len(len, sign, flags));
	while (div > 0)
	{
		count += print_char((value / div) % 10 + 48);
		div /= 10;
	}
	if (flags->left_align && flags->min_width > 0)
		count += print_padding(flags, len + pr_len(len, sign, flags));
    return (count);
}

/*
int print_hexa(t_flags *flags, int value)
{
    char *hexa_low;
    char *heca_up;
    char *base;
    int count;
    
    hexa_low = "0123456789abcdef";
    hexa_up = "0123456789ABCDEF";
    if (flags->convert == 'X')
        base = hexa_up;
    else if (flags->convert == 'x')
        base = hexa_low;
    
    
    
    return (count);
}

int ft_putaddress(void *value)
{
    
}
*/