/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:05:39 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/26 13:35:22 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_s(t_cdata *cdata, va_list args)
{
	char	filler;
	char	*ptr;
	char	*str;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	if (cdata->prec == -1 || cdata->prec > (int)ft_strlen(str))
		cdata->prec = ft_strlen(str);
	filler = cdata->flag_zero == 1 && cdata->flag_minus == 0 ? '0' : ' ';
	if (!(ptr = ft_substr(str, 0, cdata->prec)))
		return (-1);
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
	cdata->printed = cdata->width > cdata->prec ? cdata->width : cdata->prec;
	return (0);
}
