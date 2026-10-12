#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

/*
** Extra edge cases from the review session.
** The format is passed as a variable, so the compiler cannot check it:
** this file compiles with -Wall -Wextra -Werror even with repeated or
** conflicting flags (a literal "%--5d" would not).
** printf is buffered and ft_printf is not, hence the fflush after printf.
*/

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static void	print_results(int result_ft, int result_og);
static void	cmp_int(const char *fmt, int n);
static void	cmp_uint(const char *fmt, unsigned int n);
static void	cmp_str(const char *fmt, char *s);
static void	cmp_ptr(const char *fmt, void *p);

void	test_review(void)
{
	int	x;

	printf("\n--- 1. Flag combinations: accepted, winner rule ---\n\n");
	cmp_int("%-05d", 42);
	cmp_int("%+ d", 42);
	cmp_int("% +d", 42);
	cmp_int("%--5d", 1);
	cmp_int("%00d", 1);
	cmp_uint("%##x", 1);
	cmp_int("%-010d", -7);
	cmp_int("%- d", 7);
	cmp_int("%-+5d", 7);
	cmp_int("%08.5d", 42);

	printf("\n--- 2. Flag on a conversion it does not apply to ---\n\n");
	cmp_uint("%+u", 1);
	cmp_uint("% u", 1);
	cmp_int("%#d", 1);
	cmp_uint("%+x", 1);

	printf("\n--- 3. Hexadecimal with value 0 ---\n\n");
	cmp_uint("%x", 0);
	cmp_uint("%5x", 0);
	cmp_uint("%-5x", 0);
	cmp_uint("%05x", 0);
	cmp_uint("%0x", 0);
	cmp_uint("%.3x", 0);
	cmp_uint("%5.3x", 0);
	cmp_uint("%.0x", 0);
	cmp_uint("%5.0x", 0);
	cmp_uint("%#x", 0);
	cmp_uint("%#5x", 0);
	cmp_uint("%#-5x", 0);
	cmp_uint("%#05x", 0);
	cmp_uint("%#.0x", 0);
	cmp_uint("%0X", 0);

	printf("\n--- 4. Decimal with value 0: precision vs no precision ---\n\n");
	cmp_int("%d", 0);
	cmp_int("%.0d", 0);
	cmp_int("%.d", 0);
	cmp_int("%5.0d", 0);
	cmp_uint("%.0u", 0);

	printf("\n--- 5. NULL string and NULL pointer ---\n\n");
	cmp_str("%s", NULL);
	cmp_str("%10s", NULL);
	cmp_str("%-10s", NULL);
	cmp_str("%.3s", NULL);
	cmp_str("%10.3s", NULL);
	cmp_str("%.8s", NULL);
	cmp_str("%12.8s", NULL);
	cmp_str("%1.8s", NULL);
	cmp_ptr("%p", NULL);
	cmp_ptr("%5p", NULL);
	cmp_ptr("%-20p", &x);

	printf("\n--- 6. INT_MIN / limits ---\n\n");
	cmp_int("%d", INT_MIN);
	cmp_int("%010d", INT_MIN);
	cmp_int("%.15d", INT_MIN);
	cmp_int("%+d", INT_MAX);
	cmp_uint("%u", UINT_MAX);
	cmp_uint("%#X", UINT_MAX);
}

static void	print_results(int result_ft, int result_og)
{
	printf("result_ft = %d | result_og = %d", result_ft, result_og);
	if (result_ft == result_og)
		printf(GREEN"   OK\n\n" RESET);
	else
		printf(RED"   KO <------\n\n" RESET);
	fflush(stdout);
}

static void	cmp_int(const char *fmt, int n)
{
	int	result_ft;
	int	result_og;

	printf("%-10s n = %d\n", fmt, n);
	fflush(stdout);
	ft_printf("ft: *");
	result_ft = ft_printf(fmt, n);
	ft_printf("*\n");
	printf("og: *");
	result_og = printf(fmt, n);
	printf("*\n");
	fflush(stdout);
	print_results(result_ft, result_og);
}

static void	cmp_uint(const char *fmt, unsigned int n)
{
	int	result_ft;
	int	result_og;

	printf("%-10s n = %u\n", fmt, n);
	fflush(stdout);
	ft_printf("ft: *");
	result_ft = ft_printf(fmt, n);
	ft_printf("*\n");
	printf("og: *");
	result_og = printf(fmt, n);
	printf("*\n");
	fflush(stdout);
	print_results(result_ft, result_og);
}

static void	cmp_str(const char *fmt, char *s)
{
	int	result_ft;
	int	result_og;

	if (s)
		printf("%-10s s = \"%s\"\n", fmt, s);
	else
		printf("%-10s s = NULL\n", fmt);
	fflush(stdout);
	ft_printf("ft: *");
	result_ft = ft_printf(fmt, s);
	ft_printf("*\n");
	printf("og: *");
	result_og = printf(fmt, s);
	printf("*\n");
	fflush(stdout);
	print_results(result_ft, result_og);
}

static void	cmp_ptr(const char *fmt, void *p)
{
	int	result_ft;
	int	result_og;

	printf("%-10s p = %s\n", fmt, p ? "address" : "NULL");
	fflush(stdout);
	ft_printf("ft: *");
	result_ft = ft_printf(fmt, p);
	ft_printf("*\n");
	printf("og: *");
	result_og = printf(fmt, p);
	printf("*\n");
	fflush(stdout);
	print_results(result_ft, result_og);
}
