/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:01:24 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 23:01:31 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_converter(char c)
{
	char	*s;

	s = "cspdiuxX%";
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	char	*s;

	s = "-0+# ";
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}
