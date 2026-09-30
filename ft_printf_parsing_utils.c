
#include "ft_printf.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	char	*s;

	s = "-0+# ";
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}