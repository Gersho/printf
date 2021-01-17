/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_cdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:53:40 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/17 16:25:08 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialise_cdata(t_cdata *cdata)
{
	cdata->type = 0;
	cdata->flag_minus = 0;
	cdata->flag_zero = 0;
	cdata->width = 0;
	cdata->prec = -1;
	cdata->int_isneg = 0;
	cdata->len = 0;
	cdata->printed = 0;
}
