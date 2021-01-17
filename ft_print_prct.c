/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:54:23 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/16 17:00:04 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_prct(t_cdata *cdata)
{
	char	filler;

	filler = ' ';
	if (cdata->flag_zero == 1 && cdata->flag_minus == 0)
		filler = '0';
	if (cdata->width == 0)
		cdata->width = 1;
	if (cdata->flag_minus == 1)
	{
		ft_putchar_fd('%', 1);
		ft_putxchary_fd(cdata->width - 1, filler, 1);
	}
	else
	{
		ft_putxchary_fd(cdata->width - 1, filler, 1);
		ft_putchar_fd('%', 1);
	}
	cdata->printed += cdata->width;
}
