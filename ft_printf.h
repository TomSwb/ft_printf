#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// *** Libraries *** //

// va_arg functions & type
# include <stdarg.h>

// write();
# include <unistd.h>

// *** Struct *** //

typedef struct s_flags
{
    int left_align;
    int zero_padding;
    int positive_sign;
    int alt_hexa;
    int spaces;
    
    int min_width;
    int precision_len;
    
    int print_count;
    
} t_flags

// *** Functions *** //

// ft_printf.c
int ft_printf(const char *, ...);
int parser();
int printer_manager();
int is_converter(char c);

// ft_printf_printing.c
int putchar(void *value);
int putnbr(void *value);
int putstr(void *value);
int puthexa(void *value);

// fr_printf_utils.c
int min_width();
int positive_sign();
int space();
int left_align();
int zero_padding();
int precision();
int alt_hexa();

#endif