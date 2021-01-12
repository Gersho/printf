/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:56:55 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/12 17:16:23 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_flags(char *str, t_cdata *cdata)
{
	int		i;

	i = 0;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			cdata->flag_minus = 1;
		if (str[i] == '0')
			cdata->flag_zero = 1;
		i++;
	}
	cdata->len += i;
}
