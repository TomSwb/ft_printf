
#include "ft_printf.h"
#include <stdio.h>

void	test_d(void)
{
	int		result_ft;
	int		result_og;
	int		n;

	ft_printf("Testing '%%d' (signed decimal integer):\n");

	// ---------- Basic cases ----------
	ft_printf("\n--- Basic cases ---\n");

	n = 42;
	result_ft = ft_printf("no flags, n = 42: *%d*\n", n);
	result_og = printf("no flags, n = 42: *%d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("no flags, n = -42: *%d*\n", n);
	result_og = printf("no flags, n = -42: *%d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("no flags, n = 0: *%d*\n", n);
	result_og = printf("no flags, n = 0: *%d*\n", n);
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

	// '-' and '0' together: '-' should win, '0' ignored
	ft_printf("\n--- Flags '-0' ('-' wins, '0' ignored) ---\n");

	n = 42;
	result_ft = ft_printf("flags '-0', min width 5, n = 42: *%-05d*\n", n);
	// result_og = printf("flags '-0', min width 5, n = 42: *%-05d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flags '-0', min width 5, n = -42: *%-05d*\n", n);
	// result_og = printf("flags '-0', min width 5, n = -42: *%-05d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

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

	result_ft = ft_printf("flag ' ', min width 5, n = 42: *% 5d*\n", 42);
	result_og = printf("flag ' ', min width 5, n = 42: *% 5d*\n", 42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '+' and ' ' together: '+' wins
	ft_printf("\n--- Flags '+ ' ('+' wins) ---\n");

	n = 42;
	result_ft = ft_printf("flags '+ ', n = 42: *%+ d*\n", n);
	// result_og = printf("flags '+ ', n = 42: *%+ d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flags '+ ', n = -42: *%+ d*\n", n);
	// result_og = printf("flags '+ ', n = -42: *%+ d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

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

	// precision 0 with value 0: should print nothing (empty)
	result_ft = ft_printf("precision 0, n = 0: *%.0d*\n", 0);
	result_og = printf("precision 0, n = 0: *%.0d*\n", 0);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

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

	// ---------- Precision + flag '0' ('0' ignored when precision present) ----------
	ft_printf("\n--- Precision + flag '0' ('0' ignored) ---\n");

	n = 42;
	result_ft = ft_printf("flag '0' + precision 3, n = 42: *%0.3d*\n", n);
	// result_og = printf("flag '0' + precision 3, n = 42: *%0.3d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag '0' + precision 3, n = -42: *%0.3d*\n", n);
	// result_og = printf("flag '0' + precision 3, n = -42: *%0.3d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Combined flags, width, precision ----------
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
	result_ft = ft_printf("'-+', width 8, precision 4, n = 42: *%-+8.4d*\n", n);
	result_og = printf("'-+', width 8, precision 4, n = 42: *%-+8.4d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("'-+', width 8, precision 4, n = -42: *%-+8.4d*\n", n);
	result_og = printf("'-+', width 8, precision 4, n = -42: *%-+8.4d*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Edge values ----------
	ft_printf("\n--- Edge values ---\n");

	result_ft = ft_printf("INT_MIN-ish: *%d*\n", -2147483648);
	// result_og = printf("INT_MIN-ish: *%d*\n", -2147483648);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	result_ft = ft_printf("INT_MAX-ish: *%d*\n", 2147483647);
	result_og = printf("INT_MAX-ish: *%d*\n", 2147483647);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}

void	test_i(void)
{
	int		result_ft;
	int		result_og;
	int		n;

	ft_printf("Testing '%%i' (signed integer):\n");

	// ---------- Basic cases ----------
	ft_printf("\n--- Basic cases ---\n");

	n = 42;
	result_ft = ft_printf("no flags, n = 42: *%i*\n", n);
	result_og = printf("no flags, n = 42: *%i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("no flags, n = -42: *%i*\n", n);
	result_og = printf("no flags, n = -42: *%i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("no flags, n = 0: *%i*\n", n);
	result_og = printf("no flags, n = 0: *%i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Min width only ----------
	ft_printf("\n--- Min width only (right justified) ---\n");

	n = 42;
	result_ft = ft_printf("min width 5, n = 42: *%5i*\n", n);
	result_og = printf("min width 5, n = 42: *%5i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("min width 5, n = -42: *%5i*\n", n);
	result_og = printf("min width 5, n = -42: *%5i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 123456;
	result_ft = ft_printf("min width 3, n = 123456: *%3i*\n", n);
	result_og = printf("min width 3, n = 123456: *%3i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '-' (left justified) ----------
	ft_printf("\n--- Flag '-' (left justified) ---\n");

	n = 42;
	result_ft = ft_printf("flag '-', min width 5, n = 42: *%-5i*\n", n);
	result_og = printf("flag '-', min width 5, n = 42: *%-5i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag '-', min width 5, n = -42: *%-5i*\n", n);
	result_og = printf("flag '-', min width 5, n = -42: *%-5i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '0' (zero padding) ----------
	ft_printf("\n--- Flag '0' (zero padding) ---\n");

	n = 42;
	result_ft = ft_printf("flag '0', min width 5, n = 42: *%05i*\n", n);
	result_og = printf("flag '0', min width 5, n = 42: *%05i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag '0', min width 5, n = -42: *%05i*\n", n);
	result_og = printf("flag '0', min width 5, n = -42: *%05i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '0', min width 5, n = 0: *%05i*\n", n);
	result_og = printf("flag '0', min width 5, n = 0: *%05i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '-' and '0' together: '-' should win, '0' ignored
	ft_printf("\n--- Flags '-0' ('-' wins, '0' ignored) ---\n");

	n = 42;
	result_ft = ft_printf("flags '-0', min width 5, n = 42: *%-05i*\n", n);
	// result_og = printf("flags '-0', min width 5, n = 42: *%-05i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flags '-0', min width 5, n = -42: *%-05i*\n", n);
	// result_og = printf("flags '-0', min width 5, n = -42: *%-05i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Flag '+' (always show sign) ----------
	ft_printf("\n--- Flag '+' (always show sign) ---\n");

	n = 42;
	result_ft = ft_printf("flag '+', n = 42: *%+i*\n", n);
	result_og = printf("flag '+', n = 42: *%+i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag '+', n = -42: *%+i*\n", n);
	result_og = printf("flag '+', n = -42: *%+i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '+', n = 0: *%+i*\n", n);
	result_og = printf("flag '+', n = 0: *%+i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("flag '+', min width 5, n = 42: *%+5i*\n", 42);
	result_og = printf("flag '+', min width 5, n = 42: *%+5i*\n", 42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("flag '+', min width 5, n = -42: *%+5i*\n", -42);
	result_og = printf("flag '+', min width 5, n = -42: *%+5i*\n", -42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag ' ' (space instead of + for positives) ----------
	ft_printf("\n--- Flag ' ' (space for positive sign) ---\n");

	n = 42;
	result_ft = ft_printf("flag ' ', n = 42: *% i*\n", n);
	result_og = printf("flag ' ', n = 42: *% i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag ' ', n = -42: *% i*\n", n);
	result_og = printf("flag ' ', n = -42: *% i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag ' ', n = 0: *% i*\n", n);
	result_og = printf("flag ' ', n = 0: *% i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("flag ' ', min width 5, n = 42: *% 5i*\n", 42);
	result_og = printf("flag ' ', min width 5, n = 42: *% 5i*\n", 42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '+' and ' ' together: '+' wins
	ft_printf("\n--- Flags '+ ' ('+' wins) ---\n");

	n = 42;
	result_ft = ft_printf("flags '+ ', n = 42: *%+ i*\n", n);
	// result_og = printf("flags '+ ', n = 42: *%+ i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flags '+ ', n = -42: *%+ i*\n", n);
	// result_og = printf("flags '+ ', n = -42: *%+ i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Precision '.' (minimum number of digits) ----------
	ft_printf("\n--- Precision '.' (minimum digits) ---\n");

	n = 42;
	result_ft = ft_printf("precision 5, n = 42: *%.5i*\n", n);
	result_og = printf("precision 5, n = 42: *%.5i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("precision 5, n = -42: *%.5i*\n", n);
	result_og = printf("precision 5, n = -42: *%.5i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("precision 1, n = 0: *%.1i*\n", n);
	result_og = printf("precision 1, n = 0: *%.1i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision 0 with value 0: should print nothing (empty)
	result_ft = ft_printf("precision 0, n = 0: *%.0i*\n", 0);
	result_og = printf("precision 0, n = 0: *%.0i*\n", 0);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("precision 8, n = 7: *%.8i*\n", 7);
	result_og = printf("precision 8, n = 7: *%.8i*\n", 7);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + min width ----------
	ft_printf("\n--- Precision + min width ---\n");

	n = 42;
	result_ft = ft_printf("precision 3 + min width 6, n = 42: *%6.3i*\n", n);
	result_og = printf("precision 3 + min width 6, n = 42: *%6.3i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("precision 3 + min width 6, n = -42: *%6.3i*\n", n);
	result_og = printf("precision 3 + min width 6, n = -42: *%6.3i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("precision 0 + min width 5, n = 0: *%5.0i*\n", 0);
	result_og = printf("precision 0 + min width 5, n = 0: *%5.0i*\n", 0);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + flag '0' ('0' ignored when precision present) ----------
	ft_printf("\n--- Precision + flag '0' ('0' ignored) ---\n");

	n = 42;
	result_ft = ft_printf("flag '0' + precision 3, n = 42: *%0.3i*\n", n);
	// result_og = printf("flag '0' + precision 3, n = 42: *%0.3i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("flag '0' + precision 3, n = -42: *%0.3i*\n", n);
	// result_og = printf("flag '0' + precision 3, n = -42: *%0.3i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Combined flags, width, precision ----------
	ft_printf("\n--- Combined flags, width, precision ---\n");

	n = 42;
	result_ft = ft_printf("'+', width 8, precision 4, n = 42: *%+8.4i*\n", n);
	result_og = printf("'+', width 8, precision 4, n = 42: *%+8.4i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("'+', width 8, precision 4, n = -42: *%+8.4i*\n", n);
	result_og = printf("'+', width 8, precision 4, n = -42: *%+8.4i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 42;
	result_ft = ft_printf("'-+', width 8, precision 4, n = 42: *%-+8.4i*\n", n);
	result_og = printf("'-+', width 8, precision 4, n = 42: *%-+8.4i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = -42;
	result_ft = ft_printf("'-+', width 8, precision 4, n = -42: *%-+8.4i*\n", n);
	result_og = printf("'-+', width 8, precision 4, n = -42: *%-+8.4i*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Edge values ----------
	ft_printf("\n--- Edge values ---\n");

	result_ft = ft_printf("INT_MIN-ish: *%i*\n", -2147483648);
	// result_og = printf("INT_MIN-ish: *%i*\n", -2147483648);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	result_ft = ft_printf("INT_MAX-ish: *%i*\n", 2147483647);
	result_og = printf("INT_MAX-ish: *%i*\n", 2147483647);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}

void	test_u(void)
{
	int		result_ft;
	int		result_og;
	unsigned int	n;

	ft_printf("Testing '%%u' (unsigned decimal integer):\n");

	// ---------- Basic cases ----------
	ft_printf("\n--- Basic cases ---\n");

	n = 42;
	result_ft = ft_printf("no flags, n = 42: *%u*\n", n);
	result_og = printf("no flags, n = 42: *%u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("no flags, n = 0: *%u*\n", n);
	result_og = printf("no flags, n = 0: *%u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 4294967295u; // UINT_MAX-ish on 32-bit
	result_ft = ft_printf("no flags, n = 4294967295: *%u*\n", n);
	result_og = printf("no flags, n = 4294967295: *%u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Min width only ----------
	ft_printf("\n--- Min width only (right justified) ---\n");

	n = 42;
	result_ft = ft_printf("min width 5, n = 42: *%5u*\n", n);
	result_og = printf("min width 5, n = 42: *%5u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("min width 5, n = 0: *%5u*\n", n);
	result_og = printf("min width 5, n = 0: *%5u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 12345678u;
	result_ft = ft_printf("min width 3, n = 12345678: *%3u*\n", n);
	result_og = printf("min width 3, n = 12345678: *%3u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '-' (left justified) ----------
	ft_printf("\n--- Flag '-' (left justified) ---\n");

	n = 42;
	result_ft = ft_printf("flag '-', min width 5, n = 42: *%-5u*\n", n);
	result_og = printf("flag '-', min width 5, n = 42: *%-5u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '-', min width 5, n = 0: *%-5u*\n", n);
	result_og = printf("flag '-', min width 5, n = 0: *%-5u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 12345678u;
	result_ft = ft_printf("flag '-', min width 3, n = 12345678: *%-3u*\n", n);
	result_og = printf("flag '-', min width 3, n = 12345678: *%-3u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '0' (zero padding) ----------
	ft_printf("\n--- Flag '0' (zero padding) ---\n");

	n = 42;
	result_ft = ft_printf("flag '0', min width 5, n = 42: *%05u*\n", n);
	result_og = printf("flag '0', min width 5, n = 42: *%05u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '0', min width 5, n = 0: *%05u*\n", n);
	result_og = printf("flag '0', min width 5, n = 0: *%05u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 12345678u;
	result_ft = ft_printf("flag '0', min width 10, n = 12345678: *%010u*\n", n);
	result_og = printf("flag '0', min width 10, n = 12345678: *%010u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '-' and '0' together: '-' should win, '0' ignored [61][63]
	ft_printf("\n--- Flags '-0' ('-' wins, '0' ignored) ---\n");

	n = 42;
	result_ft = ft_printf("flags '-0', min width 5, n = 42: *%-05u*\n", n);
	// result_og = printf("flags '-0', min width 5, n = 42: *%-05u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flags '-0', min width 5, n = 0: *%-05u*\n", n);
	// result_og = printf("flags '-0', min width 5, n = 0: *%-05u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 12345678u;
	result_ft = ft_printf("flags '-0', min width 10, n = 12345678: *%-010u*\n", n);
	// result_og = printf("flags '-0', min width 10, n = 12345678: *%-010u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Precision '.' (minimum number of digits) ----------
	ft_printf("\n--- Precision '.' (minimum digits) ---\n");

	n = 42;
	result_ft = ft_printf("precision 5, n = 42: *%.5u*\n", n);
	result_og = printf("precision 5, n = 42: *%.5u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("precision 1, n = 0: *%.1u*\n", n);
	result_og = printf("precision 1, n = 0: *%.1u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision 0 with value 0: should print nothing (empty) [61][64][65]
	result_ft = ft_printf("precision 0, n = 0: *%.0u*\n", 0u);
	result_og = printf("precision 0, n = 0: *%.0u*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 7;
	result_ft = ft_printf("precision 8, n = 7: *%.8u*\n", n);
	result_og = printf("precision 8, n = 7: *%.8u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 4294967295u;
	result_ft = ft_printf("precision 12, n = 4294967295: *%.12u*\n", n);
	result_og = printf("precision 12, n = 4294967295: *%.12u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + min width ----------
	ft_printf("\n--- Precision + min width ---\n");

	n = 42;
	result_ft = ft_printf("precision 3 + min width 6, n = 42: *%6.3u*\n", n);
	result_og = printf("precision 3 + min width 6, n = 42: *%6.3u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("precision 0 + min width 5, n = 0: *%5.0u*\n", 0u);
	result_og = printf("precision 0 + min width 5, n = 0: *%5.0u*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 7;
	result_ft = ft_printf("precision 5 + min width 8, n = 7: *%8.5u*\n", n);
	result_og = printf("precision 5 + min width 8, n = 7: *%8.5u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + flag '0' ('0' ignored when precision present) [61][64] ----------
	ft_printf("\n--- Precision + flag '0' ('0' ignored) ---\n");

	n = 42;
	result_ft = ft_printf("flag '0' + precision 3, n = 42: *%0.3u*\n", n);
	// result_og = printf("flag '0' + precision 3, n = 42: *%0.3u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '0' + precision 5, n = 0: *%0.5u*\n", 0u);
	// result_og = printf("flag '0' + precision 5, n = 0: *%0.5u*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 12345678u;
	result_ft = ft_printf("flag '0' + precision 10, n = 12345678: *%0.10u*\n", n);
	// result_og = printf("flag '0' + precision 10, n = 12345678: *%0.10u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Combined flags, width, precision ----------
	ft_printf("\n--- Combined flags, width, precision ---\n");

	n = 42;
	result_ft = ft_printf("flag '0', width 8, precision 4, n = 42: *%08.4u*\n", n);
	// result_og = printf("flag '0', width 8, precision 4, n = 42: *%08.4u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '0', width 8, precision 4, n = 0: *%08.4u*\n", 0u);
	// result_og = printf("flag '0', width 8, precision 4, n = 0: *%08.4u*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 42;
	result_ft = ft_printf("flag '-', width 8, precision 4, n = 42: *%-8.4u*\n", n);
	result_og = printf("flag '-', width 8, precision 4, n = 42: *%-8.4u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 12345678u;
	result_ft = ft_printf("flag '-', width 12, precision 10, n = 12345678: *%-12.10u*\n", n);
	result_og = printf("flag '-', width 12, precision 10, n = 12345678: *%-12.10u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Edge / large values ----------
	ft_printf("\n--- Edge / large values ---\n");

	n = 0u;
	result_ft = ft_printf("n = 0: *%u*\n", n);
	result_og = printf("n = 0: *%u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 1u;
	result_ft = ft_printf("n = 1: *%u*\n", n);
	result_og = printf("n = 1: *%u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 2147483647u; // INT_MAX
	result_ft = ft_printf("n = 2147483647: *%u*\n", n);
	result_og = printf("n = 2147483647: *%u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 4294967295u; // UINT_MAX on 32-bit
	result_ft = ft_printf("n = 4294967295: *%u*\n", n);
	result_og = printf("n = 4294967295: *%u*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}

