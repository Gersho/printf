/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:04:50 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/26 15:38:35 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_print(t_cdata *cdata, char *str)
{
	int							str_len;
	char						filler;

	str_len = ft_strlen(str);
	if (cdata->prec != -1)
		cdata->flag_zero = 0;
	filler = cdata->flag_zero == 1 ? '0' : ' ';
	if (cdata->prec < str_len)
		cdata->prec = str_len;
	if (cdata->width > cdata->prec && cdata->flag_minus == 0)
		ft_putxchary_fd(cdata->width - cdata->prec, filler, 1);
	if (cdata->prec > str_len)
		ft_putxchary_fd(cdata->prec - str_len, '0', 1);
	ft_putstr_fd(str, 1);
	if (cdata->width > cdata->prec && cdata->flag_minus == 1)
		ft_putxchary_fd(cdata->width - cdata->prec, ' ', 1);
	if (cdata->width > cdata->prec)
		cdata->printed += cdata->width;
	else
		cdata->printed += cdata->prec;
}

int			ft_print_x(t_cdata *cdata, va_list args)
{
	unsigned int				value;
	char						*str;
	int							need_free;

	value = (unsigned int)va_arg(args, int);
	need_free = 1;
	if (value == 0 && cdata->prec == 0)
	{
		need_free = 0;
		str = "";
	}
	else if (cdata->type == 'x')
		str = ft_llutoa_base(value, "0123456789abcdef");
	else
		str = ft_llutoa_base(value, "0123456789ABCDEF");
	if (!str)
		return (-1);
	ft_handle_print(cdata, str);
	if (need_free)
		free(str);
	return (0);
}
