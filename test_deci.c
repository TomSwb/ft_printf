
#include "ft_printf.h"

void	test_di(void)
{
	int		result_ft;
	int		result_og;
	int		n;

	ft_printf("Testing '%%d' and '%%i' (signed decimal integer):\n");

	// ---------- Basic cases ----------
	ft_printf("\n--- Basic cases ---\n");

	n = 42;
	result_ft = ft_printf("no flags, n = 42: *%d* *%i*\n", n, n);
	result_og = printf("no flags, n = 42: *%d* *%i*\n", n, n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("no flags, n = -42: *%d* *%i*\n", n, n);
	result_og = printf("no flags, n = -42: *%d* *%i*\n", n, n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("no flags, n = 0: *%d* *%i*\n", n, n);
	result_og = printf("no flags, n = 0: *%d* *%i*\n", n, n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Min width only ----------
	ft_printf("\n--- Min width only (right justified) ---\n");

	n = 42;
	result_ft = ft_printf("min width 5, n = 42: *%5d*\n", n);
	result_og = printf("min width 5, n = 42: *%5d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("min width 5, n = -42: *%5d*\n", n);
	result_og = printf("min width 5, n = -42: *%5d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 123456;
	result_ft = ft_printf("min width 3, n = 123456: *%3d*\n", n);
	result_og = printf("min width 3, n = 123456: *%3d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '-' (left justified) ----------
	ft_printf("\n--- Flag '-' (left justified) ---\n");

	n = 42;
	result_ft = ft_printf("flag '-', min width 5, n = 42: *%-5d*\n", n);
	result_og = printf("flag '-', min width 5, n = 42: *%-5d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag '-', min width 5, n = -42: *%-5d*\n", n);
	result_og = printf("flag '-', min width 5, n = -42: *%-5d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '0' (zero padding) ----------
	ft_printf("\n--- Flag '0' (zero padding) ---\n");

	n = 42;
	result_ft = ft_printf("flag '0', min width 5, n = 42: *%05d*\n", n);
	result_og = printf("flag '0', min width 5, n = 42: *%05d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag '0', min width 5, n = -42: *%05d*\n", n);
	result_og = printf("flag '0', min width 5, n = -42: *%05d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '0', min width 5, n = 0: *%05d*\n", n);
	result_og = printf("flag '0', min width 5, n = 0: *%05d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '-' and '0' together: '-' should win, '0' ignored [40][41][43]
	ft_printf("\n--- Flags '-' and '0' together ('-' wins) ---\n");

	n = 42;
	result_ft = ft_printf("flags '-0', min width 5, n = 42: *%-05d*\n", n);
	result_og = printf("flags '-0', min width 5, n = 42: *%-05d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flags '-0', min width 5, n = -42: *%-05d*\n", n);
	result_og = printf("flags '-0', min width 5, n = -42: *%-05d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '+' (always show sign) ----------
	ft_printf("\n--- Flag '+' (always show sign) ---\n");

	n = 42;
	result_ft = ft_printf("flag '+', n = 42: *%+d*\n", n);
	result_og = printf("flag '+', n = 42: *%+d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag '+', n = -42: *%+d*\n", n);
	result_og = printf("flag '+', n = -42: *%+d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '+', n = 0: *%+d*\n", n);
	result_og = printf("flag '+', n = 0: *%+d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '+' with width
	result_ft = ft_printf("flag '+', min width 5, n = 42: *%+5d*\n", 42);
	result_og = printf("flag '+', min width 5, n = 42: *%+5d*\n", 42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("flag '+', min width 5, n = -42: *%+5d*\n", -42);
	result_og = printf("flag '+', min width 5, n = -42: *%+5d*\n", -42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag ' ' (space instead of + for positives) ----------
	ft_printf("\n--- Flag ' ' (space for positive sign) ---\n");

	n = 42;
	result_ft = ft_printf("flag ' ', n = 42: *% d*\n", n);
	result_og = printf("flag ' ', n = 42: *% d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag ' ', n = -42: *% d*\n", n);
	result_og = printf("flag ' ', n = -42: *% d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag ' ', n = 0: *% d*\n", n);
	result_og = printf("flag ' ', n = 0: *% d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ' ' with width
	result_ft = ft_printf("flag ' ', min width 5, n = 42: *% 5d*\n", 42);
	result_og = printf("flag ' ', min width 5, n = 42: *% 5d*\n", 42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '+' and ' ' together: '+' wins [39][43][46]
	ft_printf("\n--- Flags '+' and ' ' together ('+' wins) ---\n");

	n = 42;
	result_ft = ft_printf("flags '+ ', n = 42: *%+ d*\n", n);
	result_og = printf("flags '+ ', n = 42: *%+ d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flags '+ ', n = -42: *%+ d*\n", n);
	result_og = printf("flags '+ ', n = -42: *%+ d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision '.' (minimum number of digits) ----------
	ft_printf("\n--- Precision '.' (minimum digits) ---\n");

	n = 42;
	result_ft = ft_printf("precision 5, n = 42: *%.5d*\n", n);
	result_og = printf("precision 5, n = 42: *%.5d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("precision 5, n = -42: *%.5d*\n", n);
	result_og = printf("precision 5, n = -42: *%.5d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("precision 1, n = 0: *%.1d*\n", n);
	result_og = printf("precision 1, n = 0: *%.1d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision 0 with value 0: should print nothing (empty) [39][43]
	result_ft = ft_printf("precision 0, n = 0: *%.0d*\n", 0);
	result_og = printf("precision 0, n = 0: *%.0d*\n", 0);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision larger than number
	result_ft = ft_printf("precision 8, n = 7: *%.8d*\n", 7);
	result_og = printf("precision 8, n = 7: *%.8d*\n", 7);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + min width ----------
	ft_printf("\n--- Precision + min width ---\n");

	n = 42;
	result_ft = ft_printf("precision 3 + min width 6, n = 42: *%6.3d*\n", n);
	result_og = printf("precision 3 + min width 6, n = 42: *%6.3d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("precision 3 + min width 6, n = -42: *%6.3d*\n", n);
	result_og = printf("precision 3 + min width 6, n = -42: *%6.3d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("precision 0 + min width 5, n = 0: *%5.0d*\n", 0);
	result_og = printf("precision 0 + min width 5, n = 0: *%5.0d*\n", 0);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + flags ('0' ignored when precision present) [40][41][43] ----------
	ft_printf("\n--- Precision + flag '0' ('0' ignored) ---\n");

	n = 42;
	result_ft = ft_printf("flag '0' + precision 3, n = 42: *%0.3d*\n", n);
	result_og = printf("flag '0' + precision 3, n = 42: *%0.3d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag '0' + precision 3, n = -42: *%0.3d*\n", n);
	result_og = printf("flag '0' + precision 3, n = -42: *%0.3d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- All together: flags, width, precision ----------
	ft_printf("\n--- Combined flags, width, precision ---\n");

	n = 42;
	result_ft = ft_printf("'+', width 8, precision 4, n = 42: *%+8.4d*\n", n);
	result_og = printf("'+', width 8, precision 4, n = 42: *%+8.4d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("'+', width 8, precision 4, n = -42: *%+8.4d*\n", n);
	result_og = printf("'+', width 8, precision 4, n = -42: *%+8.4d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 42;
	result_ft = ft_printf("'-' + '+', width 8, precision 4, n = 42: *%-+8.4d*\n", n);
	result_og = printf("'-' + '+', width 8, precision 4, n = 42: *%-+8.4d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("'-' + '+', width 8, precision 4, n = -42: *%-+8.4d*\n", n);
	result_og = printf("'-' + '+', width 8, precision 4, n = -42: *%-+8.4d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Edge values (INT_MIN / INT_MAX if you want) ----------
	ft_printf("\n--- Edge values (optional, adjust to your system) ---\n");

	// If you have <limits.h>, you can replace these with INT_MIN / INT_MAX
	result_ft = ft_printf("INT_MIN-ish: *%d*\n", -2147483648);
	result_og = printf("INT_MIN-ish: *%d*\n", -2147483648);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("INT_MAX-ish: *%d*\n", 2147483647);
	result_og = printf("INT_MAX-ish: *%d*\n", 2147483647);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}
