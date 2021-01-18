/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:37:56 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/18 12:54:00 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_width(const char *str, t_cdata *cdata, va_list args)
{
	int				i;
	long int		nb;

	//printf("in parse widths! ==> str:%s\n", str);
	if (str[0] == '*')
	{
		cdata->width = va_arg(args, int);
		if (cdata->width < 0)
		{
			cdata->width *= -1;
			cdata->flag_minus = 1;
		}
		cdata->len += 1;
		return ;
	}
	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	cdata->width = nb;
	cdata->len += i;
}
