
#include "ft_printf.h"
#include <stdio.h>

void	test_x(void)
{
	int			result_ft;
	int			result_og;
	unsigned int	n;

	ft_printf("Testing '%%x' (unsigned hexadecimal, lowercase):\n");

	// ---------- Basic cases ----------
	ft_printf("\n--- Basic cases ---\n");

	n = 0;
	result_ft = ft_printf("no flags, n = 0: *%x*\n", n);
	result_og = printf("no flags, n = 0: *%x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("no flags, n = 15: *%x*\n", n);
	result_og = printf("no flags, n = 15: *%x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("no flags, n = 255: *%x*\n", n);
	result_og = printf("no flags, n = 255: *%x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 4294967295u; // UINT_MAX-ish
	result_ft = ft_printf("no flags, n = 4294967295: *%x*\n", n);
	result_og = printf("no flags, n = 4294967295: *%x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Min width only ----------
	ft_printf("\n--- Min width only (right justified) ---\n");

	n = 15;
	result_ft = ft_printf("min width 5, n = 15: *%5x*\n", n);
	result_og = printf("min width 5, n = 15: *%5x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("min width 3, n = 255: *%3x*\n", n);
	result_og = printf("min width 3, n = 255: *%3x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("min width 4, n = 0: *%4x*\n", n);
	result_og = printf("min width 4, n = 0: *%4x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '-' (left justified) ----------
	ft_printf("\n--- Flag '-' (left justified) ---\n");

	n = 15;
	result_ft = ft_printf("flag '-', min width 5, n = 15: *%-5x*\n", n);
	result_og = printf("flag '-', min width 5, n = 15: *%-5x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '-', min width 5, n = 255: *%-5x*\n", n);
	result_og = printf("flag '-', min width 5, n = 255: *%-5x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '-', min width 4, n = 0: *%-4x*\n", n);
	result_og = printf("flag '-', min width 4, n = 0: *%-4x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '0' (zero padding) ----------
	ft_printf("\n--- Flag '0' (zero padding) ---\n");

	n = 15;
	result_ft = ft_printf("flag '0', min width 5, n = 15: *%05x*\n", n);
	result_og = printf("flag '0', min width 5, n = 15: *%05x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '0', min width 6, n = 255: *%06x*\n", n);
	result_og = printf("flag '0', min width 6, n = 255: *%06x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '0', min width 4, n = 0: *%04x*\n", n);
	result_og = printf("flag '0', min width 4, n = 0: *%04x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '-' and '0' together: '-' should win, '0' ignored [84][85][89]
	ft_printf("\n--- Flags '-0' ('-' wins, '0' ignored) ---\n");

	n = 15;
	result_ft = ft_printf("flags '-0', min width 5, n = 15: *%-05x*\n", n);
	// result_og = printf("flags '-0', min width 5, n = 15: *%-05x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flags '-0', min width 6, n = 255: *%-06x*\n", n);
	// result_og = printf("flags '-0', min width 6, n = 255: *%-06x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Flag '#' (alternate form: 0x prefix) ----------
	ft_printf("\n--- Flag '#' (alternate form: 0x prefix) ---\n");

	n = 0;
	result_ft = ft_printf("flag '#', n = 0: *%#x*\n", n);
	result_og = printf("flag '#', n = 0: *%#x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("flag '#', n = 15: *%#x*\n", n);
	result_og = printf("flag '#', n = 15: *%#x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '#', n = 255: *%#x*\n", n);
	result_og = printf("flag '#', n = 255: *%#x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 4294967295u;
	result_ft = ft_printf("flag '#', n = 4294967295: *%#x*\n", n);
	result_og = printf("flag '#', n = 4294967295: *%#x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '#' with width
	n = 15;
	result_ft = ft_printf("flag '#', min width 6, n = 15: *%#6x*\n", n);
	result_og = printf("flag '#', min width 6, n = 15: *%#6x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '#', min width 6, n = 255: *%#6x*\n", n);
	result_og = printf("flag '#', min width 6, n = 255: *%#6x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '#' with '0' flag
	n = 15;
	result_ft = ft_printf("flags '#0', min width 6, n = 15: *%#06x*\n", n);
	result_og = printf("flags '#0', min width 6, n = 15: *%#06x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flags '#0', min width 6, n = 0: *%#06x*\n", n);
	result_og = printf("flags '#0', min width 6, n = 0: *%#06x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision '.' (minimum number of digits) ----------
	ft_printf("\n--- Precision '.' (minimum digits) ---\n");

	n = 0;
	result_ft = ft_printf("precision 1, n = 0: *%.1x*\n", n);
	result_og = printf("precision 1, n = 0: *%.1x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("precision 5, n = 15: *%.5x*\n", n);
	result_og = printf("precision 5, n = 15: *%.5x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("precision 5, n = 255: *%.5x*\n", n);
	result_og = printf("precision 5, n = 255: *%.5x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision 0 with value 0: should print nothing (empty) [82][85][87][89]
	result_ft = ft_printf("precision 0, n = 0: *%.0x*\n", 0u);
	result_og = printf("precision 0, n = 0: *%.0x*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 7;
	result_ft = ft_printf("precision 8, n = 7: *%.8x*\n", n);
	result_og = printf("precision 8, n = 7: *%.8x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- '#' with precision ----------
	ft_printf("\n--- Flag '#' with precision ---\n");

	n = 0;
	result_ft = ft_printf("flag '#', precision 0, n = 0: *%#.0x*\n", 0u);
	result_og = printf("flag '#', precision 0, n = 0: *%#.0x*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("flag '#', precision 5, n = 15: *%#.5x*\n", n);
	result_og = printf("flag '#', precision 5, n = 15: *%#.5x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '#', precision 3, n = 255: *%#.3x*\n", n);
	result_og = printf("flag '#', precision 3, n = 255: *%#.3x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + min width ----------
	ft_printf("\n--- Precision + min width ---\n");

	n = 15;
	result_ft = ft_printf("precision 3 + min width 6, n = 15: *%6.3x*\n", n);
	result_og = printf("precision 3 + min width 6, n = 15: *%6.3x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("precision 0 + min width 5, n = 0: *%5.0x*\n", 0u);
	result_og = printf("precision 0 + min width 5, n = 0: *%5.0x*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 7;
	result_ft = ft_printf("precision 5 + min width 8, n = 7: *%8.5x*\n", n);
	result_og = printf("precision 5 + min width 8, n = 7: *%8.5x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + flag '0' ('0' ignored when precision present) [85][89] ----------
	ft_printf("\n--- Precision + flag '0' ('0' ignored) ---\n");

	n = 15;
	result_ft = ft_printf("flag '0' + precision 3, n = 15: *%0.3x*\n", n);
	// result_og = printf("flag '0' + precision 3, n = 15: *%0.3x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '0' + precision 5, n = 0: *%0.5x*\n", 0u);
	// result_og = printf("flag '0' + precision 5, n = 0: *%0.5x*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Combined flags, width, precision ----------
	ft_printf("\n--- Combined flags, width, precision ---\n");

	n = 15;
	result_ft = ft_printf("flag '#', width 8, precision 4, n = 15: *%#8.4x*\n", n);
	result_og = printf("flag '#', width 8, precision 4, n = 15: *%#8.4x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '#', width 10, precision 6, n = 255: *%#10.6x*\n", n);
	result_og = printf("flag '#', width 10, precision 6, n = 255: *%#10.6x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("flags '#-', width 8, precision 4, n = 15: *%#-8.4x*\n", n);
	result_og = printf("flags '#-', width 8, precision 4, n = 15: *%#-8.4x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flags '#-', width 10, precision 6, n = 255: *%#-10.6x*\n", n);
	result_og = printf("flags '#-', width 10, precision 6, n = 255: *%#-10.6x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Edge / large values ----------
	ft_printf("\n--- Edge / large values ---\n");

	n = 0u;
	result_ft = ft_printf("n = 0: *%x*\n", n);
	result_og = printf("n = 0: *%x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 1u;
	result_ft = ft_printf("n = 1: *%x*\n", n);
	result_og = printf("n = 1: *%x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 4294967295u;
	result_ft = ft_printf("n = 4294967295: *%x*\n", n);
	result_og = printf("n = 4294967295: *%x*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}

void	test_X(void)
{
	int			result_ft;
	int			result_og;
	unsigned int	n;

	ft_printf("Testing '%%X' (unsigned hexadecimal, uppercase):\n");

	// ---------- Basic cases ----------
	ft_printf("\n--- Basic cases ---\n");

	n = 0;
	result_ft = ft_printf("no flags, n = 0: *%X*\n", n);
	result_og = printf("no flags, n = 0: *%X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("no flags, n = 15: *%X*\n", n);
	result_og = printf("no flags, n = 15: *%X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("no flags, n = 255: *%X*\n", n);
	result_og = printf("no flags, n = 255: *%X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 4294967295u;
	result_ft = ft_printf("no flags, n = 4294967295: *%X*\n", n);
	result_og = printf("no flags, n = 4294967295: *%X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Min width only ----------
	ft_printf("\n--- Min width only (right justified) ---\n");

	n = 15;
	result_ft = ft_printf("min width 5, n = 15: *%5X*\n", n);
	result_og = printf("min width 5, n = 15: *%5X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("min width 3, n = 255: *%3X*\n", n);
	result_og = printf("min width 3, n = 255: *%3X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("min width 4, n = 0: *%4X*\n", n);
	result_og = printf("min width 4, n = 0: *%4X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '-' (left justified) ----------
	ft_printf("\n--- Flag '-' (left justified) ---\n");

	n = 15;
	result_ft = ft_printf("flag '-', min width 5, n = 15: *%-5X*\n", n);
	result_og = printf("flag '-', min width 5, n = 15: *%-5X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '-', min width 5, n = 255: *%-5X*\n", n);
	result_og = printf("flag '-', min width 5, n = 255: *%-5X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '-', min width 4, n = 0: *%-4X*\n", n);
	result_og = printf("flag '-', min width 4, n = 0: *%-4X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Flag '0' (zero padding) ----------
	ft_printf("\n--- Flag '0' (zero padding) ---\n");

	n = 15;
	result_ft = ft_printf("flag '0', min width 5, n = 15: *%05X*\n", n);
	result_og = printf("flag '0', min width 5, n = 15: *%05X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '0', min width 6, n = 255: *%06X*\n", n);
	result_og = printf("flag '0', min width 6, n = 255: *%06X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '0', min width 4, n = 0: *%04X*\n", n);
	result_og = printf("flag '0', min width 4, n = 0: *%04X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '-' and '0' together: '-' should win, '0' ignored
	ft_printf("\n--- Flags '-0' ('-' wins, '0' ignored) ---\n");

	n = 15;
	result_ft = ft_printf("flags '-0', min width 5, n = 15: *%-05X*\n", n);
	// result_og = printf("flags '-0', min width 5, n = 15: *%-05X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flags '-0', min width 6, n = 255: *%-06X*\n", n);
	// result_og = printf("flags '-0', min width 6, n = 255: *%-06X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Flag '#' (alternate form: 0X prefix) ----------
	ft_printf("\n--- Flag '#' (alternate form: 0X prefix) ---\n");

	n = 0;
	result_ft = ft_printf("flag '#', n = 0: *%#X*\n", n);
	result_og = printf("flag '#', n = 0: *%#X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("flag '#', n = 15: *%#X*\n", n);
	result_og = printf("flag '#', n = 15: *%#X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '#', n = 255: *%#X*\n", n);
	result_og = printf("flag '#', n = 255: *%#X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 4294967295u;
	result_ft = ft_printf("flag '#', n = 4294967295: *%#X*\n", n);
	result_og = printf("flag '#', n = 4294967295: *%#X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '#' with width
	n = 15;
	result_ft = ft_printf("flag '#', min width 6, n = 15: *%#6X*\n", n);
	result_og = printf("flag '#', min width 6, n = 15: *%#6X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '#', min width 6, n = 255: *%#6X*\n", n);
	result_og = printf("flag '#', min width 6, n = 255: *%#6X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '#' with '0' flag
	n = 15;
	result_ft = ft_printf("flags '#0', min width 6, n = 15: *%#06X*\n", n);
	result_og = printf("flags '#0', min width 6, n = 15: *%#06X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flags '#0', min width 6, n = 0: *%#06X*\n", n);
	result_og = printf("flags '#0', min width 6, n = 0: *%#06X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision '.' (minimum number of digits) ----------
	ft_printf("\n--- Precision '.' (minimum digits) ---\n");

	n = 0;
	result_ft = ft_printf("precision 1, n = 0: *%.1X*\n", n);
	result_og = printf("precision 1, n = 0: *%.1X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("precision 5, n = 15: *%.5X*\n", n);
	result_og = printf("precision 5, n = 15: *%.5X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("precision 5, n = 255: *%.5X*\n", n);
	result_og = printf("precision 5, n = 255: *%.5X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision 0 with value 0: should print nothing (empty)
	result_ft = ft_printf("precision 0, n = 0: *%.0X*\n", 0u);
	result_og = printf("precision 0, n = 0: *%.0X*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 7;
	result_ft = ft_printf("precision 8, n = 7: *%.8X*\n", n);
	result_og = printf("precision 8, n = 7: *%.8X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- '#' with precision ----------
	ft_printf("\n--- Flag '#' with precision ---\n");

	n = 0;
	result_ft = ft_printf("flag '#', precision 0, n = 0: *%#.0X*\n", 0u);
	result_og = printf("flag '#', precision 0, n = 0: *%#.0X*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("flag '#', precision 5, n = 15: *%#.5X*\n", n);
	result_og = printf("flag '#', precision 5, n = 15: *%#.5X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '#', precision 3, n = 255: *%#.3X*\n", n);
	result_og = printf("flag '#', precision 3, n = 255: *%#.3X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + min width ----------
	ft_printf("\n--- Precision + min width ---\n");

	n = 15;
	result_ft = ft_printf("precision 3 + min width 6, n = 15: *%6.3X*\n", n);
	result_og = printf("precision 3 + min width 6, n = 15: *%6.3X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("precision 0 + min width 5, n = 0: *%5.0X*\n", 0u);
	result_og = printf("precision 0 + min width 5, n = 0: *%5.0X*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 7;
	result_ft = ft_printf("precision 5 + min width 8, n = 7: *%8.5X*\n", n);
	result_og = printf("precision 5 + min width 8, n = 7: *%8.5X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Precision + flag '0' ('0' ignored when precision present) ----------
	ft_printf("\n--- Precision + flag '0' ('0' ignored) ---\n");

	n = 15;
	result_ft = ft_printf("flag '0' + precision 3, n = 15: *%0.3X*\n", n);
	// result_og = printf("flag '0' + precision 3, n = 15: *%0.3X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	n = 0;
	result_ft = ft_printf("flag '0' + precision 5, n = 0: *%0.5X*\n", 0u);
	// result_og = printf("flag '0' + precision 5, n = 0: *%0.5X*\n", 0u);
	ft_printf("result_ft = %d\n", result_ft);
	// printf("result_og = %d\n", result_og);

	// ---------- Combined flags, width, precision ----------
	ft_printf("\n--- Combined flags, width, precision ---\n");

	n = 15;
	result_ft = ft_printf("flag '#', width 8, precision 4, n = 15: *%#8.4X*\n", n);
	result_og = printf("flag '#', width 8, precision 4, n = 15: *%#8.4X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flag '#', width 10, precision 6, n = 255: *%#10.6X*\n", n);
	result_og = printf("flag '#', width 10, precision 6, n = 255: *%#10.6X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 15;
	result_ft = ft_printf("flags '#-', width 8, precision 4, n = 15: *%#-8.4X*\n", n);
	result_og = printf("flags '#-', width 8, precision 4, n = 15: *%#-8.4X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 255;
	result_ft = ft_printf("flags '#-', width 10, precision 6, n = 255: *%#-10.6X*\n", n);
	result_og = printf("flags '#-', width 10, precision 6, n = 255: *%#-10.6X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// ---------- Edge / large values ----------
	ft_printf("\n--- Edge / large values ---\n");

	n = 0u;
	result_ft = ft_printf("n = 0: *%X*\n", n);
	result_og = printf("n = 0: *%X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 1u;
	result_ft = ft_printf("n = 1: *%X*\n", n);
	result_og = printf("n = 1: *%X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	n = 4294967295u;
	result_ft = ft_printf("n = 4294967295: *%X*\n", n);
	result_og = printf("n = 4294967295: *%X*\n", n);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}

