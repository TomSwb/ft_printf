/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:54:13 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 19:39:53 by tomswb           ###   ########.fr       */
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
	int	count;

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
	int			count;
	long long	div;

	count = 0;
	div = def_div(value, flags);
	if (flags->zero_padding && !flags->precision && !flags->left_align
		&& (flags->converter == 'd' || flags->converter == 'i'))
		count += print_prefix(flags);
	if (!flags->left_align && flags->min_width > 0)
		count += print_padding(flags, len + pr_len(len, flags));
	if ((!flags->zero_padding || flags->precision || flags->left_align)
		&& (flags->converter == 'd' || flags->converter == 'i'))
		count += print_prefix(flags);
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
	int			hex_len;
	int			count;
	long long	div;

	count = 0;
	hex_len = hexa_len(value, flags);
	div = def_div(value, flags);
	if (!flags->left_align && flags->min_width > 0)
		count += print_padding(flags, hex_len + pr_len(hex_len, flags));
	if ((!flags->zero_padding || flags->precision
		|| flags->left_align) && value != 0)
		count += print_prefix(flags);
	if (flags->precision && flags->precision_len != 0)
		count += print_precision(pr_len(hex_len, flags));
	if (value == 0 && !flags->precision && !flags->zero_padding)
		count += print_char('0');
	else
	{
		while (div > 0)
		{
			count += print_char(base[(value / div) % 16]);
			div /= 16;
		}
	}
	return (count);
}


int print_address(uintptr_t value)
{
	int			count;
	uintptr_t	div;
	char		*base;

	base = "0123456789abcdef";
	count = 0;
	count += print_char('0');
	count += print_char('x');
	div = 1;
	while (value / div >= 16)
	{
		if (div > value / 16)
			break ;
		div *= 16;
	}
	while (div > 0)
	{
		count += print_char(base[(value / div) % 16]);
		div /= 16;
	}
	return (count);
}
