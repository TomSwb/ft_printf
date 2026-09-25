
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    ft_printf();
    
    printf();
}

void test_c()
{
    int result_ft;
    int result_og;
    char c;
    
    c = 'W';
    result_ft = ft_printf("no flags = %c\n", c);
    ft_printf("%d\n", result_ft);
    result_og = printf("no flags = %c\n", c);
    printf("%d\n", result_og);
}
