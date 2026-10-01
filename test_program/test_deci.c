#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	print_results(int result_ft, int result_og)
{
	ft_printf("return ft_printf = %d\n", result_ft);
	printf("return printf     = %d\n", result_og);
	if (result_ft == result_og)
		ft_printf("RETURN VALUES: OK\n");
	else
		ft_printf("RETURN VALUES: DIFFERENT\n");
}

/*
** ---------------------------------------------------------------------------
** %d tests
** ---------------------------------------------------------------------------
*/

void	test_d(void)
{
	int	result_ft;
	int	result_og;

	ft_printf("\n========================================\n");
	ft_printf("TESTING %%d\n");
	ft_printf("========================================\n");

	ft_printf("\n--- Basic values ---\n");

	result_ft = ft_printf("zero:             *%d*\n", 0);
	result_og = printf("zero:             *%d*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("one:              *%d*\n", 1);
	result_og = printf("one:              *%d*\n", 1);
	print_results(result_ft, result_og);

	result_ft = ft_printf("minus one:        *%d*\n", -1);
	result_og = printf("minus one:        *%d*\n", -1);
	print_results(result_ft, result_og);

	result_ft = ft_printf("positive:          *%d*\n", 42);
	result_og = printf("positive:          *%d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("negative:          *%d*\n", -42);
	result_og = printf("negative:          *%d*\n", -42);
	print_results(result_ft, result_og);

	ft_printf("\n--- Integer boundaries ---\n");

	result_ft = ft_printf("INT_MIN:           *%d*\n", INT_MIN);
	result_og = printf("INT_MIN:           *%d*\n", INT_MIN);
	print_results(result_ft, result_og);

	result_ft = ft_printf("INT_MAX:           *%d*\n", INT_MAX);
	result_og = printf("INT_MAX:           *%d*\n", INT_MAX);
	print_results(result_ft, result_og);

	result_ft = ft_printf("INT_MIN + 1:       *%d*\n", INT_MIN + 1);
	result_og = printf("INT_MIN + 1:       *%d*\n", INT_MIN + 1);
	print_results(result_ft, result_og);

	result_ft = ft_printf("INT_MAX - 1:       *%d*\n", INT_MAX - 1);
	result_og = printf("INT_MAX - 1:       *%d*\n", INT_MAX - 1);
	print_results(result_ft, result_og);

	ft_printf("\n--- Width ---\n");

	result_ft = ft_printf("width 1:           *%1d*\n", 42);
	result_og = printf("width 1:           *%1d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 5:           *%5d*\n", 42);
	result_og = printf("width 5:           *%5d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 5 negative:  *%5d*\n", -42);
	result_og = printf("width 5 negative:  *%5d*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 10:          *%10d*\n", 123456);
	result_og = printf("width 10:          *%10d*\n", 123456);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width too small:   *%3d*\n", 123456);
	result_og = printf("width too small:   *%3d*\n", 123456);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width zero value:  *%5d*\n", 0);
	result_og = printf("width zero value:  *%5d*\n", 0);
	print_results(result_ft, result_og);

	ft_printf("\n--- Minus flag ---\n");

	result_ft = ft_printf("left width 5:      *%-5d*\n", 42);
	result_og = printf("left width 5:      *%-5d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("left negative:     *%-5d*\n", -42);
	result_og = printf("left negative:     *%-5d*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("left zero:         *%-5d*\n", 0);
	result_og = printf("left zero:         *%-5d*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("left width small:  *%-2d*\n", 123456);
	result_og = printf("left width small:  *%-2d*\n", 123456);
	print_results(result_ft, result_og);

	ft_printf("\n--- Zero flag ---\n");

	result_ft = ft_printf("zero width 5:      *%05d*\n", 42);
	result_og = printf("zero width 5:      *%05d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero negative:     *%05d*\n", -42);
	result_og = printf("zero negative:     *%05d*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero zero:         *%05d*\n", 0);
	result_og = printf("zero zero:         *%05d*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero INT_MIN:      *%020d*\n", INT_MIN);
	result_og = printf("zero INT_MIN:      *%020d*\n", INT_MIN);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero INT_MAX:      *%020d*\n", INT_MAX);
	result_og = printf("zero INT_MAX:      *%020d*\n", INT_MAX);
	print_results(result_ft, result_og);

	ft_printf("\n--- Conflicting '-' and '0' flags ---\n");

	result_ft = ft_printf("minus and zero:    *%-05d*\n", 42);
	// result_og = printf("minus and zero:    *%-05d*\n", 42);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("minus zero neg:    *%-05d*\n", -42);
	// result_og = printf("minus zero neg:    *%-05d*\n", -42);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("minus zero zero:   *%-05d*\n", 0);
	// result_og = printf("minus zero zero:   *%-05d*\n", 0);
	// print_results(result_ft, result_og);

	ft_printf("\n--- Plus flag ---\n");

	result_ft = ft_printf("plus positive:     *%+d*\n", 42);
	result_og = printf("plus positive:     *%+d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("plus negative:     *%+d*\n", -42);
	result_og = printf("plus negative:     *%+d*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("plus zero:         *%+d*\n", 0);
	result_og = printf("plus zero:         *%+d*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("plus width:        *%+8d*\n", 42);
	result_og = printf("plus width:        *%+8d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("plus neg width:    *%+8d*\n", -42);
	result_og = printf("plus neg width:    *%+8d*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("plus zero width:   *%+8d*\n", 0);
	result_og = printf("plus zero width:   *%+8d*\n", 0);
	print_results(result_ft, result_og);

	ft_printf("\n--- Space flag ---\n");

	result_ft = ft_printf("space positive:    *% d*\n", 42);
	result_og = printf("space positive:    *% d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("space negative:    *% d*\n", -42);
	result_og = printf("space negative:    *% d*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("space zero:        *% d*\n", 0);
	result_og = printf("space zero:        *% d*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("space width:       *% 8d*\n", 42);
	result_og = printf("space width:       *% 8d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("space neg width:   *% 8d*\n", -42);
	result_og = printf("space neg width:   *% 8d*\n", -42);
	print_results(result_ft, result_og);

	ft_printf("\n--- Plus and space together ---\n");

	result_ft = ft_printf("plus space:        *%+ d*\n", 42);
	// result_og = printf("plus space:        *%+ d*\n", 42);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("plus space neg:    *%+ d*\n", -42);
	// result_og = printf("plus space neg:    *%+ d*\n", -42);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("plus width space:  *%+ 8d*\n", 42);
	// result_og = printf("plus width space:  *%+ 8d*\n", 42);
	// print_results(result_ft, result_og);

	ft_printf("\n--- Precision ---\n");

	result_ft = ft_printf("precision 0:       *%.0d*\n", 42);
	result_og = printf("precision 0:       *%.0d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision 1:       *%.1d*\n", 42);
	result_og = printf("precision 1:       *%.1d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision 2:       *%.2d*\n", 42);
	result_og = printf("precision 2:       *%.2d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision 5:       *%.5d*\n", 42);
	result_og = printf("precision 5:       *%.5d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision neg:     *%.5d*\n", -42);
	result_og = printf("precision neg:     *%.5d*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision zero:    *%.5d*\n", 0);
	result_og = printf("precision zero:    *%.5d*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision zero 0:  *%.0d*\n", 0);
	result_og = printf("precision zero 0:  *%.0d*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision large:   *%.20d*\n", 123);
	result_og = printf("precision large:   *%.20d*\n", 123);
	print_results(result_ft, result_og);

	ft_printf("\n--- Width and precision ---\n");

	result_ft = ft_printf("width 8 prec 3:    *%8.3d*\n", 42);
	result_og = printf("width 8 prec 3:    *%8.3d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 8 prec 3 neg:*%8.3d*\n", -42);
	result_og = printf("width 8 prec 3 neg:*%8.3d*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 8 prec 0:    *%8.0d*\n", 0);
	result_og = printf("width 8 prec 0:    *%8.0d*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 3 prec 8:    *%3.8d*\n", 42);
	result_og = printf("width 3 prec 8:    *%3.8d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("plus width prec:   *%+8.5d*\n", 42);
	result_og = printf("plus width prec:   *%+8.5d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("minus width prec:  *%-8.5d*\n", 42);
	result_og = printf("minus width prec:  *%-8.5d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("space width prec:  *% 8.5d*\n", 42);
	result_og = printf("space width prec:  *% 8.5d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero width prec:   *%08.5d*\n", 42);
	// result_og = printf("zero width prec:   *%08.5d*\n", 42);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("minus plus prec:   *%-+8.5d*\n", 42);
	result_og = printf("minus plus prec:   *%-+8.5d*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("minus plus neg:    *%-+8.5d*\n", -42);
	result_og = printf("minus plus neg:    *%-+8.5d*\n", -42);
	print_results(result_ft, result_og);

	ft_printf("\n--- Repeated flags ---\n");

	result_ft = ft_printf("repeated minus:    *%--5d*\n", 42);
	ft_printf("result_ft = %d\n", result_ft);
	// result_og = printf("repeated minus:    *%--5d*\n", 42);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("repeated zero:     *%005d*\n", 42);
	ft_printf("result_ft = %d\n", result_ft);
	// result_og = printf("repeated zero:     *%005d*\n", 42);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("repeated plus:     *%++d*\n", 42);
	ft_printf("result_ft = %d\n", result_ft);
	// result_og = printf("repeated plus:     *%++d*\n", 42);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("all flags:         *%-+ 05d*\n", 42);
	ft_printf("result_ft = %d\n", result_ft);
	// result_og = printf("all flags:         *%-+ 05d*\n", 42);
	// print_results(result_ft, result_og);

	ft_printf("\n--- Embedded conversions ---\n");

	result_ft = ft_printf("before %d after\n", 42);
	result_og = printf("before %d after\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("%d%d%d\n", 1, 2, 3);
	result_og = printf("%d%d%d\n", 1, 2, 3);
	print_results(result_ft, result_og);

	result_ft = ft_printf("[%d][%d][%d]\n", INT_MIN, 0, INT_MAX);
	result_og = printf("[%d][%d][%d]\n", INT_MIN, 0, INT_MAX);
	print_results(result_ft, result_og);

	result_ft = ft_printf("percent: %% and number: %d\n", 42);
	result_og = printf("percent: %% and number: %d\n", 42);
	print_results(result_ft, result_og);
}

/*
** ---------------------------------------------------------------------------
** %i tests
** ---------------------------------------------------------------------------
**
** The test cases are intentionally similar to %d.
*/

void	test_i(void)
{
	int	result_ft;
	int	result_og;

	ft_printf("\n========================================\n");
	ft_printf("TESTING %%i\n");
	ft_printf("========================================\n");

	ft_printf("\n--- Basic and boundary values ---\n");

	result_ft = ft_printf("zero:             *%i*\n", 0);
	result_og = printf("zero:             *%i*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("one:              *%i*\n", 1);
	result_og = printf("one:              *%i*\n", 1);
	print_results(result_ft, result_og);

	result_ft = ft_printf("minus one:        *%i*\n", -1);
	result_og = printf("minus one:        *%i*\n", -1);
	print_results(result_ft, result_og);

	result_ft = ft_printf("INT_MIN:           *%i*\n", INT_MIN);
	result_og = printf("INT_MIN:           *%i*\n", INT_MIN);
	print_results(result_ft, result_og);

	result_ft = ft_printf("INT_MAX:           *%i*\n", INT_MAX);
	result_og = printf("INT_MAX:           *%i*\n", INT_MAX);
	print_results(result_ft, result_og);

	ft_printf("\n--- Width and alignment ---\n");

	result_ft = ft_printf("width 5:           *%5i*\n", 42);
	result_og = printf("width 5:           *%5i*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("left width 5:      *%-5i*\n", 42);
	result_og = printf("left width 5:      *%-5i*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero width 5:      *%05i*\n", 42);
	result_og = printf("zero width 5:      *%05i*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("negative width:     *%5i*\n", -42);
	result_og = printf("negative width:     *%5i*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("negative zero:      *%05i*\n", -42);
	result_og = printf("negative zero:      *%05i*\n", -42);
	print_results(result_ft, result_og);

	ft_printf("\n--- Signs ---\n");

	result_ft = ft_printf("plus positive:      *%+i*\n", 42);
	result_og = printf("plus positive:      *%+i*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("plus negative:      *%+i*\n", -42);
	result_og = printf("plus negative:      *%+i*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("plus zero:          *%+i*\n", 0);
	result_og = printf("plus zero:          *%+i*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("space positive:     *% i*\n", 42);
	result_og = printf("space positive:     *% i*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("space negative:     *% i*\n", -42);
	result_og = printf("space negative:     *% i*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("plus space:         *%+ i*\n", 42);
	// result_og = printf("plus space:         *%+ i*\n", 42);
	// print_results(result_ft, result_og);

	ft_printf("\n--- Precision ---\n");

	result_ft = ft_printf("precision 3:        *%.3i*\n", 42);
	result_og = printf("precision 3:        *%.3i*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision negative:  *%.5i*\n", -42);
	result_og = printf("precision negative:  *%.5i*\n", -42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision zero:      *%.5i*\n", 0);
	result_og = printf("precision zero:      *%.5i*\n", 0);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision zero-zero: *%.0i*\n", 0);
	result_og = printf("precision zero-zero: *%.0i*\n", 0);
	print_results(result_ft, result_og);

	ft_printf("\n--- Combined options ---\n");

	result_ft = ft_printf("plus width precision:*%+8.5i*\n", 42);
	result_og = printf("plus width precision:*%+8.5i*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("minus width precision:*%-8.5i*\n", 42);
	result_og = printf("minus width precision:*%-8.5i*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero width precision: *%08.5i*\n", 42);
	// result_og = printf("zero width precision: *%08.5i*\n", 42);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("space width precision:*% 8.5i*\n", 42);
	result_og = printf("space width precision:*% 8.5i*\n", 42);
	print_results(result_ft, result_og);

	result_ft = ft_printf("minus plus precision: *%-+8.5i*\n", -42);
	result_og = printf("minus plus precision: *%-+8.5i*\n", -42);
	print_results(result_ft, result_og);

	ft_printf("\n--- Multiple conversions ---\n");

	result_ft = ft_printf("[%i][%i][%i]\n", INT_MIN, 0, INT_MAX);
	result_og = printf("[%i][%i][%i]\n", INT_MIN, 0, INT_MAX);
	print_results(result_ft, result_og);

	result_ft = ft_printf("%i%i%i%i\n", -1, 0, 1, 42);
	result_og = printf("%i%i%i%i\n", -1, 0, 1, 42);
	print_results(result_ft, result_og);
}

/*
** ---------------------------------------------------------------------------
** %u tests
** ---------------------------------------------------------------------------
*/

void	test_u(void)
{
	unsigned int	values[] = {
		0u,
		1u,
		2u,
		9u,
		10u,
		42u,
		99u,
		100u,
		255u,
		256u,
		1000u,
		2147483647u,
		2147483648u,
		4294967294u,
		4294967295u
	};
	size_t	i;
	int		result_ft;
	int		result_og;

	ft_printf("\n========================================\n");
	ft_printf("TESTING %%u\n");
	ft_printf("========================================\n");

	ft_printf("\n--- Basic and boundary values ---\n");

	i = 0;
	while (i < sizeof(values) / sizeof(values[0]))
	{
		result_ft = ft_printf("value: *%u*\n", values[i]);
		result_og = printf("value: *%u*\n", values[i]);
		print_results(result_ft, result_og);
		i++;
	}

	ft_printf("\n--- Width ---\n");

	result_ft = ft_printf("width 1:           *%1u*\n", 42u);
	result_og = printf("width 1:           *%1u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 5:           *%5u*\n", 42u);
	result_og = printf("width 5:           *%5u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width zero:        *%5u*\n", 0u);
	result_og = printf("width zero:        *%5u*\n", 0u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width too small:   *%3u*\n", 123456u);
	result_og = printf("width too small:   *%3u*\n", 123456u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width UINT_MAX:    *%15u*\n", UINT_MAX);
	result_og = printf("width UINT_MAX:    *%15u*\n", UINT_MAX);
	print_results(result_ft, result_og);

	ft_printf("\n--- Minus flag ---\n");

	result_ft = ft_printf("left width 5:      *%-5u*\n", 42u);
	result_og = printf("left width 5:      *%-5u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("left zero:         *%-5u*\n", 0u);
	result_og = printf("left zero:         *%-5u*\n", 0u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("left UINT_MAX:     *%-15u*\n", UINT_MAX);
	result_og = printf("left UINT_MAX:     *%-15u*\n", UINT_MAX);
	print_results(result_ft, result_og);

	ft_printf("\n--- Zero flag ---\n");

	result_ft = ft_printf("zero width 5:      *%05u*\n", 42u);
	result_og = printf("zero width 5:      *%05u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero value zero:   *%05u*\n", 0u);
	result_og = printf("zero value zero:   *%05u*\n", 0u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero UINT_MAX:     *%015u*\n", UINT_MAX);
	result_og = printf("zero UINT_MAX:     *%015u*\n", UINT_MAX);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero high bit:     *%010u*\n", 2147483648u);
	result_og = printf("zero high bit:     *%010u*\n", 2147483648u);
	print_results(result_ft, result_og);

	ft_printf("\n--- Conflicting '-' and '0' flags ---\n");

	result_ft = ft_printf("minus and zero:    *%-05u*\n", 42u);
	// result_og = printf("minus and zero:    *%-05u*\n", 42u);
	// print_results(result_ft, result_og);
 
	result_ft = ft_printf("minus zero value:  *%-05u*\n", 0u);
	// result_og = printf("minus zero value:  *%-05u*\n", 0u);
	// print_results(result_ft, result_og);

	ft_printf("\n--- Precision ---\n");

	result_ft = ft_printf("precision 0:       *%.0u*\n", 42u);
	result_og = printf("precision 0:       *%.0u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision 1:       *%.1u*\n", 42u);
	result_og = printf("precision 1:       *%.1u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision 5:       *%.5u*\n", 42u);
	result_og = printf("precision 5:       *%.5u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision zero:    *%.5u*\n", 0u);
	result_og = printf("precision zero:    *%.5u*\n", 0u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision zero-zero:*%.0u*\n", 0u);
	result_og = printf("precision zero-zero:*%.0u*\n", 0u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("precision UINT_MAX: *%.15u*\n", UINT_MAX);
	result_og = printf("precision UINT_MAX: *%.15u*\n", UINT_MAX);
	print_results(result_ft, result_og);

	ft_printf("\n--- Width and precision ---\n");

	result_ft = ft_printf("width 8 prec 3:    *%8.3u*\n", 42u);
	result_og = printf("width 8 prec 3:    *%8.3u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 8 prec 3 zero:*%8.3u*\n", 0u);
	result_og = printf("width 8 prec 3 zero:*%8.3u*\n", 0u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 3 prec 8:    *%3.8u*\n", 42u);
	result_og = printf("width 3 prec 8:    *%3.8u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("width 8 prec 0:    *%8.0u*\n", 0u);
	result_og = printf("width 8 prec 0:    *%8.0u*\n", 0u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("left width prec:   *%-8.5u*\n", 42u);
	result_og = printf("left width prec:   *%-8.5u*\n", 42u);
	print_results(result_ft, result_og);

	result_ft = ft_printf("zero width prec:   *%08.5u*\n", 42u);
	// result_og = printf("zero width prec:   *%08.5u*\n", 42u);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("large width prec:  *%20.15u*\n", UINT_MAX);
	result_og = printf("large width prec:  *%20.15u*\n", UINT_MAX);
	print_results(result_ft, result_og);

	ft_printf("\n--- Repeated and combined flags ---\n");

	result_ft = ft_printf("repeated minus:    *%--5u*\n", 42u);
	// result_og = printf("repeated minus:    *%--5u*\n", 42u);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("repeated zero:     *%005u*\n", 42u);
	// result_og = printf("repeated zero:     *%005u*\n", 42u);
	// print_results(result_ft, result_og);

	result_ft = ft_printf("all supported:     *%-0 5u*\n", 42u);
	// result_og = printf("all supported:     *%-0 5u*\n", 42u);
	// print_results(result_ft, result_og);

	ft_printf("\n--- Multiple conversions ---\n");

	result_ft = ft_printf("[%u][%u][%u]\n", 0u, 42u, UINT_MAX);
	result_og = printf("[%u][%u][%u]\n", 0u, 42u, UINT_MAX);
	print_results(result_ft, result_og);

	result_ft = ft_printf("%u%u%u%u\n", 0u, 1u, 2147483648u, UINT_MAX);
	result_og = printf("%u%u%u%u\n", 0u, 1u, 2147483648u, UINT_MAX);
	print_results(result_ft, result_og);

	result_ft = ft_printf("before %u after\n", UINT_MAX);
	result_og = printf("before %u after\n", UINT_MAX);
	print_results(result_ft, result_og);
}
