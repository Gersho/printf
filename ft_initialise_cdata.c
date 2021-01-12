/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_cdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:53:40 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/12 17:17:08 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initialise_cdata(t_cdata *cdata)
{
	cdata->type = NULL;
	cdata->flag_minus = NULL;
	cdata->flag_zero = NULL;
	cdata->width = NULL;
	cdata->prec = NULL;
	cdata->len = 0;
	cdata->is_valid = 1;
	cdata->printed = 0;
}
