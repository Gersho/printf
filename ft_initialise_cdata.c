/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_cdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:53:40 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/12 15:06:36 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initialise_cdata(t_cdata *convert_data)
{
	convert_data->type = NULL;
	convert_data->flag_minus = NULL;
	convert_data->flag_zero = NULL;
	convert_data->width = NULL;
	convert_data->prec = NULL;
	convert_data->len = 0;
	convert_data->is_valid = 1;
	convert_data->printed = 0;
}
