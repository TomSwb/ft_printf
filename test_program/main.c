
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    test_c();
}

void test_c()
{
    int result_ft;
    int result_og;
    char c;
    
    c = 'W';
    ft_printf("Testing 'char c' printing:\n");
    result_ft = ft_printf("no flags = %c\n", c);
    result_og = printf("no flags = %c\n", c);
    ft_printf("result_ft = %d\n", result_ft);
    printf("result_og = %d\n", result_og);
    result_ft = ft_printf("flag '-' = %-c\n", c);
    result_og = printf("flag '-' = %-c\n", c);
    ft_printf("result_ft = %d\n", result_ft);
    printf("result_og = %d\n", result_og);
    result_ft = ft_printf("flag '-' + min width 5 = %-5c\n", c);
    result_og = printf("flag '-' + min width 5 = %-5c\n", c);
    ft_printf("result_ft = %d\n", result_ft);
    printf("result_og = %d\n", result_og);
    result_ft = ft_printf("min width 5 = %5c\n", c);
    result_og = printf("min width 5 = %5c\n", c);
    ft_printf("result_ft = %d\n", result_ft);
    printf("result_og = %d\n", result_og);
}
