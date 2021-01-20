/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:38:28 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/20 15:13:53 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_p(t_cdata *cdata, va_list args)
{
	(void)cdata;
	(void)args;

	if (cdata->flag_minus == 0)
		ft_putxchary_fd(, ' ', 1);
	write(1, "0x", 2);
	
}