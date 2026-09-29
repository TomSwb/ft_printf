/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:51:30 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/29 20:15:50 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s, t_flags *flags)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (flags->precision && len > flags->precision_len)
		len = flags->precision_len;
	return (len);
}

int int_len(int value, t_flags *flags)
{
	int len;
	
	len = 0;
}