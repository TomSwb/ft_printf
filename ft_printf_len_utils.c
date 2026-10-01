/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 02:55:43 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 18:40:10 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_len(char *s, t_flags *flags)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (len);
	while (s[len])
		len++;
	if (flags->precision && len > flags->precision_len)
		len = flags->precision_len;
	return (len);
}

int	deci_len(long long value, t_flags *flags)
{
	int len;
	
	len = 0;
	if (value >= 0 && ((flags->positive_sign || flags->space)
		&& flags->converter != 'u'))
		len++;
	if (value <= 0)
	{
		len++;
		value = -value;
	}
	while (value > 0)
	{
		len++;
		value /= 10;
	}
	return (len);
}

int	pr_len(int len, t_flags *flags)
{
	int pr_len;
	
	pr_len = 0;
	if (!flags->precision)
		return (0);
	pr_len = len;
	if (flags->neg_sign || ((flags->positive_sign || flags->space) 
		&& flags->converter != 'u'))
		pr_len--;
	if (flags->alt_hexa && (flags->converter == 'x'
		|| flags->converter == 'X'))
		pr_len -= 2;
	pr_len = flags->precision_len - pr_len;
	if (pr_len <= 0)
		pr_len = 0;
	return (pr_len);
}

int	hexa_len(long long value, t_flags *flags)
{
	int len;
	
	len = 0;
	if (value == 0 && flags->min_width > 0 && !flags->alt_hexa
		&& !flags->positive_sign && !flags->precision
		&& !flags->space && !flags->zero_padding)
		return (1);
	else if (value == 0)
		return (0);
	if (flags->alt_hexa)
		len += 2;
	while (value > 0)
	{
		len++;
		value /= 16;
	}
	return (len);
}

int address_len(uintptr_t value)
{
	int len;
	
	len = 2;
	if (value == 0)
		return (5);
	while (value > 0)
	{
		len++;
		value /= 16;
	}
	return (len);
}
