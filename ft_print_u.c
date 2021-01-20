/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:24:09 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/20 13:47:47 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(t_cdata *cdata, va_list args)
{
	char			*str;
	int				len;
	unsigned int	value;
	char			filler;
	int				need_free;

	value = va_arg(args, unsigned int);
	need_free = 0;
	if (value == 0 && cdata->prec == 0)
		str = "";
	else
		{
			str = ft_utoa(value);
			need_free = 1;
		}
	len = (int)ft_strlen(str);
	filler = ' ';
	if (cdata->flag_minus == 0 && cdata->flag_zero == 1 && cdata->prec < 0)
		filler = '0';
	//printf("filler is->%c<-\n", filler);
	if (cdata->prec < len)
		cdata->prec = len;
	if (cdata->flag_minus == 0)
		ft_putxchary_fd(cdata->width - cdata->prec, filler, 1);
	ft_putxchary_fd(cdata->prec - len, '0', 1);
	ft_putstr_fd(str, 1);
	if (cdata->flag_minus == 1)
		ft_putxchary_fd(cdata->width - cdata->prec, ' ', 1);
	if (cdata->width > cdata->prec)
		cdata->printed += cdata->width;
	else 
		cdata->printed += cdata->prec;
	if(need_free)
		free(str);
	//free(str);
}