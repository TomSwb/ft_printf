
#include "ft_printf.h"
#include <stdio.h>

/* ==================== %% TESTS ==================== */

void	test_percent(void)
{
	int		result_ft;
	int		result_og;

	ft_printf("========== Testing '%%' (percent sign) conversion ==========\n\n");

	/* --- basic cases --- */
	ft_printf("--- basic cases ---\n");

	result_ft = ft_printf("no flags = *%%*\n");
	result_og = printf("no flags = *%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("multiple = *%%%%%%*\n");
	result_og = printf("multiple = *%%%%%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("with text = Hello%%World\n");
	result_og = printf("with text = Hello%%World\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("start and end = %%test%%\n");
	result_og = printf("start and end = %%test%%\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- width and flags with %% (should be ignored by standard, but test anyway) --- */
	ft_printf("--- width/flags with %% (should be ignored) ---\n");

	result_ft = ft_printf("width 5 = *%5%%*\n");
	result_og = printf("width 5 = *%5%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + width 5 = *%-5%%*\n");
	result_og = printf("flag '-' + width 5 = *%-5%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '0' + width 5 = *%05%%*\n");
	result_og = printf("flag '0' + width 5 = *%05%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '+' + width 5 = *%+5%%*\n");
	result_og = printf("flag '+' + width 5 = *%+5%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag ' ' + width 5 = *% 5%%*\n");
	result_og = printf("flag ' ' + width 5 = *% 5%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '#' + width 5 = *%#5%%*\n");
	result_og = printf("flag '#' + width 5 = *%#5%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- percent at boundaries --- */
	ft_printf("--- percent at boundaries ---\n");

	result_ft = ft_printf("%%\n");
	result_og = printf("%%\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("%% at start\n");
	result_og = printf("%% at start\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("at end %%\n");
	result_og = printf("at end %%\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- many percents in a row --- */
	ft_printf("--- many percents in a row ---\n");

	result_ft = ft_printf("ten percents: *%%%%%%%%%%*\n");
	result_og = printf("ten percents: *%%%%%%%%%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("odd count: *%%%%%*\n");
	result_og = printf("odd count: *%%%%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- mixed with other conversions --- */
	ft_printf("--- mixed with other conversions ---\n");

	result_ft = ft_printf("char + percent + int = %c %% %d\n", 'X', 42);
	result_og = printf("char + percent + int = %c %% %d\n", 'X', 42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("string + percent = %s %%\n", "OK");
	result_og = printf("string + percent = %s %%\n", "OK");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("int + percent + string = %d %% %s\n", 123, "test");
	result_og = printf("int + percent + string = %d %% %s\n", 123, "test");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("percent between percents = %% %c %% %s %%\n", 'Z', "mid");
	result_og = printf("percent between percents = %% %c %% %s %%\n", 'Z', "mid");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- percent with precision/width on other specifiers around it --- */
	ft_printf("--- percent with width/precision on neighbors ---\n");

	result_ft = ft_printf("%5c %% %-10s\n", 'A', "hello");
	result_og = printf("%5c %% %-10s\n", 'A', "hello");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("%-5c %% %10.3s\n", 'B', "world");
	result_og = printf("%-5c %% %10.3s\n", 'B', "world");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);
}

/* ==================== %c TESTS ==================== */

void	test_c(void)
{
	int		result_ft;
	int		result_og;
	char	c;

	ft_printf("========== Testing '%%c' (character) conversion ==========\n\n");

	c = 'W';
	ft_printf("--- basic cases with c = 'W' ---\n");

	result_ft = ft_printf("no flags = *%c*\n", c);
	result_og = printf("no flags = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + min width 5 = *%-5c*\n", c);
	result_og = printf("flag '-' + min width 5 = *%-5c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("min width 5 (right justified) = *%5c*\n", c);
	result_og = printf("min width 5 (right justified) = *%5c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("min width 10 = *%10c*\n", c);
	result_og = printf("min width 10 = *%10c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + min width 10 = *%-10c*\n", c);
	result_og = printf("flag '-' + min width 10 = *%-10c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '0' + min width 5 = *%05c*\n", c);
	result_og = printf("flag '0' + min width 5 = *%05c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '+' + min width 5 = *%+5c*\n", c);
	result_og = printf("flag '+' + min width 5 = *%+5c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag ' ' + min width 5 = *% 5c*\n", c);
	result_og = printf("flag ' ' + min width 5 = *% 5c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '#' + min width 5 = *%#5c*\n", c);
	result_og = printf("flag '#' + min width 5 = *%#5c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- special characters --- */
	ft_printf("--- special characters ---\n");

	c = '\n';
	result_ft = ft_printf("char '\\n' = *%c*\n", c);
	result_og = printf("char '\\n' = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	c = '\t';
	result_ft = ft_printf("char '\\t' = *%c*\n", c);
	result_og = printf("char '\\t' = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	c = '\r';
	result_ft = ft_printf("char '\\r' = *%c*\n", c);
	result_og = printf("char '\\r' = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	c = '\\';
	result_ft = ft_printf("char '\\\\' = *%c*\n", c);
	result_og = printf("char '\\\\' = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	c = '\'';
	result_ft = ft_printf("char '\\'' = *%c*\n", c);
	result_og = printf("char '\\'' = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	c = '"';
	result_ft = ft_printf("char '\"' = *%c*\n", c);
	result_og = printf("char '\"' = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	c = ' ';
	result_ft = ft_printf("char ' ' (space) = *%c*\n", c);
	result_og = printf("char ' ' (space) = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	c = '\0';
	result_ft = ft_printf("char '\\0' (null byte) = *%c*\n", c);
	result_og = printf("char '\\0' (null byte) = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- numeric values as char --- */
	ft_printf("--- numeric values as char ---\n");

	result_ft = ft_printf("char 65 ('A') = *%c*\n", 65);
	result_og = printf("char 65 ('A') = *%c*\n", 65);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("char 0 (null byte via int 0) = *%c*\n", 0);
	result_og = printf("char 0 (null byte via int 0) = *%c*\n", 0);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("char 255 (0xFF) = *%c*\n", 255);
	result_og = printf("char 255 (0xFF) = *%c*\n", 255);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("char -1 (implementation-defined) = *%c*\n", -1);
	result_og = printf("char -1 (implementation-defined) = *%c*\n", -1);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- width edge cases --- */
	ft_printf("--- width edge cases ---\n");

	result_ft = ft_printf("width 1 = *%1c*\n", c);
	result_og = printf("width 1 = *%1c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("width 0 = *%0c*\n", c);
	result_og = printf("width 0 = *%0c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("large width 50 = *%50c*\n", 'X');
	result_og = printf("large width 50 = *%50c*\n", 'X');
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + large width 50 = *%-50c*\n", 'Y');
	result_og = printf("flag '-' + large width 50 = *%-50c*\n", 'Y');
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- mixed with other conversions --- */
	ft_printf("--- mixed with other conversions ---\n");

	result_ft = ft_printf("%c %c %c\n", 'A', 'B', 'C');
	result_og = printf("%c %c %c\n", 'A', 'B', 'C');
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("%5c %s %d\n", 'K', "mid", 999);
	result_og = printf("%5c %s %d\n", 'K', "mid", 999);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("%c%%%c\n", 'L', 'M');
	result_og = printf("%c%%%c\n", 'L', 'M');
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("%-10c %% %10c\n", 'L', 'R');
	result_og = printf("%-10c %% %10c\n", 'L', 'R');
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);
}

/* ==================== %s TESTS ==================== */

void	test_s(void)
{
	int		result_ft;
	int		result_og;
	char	*str;

	ft_printf("========== Testing '%%s' (string) conversion ==========\n\n");

	/* --- normal string --- */
	str = "Hello";
	ft_printf("--- normal string: str = \"Hello\" ---\n");

	result_ft = ft_printf("no flags = *%s*\n", str);
	result_og = printf("no flags = *%s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + min width 10 = *%-10s*\n", str);
	result_og = printf("flag '-' + min width 10 = *%-10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("min width 10 (right justified) = *%10s*\n", str);
	result_og = printf("min width 10 (right justified) = *%10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 3 (truncate) = *%.3s*\n", str);
	result_og = printf("precision 3 (truncate) = *%.3s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 20 (larger than string) = *%.20s*\n", str);
	result_og = printf("precision 20 (larger than string) = *%.20s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 3 + min width 10 = *%10.3s*\n", str);
	result_og = printf("precision 3 + min width 10 = *%10.3s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + precision 3 + min width 10 = *%-10.3s*\n", str);
	result_og = printf("flag '-' + precision 3 + min width 10 = *%-10.3s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 0 (should print nothing) = *%.0s*\n", str);
	result_og = printf("precision 0 (should print nothing) = *%.0s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '0' + width 10 = *%010s*\n", str);
	result_og = printf("flag '0' + width 10 = *%010s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '+' + width 10 = *%+10s*\n", str);
	result_og = printf("flag '+' + width 10 = *%+10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag ' ' + width 10 = *% 10s*\n", str);
	result_og = printf("flag ' ' + width 10 = *% 10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '#' + width 10 = *%#10s*\n", str);
	result_og = printf("flag '#' + width 10 = *%#10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- empty string --- */
	str = "";
	ft_printf("--- empty string: str = \"\" ---\n");

	result_ft = ft_printf("no flags = *%s*\n", str);
	result_og = printf("no flags = *%s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("min width 10 = *%10s*\n", str);
	result_og = printf("min width 10 = *%10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + min width 10 = *%-10s*\n", str);
	result_og = printf("flag '-' + min width 10 = *%-10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 5 + min width 10 = *%10.5s*\n", str);
	result_og = printf("precision 5 + min width 10 = *%10.5s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + precision 5 + min width 10 = *%-10.5s*\n", str);
	result_og = printf("flag '-' + precision 5 + min width 10 = *%-10.5s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 0 on empty = *%.0s*\n", str);
	result_og = printf("precision 0 on empty = *%.0s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- NULL string --- */
	str = NULL;
	ft_printf("--- NULL string: str = NULL ---\n");

	result_ft = ft_printf("no flags = *%s*\n", str);
	result_og = printf("no flags = *%s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("min width 10 = *%10s*\n", str);
	result_og = printf("min width 10 = *%10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + min width 10 = *%-10s*\n", str);
	result_og = printf("flag '-' + min width 10 = *%-10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 5 + min width 10 = *%10.5s*\n", str);
	result_og = printf("precision 5 + min width 10 = *%10.5s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("flag '-' + precision 5 + min width 10 = *%-10.5s*\n", str);
	result_og = printf("flag '-' + precision 5 + min width 10 = *%-10.5s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 0 on NULL = *%.0s*\n", str);
	result_og = printf("precision 0 on NULL = *%.0s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- longer and special strings --- */
	ft_printf("--- longer and special strings ---\n");

	str = "This is a longer test string with spaces and words.";
	result_ft = ft_printf("long string no flags = *%s*\n", str);
	result_og = printf("long string no flags = *%s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("long string precision 10 = *%.10s*\n", str);
	result_og = printf("long string precision 10 = *%.10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("long string width 60 = *%60s*\n", str);
	result_og = printf("long string width 60 = *%60s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	str = "tabs\there\nand\nnewlines";
	result_ft = ft_printf("string with \\t and \\n = *%s*\n", str);
	result_og = printf("string with \\t and \\n = *%s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	str = "prefix%%percent";
	result_ft = ft_printf("string containing %% = *%s*\n", str);
	result_og = printf("string containing %% = *%s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- precision edge cases --- */
	ft_printf("--- precision edge cases ---\n");

	str = "Hello";
	result_ft = ft_printf("precision 1 = *%.1s*\n", str);
	result_og = printf("precision 1 = *%.1s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision equal to length = *%.5s*\n", str);
	result_og = printf("precision equal to length = *%.5s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 2 + width 10 = *%10.2s*\n", str);
	result_og = printf("precision 2 + width 10 = *%10.2s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("precision 2 + width 2 = *%2.2s*\n", str);
	result_og = printf("precision 2 + width 2 = *%2.2s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	/* --- mixed with other conversions --- */
	ft_printf("--- mixed with other conversions ---\n");

	result_ft = ft_printf("%s %s %s\n", "one", "two", "three");
	result_og = printf("%s %s %s\n", "one", "two", "three");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("%10s %% %-10s\n", "left", "right");
	result_og = printf("%10s %% %-10s\n", "left", "right");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("%c %s %d %%\n", 'X', "mid", 42);
	result_og = printf("%c %s %d %%\n", 'X', "mid", 42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);

	result_ft = ft_printf("%-5c %10.3s %05d\n", 'A', "hello", 7);
	result_og = printf("%-5c %10.3s %05d\n", 'A', "hello", 7);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n\n", result_og);
}
