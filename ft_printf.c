/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:26 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 09:55:09 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	t_flags	flags;
	va_list	args;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			flags = init_flags();
			if (!parser(&s, &flags))
				return (-1);
			printer_manager(&flags, &args, &count);
		}
		else
		{
			if (*s == '%')
				return (-1);
			count += print_char(*s);
			s++;
		}
	}
	va_end(args);
	return (count);
}

void	printer_manager(t_flags *flags, va_list *args, int *count)
{
	if (flags->converter == '%' || flags->converter == 'c' || flags->converter == 's')
		printer_manager_char(flags, args, count);
	else if (flags->converter == 'd' || flags->converter == 'i' || flags->converter == 'u')
		printer_manager_decimal(flags, args, count);
	// else if (flags->converter == 'x' || flags->converter == 'X')
	// 	printer_manager_hexa(flags, args, count);
	// else if (flags->converter == 'p')
	// 	 printer_manager_memory(flags, args, count);
}

void	printer_manager_char(t_flags *flags, va_list *args, int *count)
{
	char	c;
	char	*s;

	if (flags->converter == '%')
		*count += print_char('%');
	else if (flags->converter == 'c')
	{
		c = va_arg(*args, int);
		if (!flags->left_align && flags->min_width > 0)
			*count += print_padding(flags, 1);
		*count += print_char(c);
		if (flags->left_align && flags->min_width > 0)
			*count += print_padding(flags, 1);
	}
	else if (flags->converter == 's')
	{
		s = va_arg(*args, char *);
		if (!flags->left_align && flags->min_width > 0)
			*count += print_padding(flags, s_len(s, flags));
		*count += print_s(s, flags);
		if (flags->left_align && flags->min_width > 0)
			*count += print_padding(flags, s_len(s, flags));
	}
}

void	printer_manager_decimal(t_flags *flags, va_list *args, int *count)
{
	long	long value;
	int		len;
	int		sign;
	
	if (flags->converter == 'u')
		value = (long long)va_arg(*args, unsigned int);
	else
		value = (long long)va_arg(*args, int);
	len = deci_len(value, flags);
	sign = 0;
	if (value == 0 && flags->precision && flags->precision_len == 0)
	{
		*count += print_nothing(len, sign, flags);
		return ;
	}
	if (value < 0)
	{
		sign = 1;
		value = -value;
	}
	*count += print_deci(value, len, sign, flags);
}

void	printer_manager_hexa(t_flags *flags, va_list *args, int *count)
{
	long	long value;
	int		len;
	
	value = (long long)va_arg(*args, unsigned int);
	len = deci_len(value, flags);
	if (value == 0 && flags->precision && flags->precision_len == 0)
	{
		*count += print_nothing(len, 0, flags);
		return ;
	}
	*count += print_hexa(value, len, flags);
}

/*
void	printer_manager_memory(t_flags *flags, va_list *args, int *count)
{

}
*/