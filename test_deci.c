
#include "ft_printf.h"

void	test_d()
{
    int		result_ft;
    int		result_og;
    int  d;
    
	d = 42;
	ft_printf("Testing 'int d':\n");
	result_ft = ft_printf("no flags = *%d*\n", d);
	result_og = printf("no flags = *%d*\n", d);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("flag '-' = *%-d*\n", d);
	result_og = printf("flag '-' = *%-d*\n", d);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("flag '-' + min width 5 = *%-5d*\n", d);
	result_og = printf("flag '-' + min width 5 = *%-5d*\n", d);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
	result_ft = ft_printf("min width 5 = *%5d*\n", d);
	result_og = printf("min width 5 = *%ds*\n", d);
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