/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:45:33 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/17 15:37:17 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_convert(const char *str, t_cdata *cdata, va_list args)
{
	//printf("in parse convert! ==> str:%s\n", str);
	ft_parse_flags(str + cdata->len, cdata);
	ft_parse_width(str + cdata->len, cdata, args);
	if (str[cdata->len] == '.')
	{
		cdata->len += 1;
		ft_parse_prec(str + cdata->len, cdata, args);
	}
	//printf("before str index c ==>str[cdata->len]:%c\n", str[cdata->len]);
	if (ft_str_index_c("cspdiuxX%", str[cdata->len]) != -1)
	{
		cdata->type = str[cdata->len];
		cdata->len++;
	}
	
	/*
	if (ft_str_index_c("cspdiuxX%", str[cdata->len]) == -1)
		return (-1);
	*/
	//cdata->type = str[cdata->len];
	return (0);
}
