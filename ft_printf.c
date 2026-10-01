/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:26 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 22:52:43 by tomswb           ###   ########.fr       */
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
				return (ft_printf("Error\n"), -1);
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
