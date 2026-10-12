/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:54:07 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/12 19:35:41 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.left_align = 0;
	flags.zero_padding = 0;
	flags.positive_sign = 0;
	flags.alt_hexa = 0;
	flags.space = 0;
	flags.neg_sign = 0;
	flags.min_width = 0;
	flags.precision = 0;
	flags.precision_len = 0;
	flags.converter = '\0';
	return (flags);
}

int	parser(const char **s, t_flags *flags)
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
			flags->space = 1;
		(*s)++;
	}
	parse_min_width_precison(flags, s);
	flags->converter = **s;
	if (!is_converter(flags->converter))
		return (0);
	(*s)++;
	parsing_check(flags);
	return (1);
}

void	parse_min_width_precison(t_flags *flags, const char **s)
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
		flags->precision = 1;
		(*s)++;
		while (is_num(**s))
		{
			flags->precision_len = flags->precision_len * 10 + (**s - 48);
			(*s)++;
		}
	}
}

void	parsing_check(t_flags *flags)
{
	if (flags->left_align)
	{
		flags->zero_padding = 0;
		flags->space = 0;
	}
	if (flags->precision && flags->converter != 's')
		flags->zero_padding = 0;
	if (flags->converter != 'd' || flags->converter != 'i')
	{
		flags->positive_sign = 0;
		flags->space = 0;
	}
	if (flags->converter != 'x' || flags->converter != 'X')
		flags->alt_hexa = 0;
	if (flags->converter == 'c' || flags->converter == 's'
		|| flags->converter == 'p')
		flags->zero_padding = 0;
	if (flags->converter == 'c' || flags->converter == 'p')
	{
		flags->precision = 0;
		flags->precision_len = 0;
	}
}
