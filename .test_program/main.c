/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:54:22 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/12 16:51:09 by tschwab          ###   ########.fr       */
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
void	test_x(void);
void	test_X(void);
void	test_p(void);

int main(void)
{
	ft_printf("test u %x\n", -42);
	printf("test u %x", -42);
}

/*
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
	if (av[1][0] == 'x')
	{
		ft_printf("\n");
		test_x();
		ft_printf("\n");
	}
	if (av[1][0] == 'X')
	{
		ft_printf("\n");
		test_X();
		ft_printf("\n");
	}
	if (av[1][0] == 'p')
	{
		ft_printf("\n");
		test_p();
		ft_printf("\n");
	}
}
	*/
