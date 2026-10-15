/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:26 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/12 19:49:05 by tschwab          ###   ########.ch       */
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
				return (va_end(args), -1);
			printer_manager(&flags, &args, &count);
		}
		else
		{
			if (*s == '%')
				return (va_end(args), -1);
			count += print_char(*s);
			s++;
		}
	}
	va_end(args);
	return (count);
}
