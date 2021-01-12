/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:56:55 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/11 17:05:16 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_flags(char *str, t_cdata *convert_data)
{
	int		i;

	i = 0;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			convert_data->flag_minus = 1;
		if (str[i] == '0')
			convert_data->flag_zero = 1;
		i++;
	}
	convert_data->len += i;
}
