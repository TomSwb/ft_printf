/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:26 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/29 20:15:16 by tomswb           ###   ########.fr       */
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
			parser(&s, &flags);
			printer_manager(&flags, &args, &count);
		}
		else
		{
			count += ft_putchar(*s);
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
	else if (flags->converter == 'p' || flags->converter == 'x' || flags->converter == 'X')
		printer_manager_hexa(flags, args, count);
}

void	printer_manager_char(t_flags *flags, va_list *args, int *count)
{
	char	c;
	char	*s;

	if (flags->converter == '%')
		*count += ft_putchar('%');
	else if (flags->converter == 'c')
	{
		c = va_arg(*args, int);
		if (!flags->left_align && flags->min_width > 0)
			*count = padding(flags, 1);
		*count += ft_putchar(c);
		if (flags->left_align && flags->min_width > 0)
			*count = padding(flags, 1);
	}
	else if (flags->converter == 's')
	{
		s = va_arg(*args, char *);
		if (!flags->left_align && flags->min_width > 0)
			*count = padding(flags, ft_strlen(s, flags));
		*count += ft_putstr(s, flags);
		if (flags->left_align && flags->min_width > 0)
			*count = padding(flags, ft_strlen(s, flags));
	}
}

void	printer_manager_decimal(t_flags *flags, va_list *args, int *count)
{

}

void	printer_manager_hexa(t_flags *flags, va_list *args, int *count)
{

}
