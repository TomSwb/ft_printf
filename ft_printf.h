/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:53:57 by tomswb            #+#    #+#             */
/*   Updated: 2026/09/30 00:27:56 by tomswb           ###   ########.fr       */
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
	int		left_align;
	int		zero_padding;
	int		positive_sign;
	int		alt_hexa;
	int		spaces;

	int	min_width;
	int		precision;
	int	precision_len;

	char	converter;
}	t_flags;

// *** Functions *** //

// ft_printf.c
int		ft_printf(const char *, ...);
void	printer_manager(t_flags *flags, va_list *args, int *count);
void	printer_manager_char(t_flags *flags, va_list *args, int *count);
void	printer_manager_decimal(t_flags *flags, va_list *args, int *count);
void	printer_manager_hexa(t_flags *flags, va_list *args, int *count);

// ft_printf_parsing.c
t_flags	init_flags(void);
void	parser(const char **s, t_flags *flags);
void	parse_min_width_precison(t_flags *flags, const char **s);
int		is_num(char c);
int		is_flag(char c);

// ft_printf_printing.c
int		padding(t_flags *flags, int len_value);
int		print_char(char value);
int		print_s(const char *value, t_flags *flags);
int		print_deci(void *value);
int		print_hexa(void *value);

// fr_printf_utils.c
int	s_len(char *s, t_flags *flags);
int	deci_len(long value, t_flags *flags);

#endif