
#include "ft_printf.h"
#include <stdio.h>

void	test_p(void)
{
	int		result_ft;
	int		result_og;
	int		n;
	int		*ptr;
	int		*null_ptr;
	char	*str;
	void	*generic_ptr;

	ft_printf("Testing '%%p' (pointer):\n");

	/* ---------- Basic pointer ---------- */

	n = 42;
	ptr = &n;

	ft_printf("\n--- Basic pointer ---\n");

	result_ft = ft_printf("ft_printf, &n:      *%p*\n", (void *)ptr);
	result_og = printf("printf,    &n:      *%p*\n", (void *)ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	/* ---------- Different variable types ---------- */

	str = "hello";
	generic_ptr = (void *)str;

	ft_printf("\n--- Different pointer types ---\n");

	result_ft = ft_printf("pointer to int:      *%p*\n", (void *)&n);
	result_og = printf("pointer to int:      *%p*\n", (void *)&n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("pointer to string:   *%p*\n", (void *)str);
	result_og = printf("pointer to string:   *%p*\n", (void *)str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("void pointer:        *%p*\n", generic_ptr);
	result_og = printf("void pointer:        *%p*\n", generic_ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	/* ---------- Same address multiple times ---------- */

	ft_printf("\n--- Same address multiple times ---\n");

	result_ft = ft_printf("same pointer: *%p* *%p* *%p*\n",
			(void *)ptr, (void *)ptr, (void *)ptr);
	result_og = printf("same pointer: *%p* *%p* *%p*\n",
			(void *)ptr, (void *)ptr, (void *)ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	/* ---------- Different real addresses ---------- */

	{
		int		a;
		int		b;
		char	c;

		a = 1;
		b = 2;
		c = 'x';

		ft_printf("\n--- Different real addresses ---\n");

		result_ft = ft_printf("&a: *%p*, &b: *%p*, &c: *%p*\n",
				(void *)&a, (void *)&b, (void *)&c);
		result_og = printf("&a: *%p*, &b: *%p*, &c: *%p*\n",
				(void *)&a, (void *)&b, (void *)&c);
		ft_printf("result_ft = %d\n", result_ft);
		printf("result_og = %d\n", result_og);
	}

	/* ---------- NULL pointer ---------- */

	null_ptr = NULL;

	ft_printf("\n--- NULL pointer ---\n");

	result_ft = ft_printf("NULL pointer: *%p*\n", (void *)null_ptr);
	result_og = printf("NULL pointer: *%p*\n", (void *)null_ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("NULL directly: *%p*\n", (void *)NULL);
	result_og = printf("NULL directly: *%p*\n", (void *)NULL);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	/* ---------- Pointer beside normal text ---------- */

	ft_printf("\n--- Pointer beside normal text ---\n");

	result_ft = ft_printf("before [%p] after\n", (void *)&n);
	result_og = printf("before [%p] after\n", (void *)&n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	/* ---------- Several conversions together ---------- */

	ft_printf("\n--- Several conversions ---\n");

	result_ft = ft_printf("int = %d, string = %s, pointer = %p, char = %c\n",
			n, str, (void *)&n, 'A');
	result_og = printf("int = %d, string = %s, pointer = %p, char = %c\n",
			n, str, (void *)&n, 'A');
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	/* ---------- Pointer with %% ---------- */

	ft_printf("\n--- Pointer with %% ---\n");

	result_ft = ft_printf("pointer = %p, percent = %%\n", (void *)&n);
	result_og = printf("pointer = %p, percent = %%\n", (void *)&n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}
