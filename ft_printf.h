/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:53:57 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/29 20:03:39 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    int precision;
    int precision_len;
    
    char converter;
} t_flags;

// *** Functions *** //

// ft_printf.c
int ft_printf(const char *, ...);
void printer_manager(t_flags *flags, va_list *args, int *count);
void printer_manager_char(t_flags *flags, va_list *args, int *count);
void printer_manager_decimal(t_flags *flags, va_list *args, int *count);
void printer_manager_hexa(t_flags *flags, va_list *args, int *count);

// ft_printf_parsing.c
t_flags init_flags(void);
void parser(const char **s, t_flags *flags);
void parse_min_width_precison(t_flags *flags, const char **s);

// ft_printf_printing.c
int padding(t_flags *flags, int len_value);
int ft_putchar(char value);
int ft_putstr(const char *value, t_flags *flags);
int putnbr(void *value);
int puthexa(void *value);

// fr_printf_utils.c
int is_num(char c);
int is_flag(char c);
int ft_strlen(char *s, t_flags *flags);

int min_width();
int positive_sign();
int space();
int left_align();
int zero_padding();
int precision();
int alt_hexa();

#endif