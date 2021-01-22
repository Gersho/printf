/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:38:28 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/22 16:32:19 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_p(t_cdata *cdata, va_list args)
{
	unsigned long long int		value;
	int							str_len;
	char						*str;

	value = (unsigned long long int)va_arg(args, void *);
	//value = va_arg(args, unsigned long long int);
	str = ft_llutoa_base(value, "0123456789abcdef");
	str_len = ft_strlen(str);
	if (cdata->flag_minus == 0)
		ft_putxchary_fd(cdata->width - str_len - 2, ' ', 1);
	write(1, "0x", 2);
	ft_putstr_fd(str, 1);
	if (cdata->flag_minus == 1)
		ft_putxchary_fd(cdata->width - str_len - 2, ' ', 1);
	if (cdata->width > (str_len + 2))
		cdata->printed += cdata->width;
	else
		cdata->printed += str_len + 2;
}
