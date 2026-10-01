/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:54:13 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 13:21:16 by tomswb           ###   ########.fr       */
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

int print_deci(long long value, int len, t_flags *flags)
{
	int count;
	int	div;

	count = 0;
	div = 1;
	while (value / div >= 10)
		div *= 10;
	if (flags->zero_padding && !flags->precision && !flags->left_align
		&& (flags->converter == 'd' || flags->converter == 'i'))
		count += print_sign(flags);
	if (!flags->left_align && flags->min_width > 0)
		count += print_padding(flags, len + pr_len(len, flags));
	if ((!flags->zero_padding || flags->precision || flags->left_align)
		&& (flags->converter == 'd' || flags->converter == 'i'))
		count += print_sign(flags);
	if (flags->precision)
		count += print_precision(pr_len(len, flags));
	while (div > 0)
	{
		count += print_char((value / div) % 10 + 48);
		div /= 10;
	}
	if (flags->left_align && flags->min_width > 0)
		count += print_padding(flags, len + pr_len(len, flags));
    return (count);
}


int		print_hexa(long long value, char *base, t_flags *flags)
{
    int	hex_len;
    int count;
	int	div;
    
	hex_len = hexa_len(value);
	div = 1;
	while (value / div >= 16)
		div *= 16;
    while (div > 0)
	{
		count += print_char(base[(value / div) % 16]);
		div /= 16;
	}
    
    
    return (count);
}

/*
int print_address(void *value)
{
    
}
*/