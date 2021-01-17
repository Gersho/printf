/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_cdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:53:40 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/16 16:58:49 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialise_cdata(t_cdata *cdata)
{
	cdata->type = 0;
	cdata->flag_minus = 0;
	cdata->flag_zero = 0;
	cdata->width = 0;
	cdata->prec = 0;
	cdata->int_isneg = 0;
	cdata->len = 1;
	cdata->printed = 0;
}
