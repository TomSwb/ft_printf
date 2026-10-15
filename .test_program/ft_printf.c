/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:26 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/15 15:45:50 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;
	int		result;

	count = 0;
	error_state(-2);
	va_start(args, s);
	while (*s)
	{
		result = printf_loop(&s, &count, &args);
		if (!result)
			return (va_end(args), -1);
	}
	if (error_state(0))
		return (va_end(args), -1);
	return (va_end(args), count);
}

int	printf_loop(const char **s, int *count, va_list *args)
{
	t_flags	flags;

	if (**s == '%' && *(*s + 1))
	{
		flags = init_flags();
		if (!parser(s, &flags))
			return (0);
		printer_manager(&flags, args, count);
	}
	else
	{
		if (**s == '%')
			return (0);
		*count += print_char(**s);
		(*s)++;
	}
	return (1);
}

int	error_state(int n)
{
	static int	error_check;

	if (n == -2)
		error_check = 0;
	else if (n == -1)
		error_check = 1;
	return (error_check);
}