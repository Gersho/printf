/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:09:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/15 17:22:13 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_i(t_cdata *cdata, va_list args)
{
	char		*str;
	int			len;
	char		filler;
	char		*ptr;

	str = ft_itoa(va_arg(args, int));
	if (cdata->prec == NULL)
		cdata->prec = ft_strlen(str);
	filler = ' ';
	if (cdata->flag_zero == 1 && cdata->flag_minus == 0)
		filler = '0';
//	if (cdata->prec > ft_strlen(str))
//concat des 0?
	ptr = ft_substr(str, 0, cdata->prec);


	if (cdata->flag_minus == 1)
	{
		ft_putstr_fd(ptr, 1);
		ft_putxchary_fd(cdata->width - cdata->prec, filler, 1);
	}
	else
	{
		ft_putxchary_fd(cdata->width - cdata->prec, filler, 1);
		ft_putstr_fd(ptr, 1);
	}
	free(ptr);
	free(str);
	cdata->printed = cdata->width > cdata->prec ? cdata->width : cdata->prec;
}

