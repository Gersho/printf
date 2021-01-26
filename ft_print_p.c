/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:38:28 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/26 13:56:31 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_p(t_cdata *cdata, va_list args)
{
	unsigned long long int		value;
	int							str_len;
	char						*str;

	value = (unsigned long long int)va_arg(args, void *);
	if (value == 0)
		str = "0";
	else if (!(str = ft_llutoa_base(value, "0123456789abcdef")))
		return (-1);
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
	if (value != 0)
		free(str);
	return (0);
}
