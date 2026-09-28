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
    
    char type;
} t_flags;

// *** Functions *** //

// ft_printf.c
int ft_printf(const char *, ...);
void parser(const char **s, t_flags *flags);
int printer_manager(t_flags flags, va_list *args, int *count);
t_flags init_flags(void);


// ft_printf_printing.c
int ft_putchar(char value);
int putnbr(void *value);
int putstr(void *value);
int puthexa(void *value);

// fr_printf_utils.c
int is_num(char c);
int is_flag(char c);
int is_converter(char c);
void min_width_precison_len(t_flags *flags, const char **s);


int min_width();
int positive_sign();
int space();
int left_align();
int zero_padding();
int precision();
int alt_hexa();

#endif