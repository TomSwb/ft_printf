/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:30 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 13:21:32 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_padding(t_flags *flags, int len_value)
{
	int count;
	int i;

	count = flags->min_width - len_value;
	if (count <= 0)
		return (0);
	i = 0;
	while (i < count)
	{
		if (flags->zero_padding && !flags->left_align && !flags->precision
			&& flags->converter != 'c' && flags->converter != 's'
			&& flags->converter != 'p')
			print_char('0');
		else
			print_char(' ');
		i++;
	}
	return (count);
}

int	print_sign(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->neg_sign)
		count += print_char('-');
	else if (flags->positive_sign)
		count += print_char('+');
	else if (flags->space)
		count += print_char(' ');
	return (count);
}

int	print_precision(int pr_len)
{
	int count;
	
	count = 0;
	while (pr_len > 0)
	{
		count += print_char('0');
		pr_len--;
	}
	return (count);
}

int	print_nothing(int len, t_flags *flags)
{
	int count;

	count = 0;
	if (!flags->left_align)
		count += print_padding(flags, len - 1);
	if (flags->converter == 'd' || flags->converter == 'i')
		count += print_sign(flags);
	if (flags->left_align)
		count += print_padding(flags, len - 1);
	return (count);
}
