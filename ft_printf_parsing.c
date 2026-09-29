/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:54:07 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/29 20:06:16 by tomswb           ###   ########.fr       */
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
	flags.spaces = 0;
	flags.min_width = 0;
	flags.precision = 0;
	flags.precision_len = 0;
	flags.converter = '\0';
	return (flags);
}

void	parser(const char **s, t_flags *flags)
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
	parse_min_width_precison(flags, s);
	flags->converter = **s;
	(*s)++;
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
