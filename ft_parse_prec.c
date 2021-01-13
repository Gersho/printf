/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:28:50 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/13 10:33:59 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_prec(char *str, t_cdata *cdata, va_list args)
{
	int				i;
	long int		nb;

	if (str[0] == '*')
	{
		cdata->prec = va_arg(args, int);
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
	cdata->prec = nb;
	cdata->len += i;
}
