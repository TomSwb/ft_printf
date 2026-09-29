/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:54:13 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/30 00:27:46 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding(t_flags *flags, int len_value)
{
	int count;
	int i;

	count = flags->min_width - len_value;
	if (count <= 0)
		return (0);
	i = 0;
	while (i < count)
	{
		if (flags->zero_padding && (flags->converter != 'c' 
			|| flags->converter != 's' || flags->converter != 'p'))
			print_char('0');
		else
			print_char(' ');
		i++;
	}
	return (count);
}

int	print_char(char value)
{
	write(1, &value, 1);
	return (1);
}

int	print_s(const char *value, t_flags *flags)
{
	size_t	i;
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
/*
int print_deci(int value)
{
    int count;
    
    return (count);
}

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