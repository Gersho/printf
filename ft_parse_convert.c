/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:45:33 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/12 17:45:22 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_convert(char *str, t_cdata *cdata, va_list args)
{
	ft_parse_flag(str, cdata);
	ft_parse_width(str + cdata->len, cdata, args);
	if (//si '.' parser la prec)
	ft_parse_prec();
	//type
}
