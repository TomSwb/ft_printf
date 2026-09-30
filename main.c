/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:54:22 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/30 03:29:16 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test_percent(void);
void	test_c(void);
void	test_s(void);
void	test_d(void);
void	test_i(void);
void	test_u(void);

int	main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	if (av[1][0] == '\0')
		return (-1);
	if (av[1][0] == '1')
	{
		ft_printf("\n");
		ft_printf("control, string ending with arg symbol: %");
		ft_printf("\n");
	}
	if (av[1][0] == '%')
	{
		ft_printf("\n");
		test_percent();
		ft_printf("\n");
	}
	if (av[1][0] == 'c')
	{
		ft_printf("\n");
		test_c();
		ft_printf("\n");
	}
	if (av[1][0] == 's')
	{
		ft_printf("\n");
		test_s();
		ft_printf("\n");
	}
	if (av[1][0] == 'd')
	{
		ft_printf("\n");
		test_d();
		ft_printf("\n");
	}
	if (av[1][0] == 'i')
	{
		ft_printf("\n");
		test_i();
		ft_printf("\n");
	}
	if (av[1][0] == 'u')
	{
		ft_printf("\n");
		test_u();
		ft_printf("\n");
	}
}
