/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:38:28 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/20 16:35:03 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_p(t_cdata *cdata, va_list args)
{
	unsigned long long int		value;
	//int							ptr_len;
	char						*str;
	(void)cdata;
	(void)args;

	value = (unsigned long long int)va_arg(args, void *);
	str = ft_lltuoa_base(value, "0123456789abcdef");
	printf("str after lltuoa_base:%s", str);
/* 	if (cdata->flag_minus == 0)
		ft_putxchary_fd(, ' ', 1); */
	write(1, "0x", 2);
	
}