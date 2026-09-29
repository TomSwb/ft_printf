/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:30 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/30 00:26:28 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_len(char *s, t_flags *flags)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (flags->precision && len > flags->precision_len)
		len = flags->precision_len;
	return (len);
}

int	deci_len(long value, t_flags *flags)
{
	int len;
	
	len = 0;
}