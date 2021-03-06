/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:48:55 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/24 15:44:59 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_cdata
{
	char		type;
	int			flag_minus;
	int			flag_zero;
	int			int_isneg;
	int			width;
	int			prec;
	int			len;
	int			printed;
}				t_cdata;

int				ft_printf(const char *str, ...);
void			ft_parse_flags(const char *str, t_cdata *cdata);
int				ft_parse_convert(const char *str, t_cdata *cdata, va_list args);
void			ft_initialise_cdata(t_cdata *cdata);
void			ft_parse_width(const char *str, t_cdata *cdata, va_list args);
void			ft_parse_prec(const char *str, t_cdata *cdata, va_list args);
void			ft_print_prct(t_cdata *cdata);
void			ft_print_c(t_cdata *cdata, va_list args);
int				ft_print_s(t_cdata *cdata, va_list args);
int				ft_print_i(t_cdata *cdata, va_list args);
int				ft_print_u(t_cdata *cdata, va_list args);
int				ft_print_conversion(t_cdata *cdata, va_list args);
int				ft_print_p(t_cdata *cdata, va_list args);
int				ft_print_x(t_cdata *cdata, va_list args);
void			debug_print_cdata(t_cdata *cdata);
#endif
