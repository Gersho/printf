/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:54:13 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/15 12:58:48 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_c(t_cdata *cdata, va_list args)
{
	char	filler;
	char	to_print;

	to_print = va_arg(args, char);
	filler = ' ';
	if (cdata->flag_zero == 1 && cdata->flag_minus == 0)
		filler = '0';
	if (cdata->width == 0)
		cdata->width = 1;
	if (cdata->flag_minus == 1)
	{
		ft_putchar_fd(to_print, 1);
		ft_putxchary_fd(cdata->width - 1, filler, 1);
	}
	else
	{
		ft_putxchary_fd(cdata->width - 1, filler, 1);
		ft_putchar_fd(to_print, 1);
	}
	cdata->printed += cdata->width;
}
