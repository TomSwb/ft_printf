
#include "ft_printf.h"
#include <stdio.h>

void	test_p(void)
{
	void	*ptr;
	int		result_ft;
	int		result_og;
	int		x;
	int		y;

	ft_printf("Testing '%%p' (pointer address):\n");

	x = 1;
	y = 2;

	// ---------- Basic cases (real addresses + NULL) ----------
	ft_printf("\n--- Basic cases ---\n");

	ptr = NULL;
	result_ft = ft_printf("no flags, ptr = NULL: *%p*\n", ptr);
	result_og = printf("no flags, ptr = NULL: *%p*\n", ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	ptr = (void *)&x;
	result_ft = ft_printf("no flags, ptr = &x: *%p*\n", ptr);
	result_og = printf("no flags, ptr = &x: *%p*\n", ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	ptr = (void *)&y;
	result_ft = ft_printf("no flags, ptr = &y: *%p*\n", ptr);
	result_og = printf("no flags, ptr = &y: *%p*\n", ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Min width only (right justified) ----------
	ft_printf("\n--- Min width only (right justified) ---\n");

	ptr = NULL;
	result_ft = ft_printf("min width 18, ptr = NULL: *%18p*\n", ptr);
	result_og = printf("min width 18, ptr = NULL: *%18p*\n", ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	ptr = (void *)&x;
	result_ft = ft_printf("min width 18, ptr = &x: *%18p*\n", ptr);
	result_og = printf("min width 18, ptr = &x: *%18p*\n", ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	ptr = (void *)&y;
	result_ft = ft_printf("min width 18, ptr = &y: *%18p*\n", ptr);
	result_og = printf("min width 18, ptr = &y: *%18p*\n", ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '-' (left justified) ----------
	ft_printf("\n--- Flag '-' (left justified) ---\n");

	ptr = NULL;
	result_ft = ft_printf("flag '-', min width 18, ptr = NULL: *%-18p*\n", ptr);
	result_og = printf("flag '-', min width 18, ptr = NULL: *%-18p*\n", ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	ptr = (void *)&x;
	result_ft = ft_printf("flag '-', min width 18, ptr = &x: *%-18p*\n", ptr);
	result_og = printf("flag '-', min width 18, ptr = &x: *%-18p*\n", ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	ptr = (void *)&y;
	result_ft = ft_printf("flag '-', min width 18, ptr = &y: *%-18p*\n", ptr);
	result_og = printf("flag '-', min width 18, ptr = &y: *%-18p*\n", ptr);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Multiple pointers in one call ----------
	ft_printf("\n--- Multiple pointers in one call ---\n");

	result_ft = ft_printf("three pointers: %p %p %p\n", (void *)&x, (void *)&y, NULL);
	result_og = printf("three pointers: %p %p %p\n", (void *)&x, (void *)&y, NULL);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("widthed: *%18p* *%18p* *%18p*\n", (void *)&x, (void *)&y, NULL);
	result_og = printf("widthed: *%18p* *%18p* *%18p*\n", (void *)&x, (void *)&y, NULL);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("left-justified: *%-18p* *%-18p* *%-18p*\n", (void *)&x, (void *)&y, NULL);
	result_og = printf("left-justified: *%-18p* *%-18p* *%-18p*\n", (void *)&x, (void *)&y, NULL);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}
