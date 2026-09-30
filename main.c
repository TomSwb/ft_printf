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

void	test_percentage();
void	test_c();
void	test_s();

int	main(void)
{
	ft_printf("\n");
	ft_printf("control, string ending with arg symbol: %");
	ft_printf("\n");
	ft_printf("\n");
	test_percentage();
	ft_printf("\n");
	test_c();
	ft_printf("\n");
	test_s();
	ft_printf("\n");
    test_d();
    ft_printf("\n");
    test_i();
    ft_printf("\n");
    test_u();
    ft_printf("\n");
}
