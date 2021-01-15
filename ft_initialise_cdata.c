/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_cdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:53:40 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/15 11:49:18 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initialise_cdata(t_cdata *cdata)
{
	cdata->type = NULL;
	cdata->flag_minus = 0;
	cdata->flag_zero = 0;
	cdata->width = NULL;
	cdata->prec = NULL;
	cdata->len = 1;
	cdata->printed = 0;
}
