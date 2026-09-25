#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// *** Libraries *** //

// va_arg functions / type
# include <stdarg.h>

// *** Functions *** //

int ft_printf(const char *, ...);

int putchar(void *value);
int putnbr(void *value);
int putstr(void *value);
int puthexa(void *value);

int min_width();
int positive_sign();
int space();
int left_align();
int zero_padding();
int precision();
int alt_hexa();

#endif