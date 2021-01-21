/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:04:50 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/21 15:40:49 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x(t_cdata *cdata, va_list args)
{
	unsigned long long int		value;
	char						*str;
	int							str_len;
	char						filler;


	value = (unsigned long long int)va_arg(args, void *);
	if (cdata->type == 'x')
		str = ft_llutoa_base(value, "0123456789abcdef");
	else
		str = ft_llutoa_base(value, "0123456789ABCDEF");
	str_len = ft_strlen(str);
	if (cdata->prec != - 1)
		cdata->flag_zero = 0;
	filler = ' ';
	if (cdata->flag_zero == 1)
		filler = '0';
	if (cdata->prec < str_len)
		cdata->prec = str_len;
	if (cdata->width > cdata->prec && cdata->flag_minus == 0)
		ft_putxchary_fd(cdata->width - cdata->prec, filler, 1);
	if (cdata->prec > str_len)
		ft_putxchary_fd(cdata->prec - str_len, '0', 1);
	ft_putstr_fd(str, 1);
	if (cdata->width > cdata->prec && cdata->flag_minus == 1)
		ft_putxchary_fd(cdata->width - cdata->prec, ' ', 1);
	//cdata->printed
	if (cdata->width > cdata->prec)
		cdata->printed += cdata->width;
	else
		cdata->printed += cdata->prec;
	free(str);
}