/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:26 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/15 16:02:44 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
* @brief 


* @param const char *s 
* @param ... 
* @return int 
*/

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;
	int		result;

	count = 0;
	error_state(-2);
	va_start(args, s);
	while (*s && !error_state(0))
	{
		result = printf_loop(&s, &count, &args);
		if (!result)
			return (va_end(args), -1);
	}
	if (error_state(0))
		return (va_end(args), -1);
	return (va_end(args), count);
}

/**
* @brief 


* @param s 
* @param count 
* @param args 
* @return int 
*/

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

// Remembers whether a write() failed during the current ft_printf call.
// n == -2 : reset the state to 0 (no error). write() never returns -2.
// n == -1 : a write() failed, set the state to 1.
// any other value : only read the state, nothing changes.
// Returns the current state: 1 if a write failed, 0 otherwise.
int	error_state(int n)
{
	static int	error_check;

	if (n == -2)
		error_check = 0;
	else if (n == -1)
		error_check = 1;
	return (error_check);
}
