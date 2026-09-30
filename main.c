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

void    test_percentage();
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
}

void	test_percentage()
{
    int		result_ft;
    int		result_og;
    
	ft_printf("Testing '%%':\n");
	result_ft = ft_printf("no flags = *%%*\n");
	result_og = printf("no flags = *%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("non related flags + min width 5 = *%- #+05.1%*\n");
	// result_og = printf("non related flags + min width 5 = *%- #+05.1%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);
}

void	test_c()
{
    int		result_ft;
    int		result_og;
    char	c;
    
	c = 'W';
	ft_printf("Testing 'char c':\n");
	result_ft = ft_printf("no flags = *%c*\n", c);
	result_og = printf("no flags = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("flag '-' + min width 5 = *%-5c*\n", c);
	result_og = printf("flag '-' + min width 5 = *%-5c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("min width 5 = *%5c*\n", c);
	result_og = printf("min width 5 = *%5c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("non related flags + min width 5 = *% #+05.1c*\n", c);
	// result_og = printf("non related flags + min width 5 = *% #+05.1c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);
}

void	test_s()
{
    int		result_ft;
    int		result_og;
    char	*s;
    
	s = "Hello World!";
	ft_printf("Testing 'char *s':\n");
	result_ft = ft_printf("no flags = *%s*\n", s);
	result_og = printf("no flags = *%s*\n", s);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("flag '-' = *%-s*\n", s);
	result_og = printf("flag '-' = *%-s*\n", s);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("flag '-' + min width 5 = *%-5s*\n", s);
	result_og = printf("flag '-' + min width 5 = *%-5s*\n", s);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("min width 5 = *%5s*\n", s);
	result_og = printf("min width 5 = *%5s*\n", s);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	ft_printf("\n");
	
	ft_printf("Testing 'char *s' printing with .precision = 5:\n");
	result_ft = ft_printf("no flags = *%.5s*\n", s);
	result_og = printf("no flags = *%.5s*\n", s);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("flag '-' = *%-.5s*\n", s);
	result_og = printf("flag '-' = *%-.5s*\n", s);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("flag '-' + min width 5 = *%-5.5s*\n", s);
	result_og = printf("flag '-' + min width 5 = *%-5.5s*\n", s);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("min width 5 = *%5.5s*\n", s);
	result_og = printf("min width 5 = *%5.5s*\n", s);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}
