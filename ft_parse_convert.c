/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:45:33 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/12 15:37:46 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_convert(char *str, t_cdata *convert_data)
{
	convert_data->len = 0;
	ft_parse_flag(str, convert_data);
	ft_parse_width(str + convert_data->len, convert_data);
	ft_parse_prec();
	//type
	
	//faire la convertion

}
