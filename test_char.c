
#include "ft_printf.h"

void	test_percent(void)
{
	int		result_ft;
	int		result_og;

	ft_printf("Testing '%%' (percent sign) conversion:\n");

	// no flags, basic usage
	result_ft = ft_printf("no flags = *%%*\n");
	result_og = printf("no flags = *%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// multiple percent signs in a row
	result_ft = ft_printf("multiple = *%%%%%%*\n");
	result_og = printf("multiple = *%%%%%%*\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// percent with other text
	result_ft = ft_printf("with text = Hello%%World\n");
	result_og = printf("with text = Hello%%World\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// percent at start and end
	result_ft = ft_printf("start and end = %%test%%\n");
	result_og = printf("start and end = %%test%%\n");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// percent between other conversions (sanity check)
	ft_printf("\nTesting '%%' mixed with other conversions:\n");

	result_ft = ft_printf("char + percent + int = %c %% %d\n", 'X', 42);
	result_og = printf("char + percent + int = %c %% %d\n", 'X', 42);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("string + percent = %s %%\n", "OK");
	result_og = printf("string + percent = %s %%\n", "OK");
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}


void	test_c(void)
{
	int		result_ft;
	int		result_og;
	char	c;

	c = 'W';
	ft_printf("Testing 'char c = 'W'':\n");

	// no flags
	result_ft = ft_printf("no flags = *%c*\n", c);
	result_og = printf("no flags = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// flag '-' + min width (left justified)
	result_ft = ft_printf("flag '-' + min width 5 = *%-5c*\n", c);
	result_og = printf("flag '-' + min width 5 = *%-5c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// min width only (right justified)
	result_ft = ft_printf("min width 5 = *%5c*\n", c);
	result_og = printf("min width 5 = *%5c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// min width larger than 5
	result_ft = ft_printf("min width 10 = *%10c*\n", c);
	result_og = printf("min width 10 = *%10c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// flag '-' + larger min width
	result_ft = ft_printf("flag '-' + min width 10 = *%-10c*\n", c);
	result_og = printf("flag '-' + min width 10 = *%-10c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// special characters
	ft_printf("\nTesting special characters:\n");

	c = '\n';
	result_ft = ft_printf("char '\\n' = *%c*\n", c);
	result_og = printf("char '\\n' = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	c = '\t';
	result_ft = ft_printf("char '\\t' = *%c*\n", c);
	result_og = printf("char '\\t' = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	c = ' ';
	result_ft = ft_printf("char ' ' (space) = *%c*\n", c);
	result_og = printf("char ' ' (space) = *%c*\n", c);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// numeric value as char
	ft_printf("\nTesting numeric value as char:\n");

	result_ft = ft_printf("char 65 ('A') = *%c*\n", 65);
	result_og = printf("char 65 ('A') = *%c*\n", 65);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("char 0 (null byte) = *%c*\n", 0);
	result_og = printf("char 0 (null byte) = *%c*\n", 0);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}

void	test_s(void)
{
	int		result_ft;
	int		result_og;
	char	*str;

	str = "Hello";
	ft_printf("Testing 'char *str = \"Hello\"':\n");

	// no flags
	result_ft = ft_printf("no flags = *%s*\n", str);
	result_og = printf("no flags = *%s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// flag '-' + min width
	result_ft = ft_printf("flag '-' + min width 10 = *%-10s*\n", str);
	result_og = printf("flag '-' + min width 10 = *%-10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// min width only (right justified)
	result_ft = ft_printf("min width 10 = *%10s*\n", str);
	result_og = printf("min width 10 = *%10s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision only (truncate string)
	result_ft = ft_printf("precision 3 = *%.3s*\n", str);
	result_og = printf("precision 3 = *%.3s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision larger than string (no truncation)
	result_ft = ft_printf("precision 20 = *%.20s*\n", str);
	result_og = printf("precision 20 = *%.20s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision + min width (right justified, truncated)
	result_ft = ft_printf("precision 3 + min width 10 = *%10.3s*\n", str);
	result_og = printf("precision 3 + min width 10 = *%10.3s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// '-' + precision + min width (left justified, truncated)
	result_ft = ft_printf("flag '-' + precision 3 + min width 10 = *%-10.3s*\n", str);
	result_og = printf("flag '-' + precision 3 + min width 10 = *%-10.3s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// precision 0 (should print nothing for non-NULL string)
	result_ft = ft_printf("precision 0 = *%.0s*\n", str);
	result_og = printf("precision 0 = *%.0s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	// empty string with precision and width
	str = "";
	ft_printf("\nTesting 'char *str = \"\"':\n");

	result_ft = ft_printf("no flags = *%s*\n", str);
	result_og = printf("no flags = *%s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("precision 5 + min width 10 = *%10.5s*\n", str);
	result_og = printf("precision 5 + min width 10 = *%10.5s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);

	result_ft = ft_printf("flag '-' + precision 5 + min width 10 = *%-10.5s*\n", str);
	result_og = printf("flag '-' + precision 5 + min width 10 = *%-10.5s*\n", str);
	ft_printf("result_ft = %d\n", result_ft);
	printf("result_og = %d\n", result_og);
}
