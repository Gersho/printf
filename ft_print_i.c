/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:09:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/24 14:30:56 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_i(t_cdata *cdata, va_list args)
{
	long int	value;
	int			str_len;
	char		filler;
	char		*str;
	int			need_free;
	char		*temp;

	if (cdata->prec != -1)
		cdata->flag_zero = 0;
	filler = ' ';
	if (cdata->flag_zero == 1 && cdata->flag_minus == 0)
		filler = '0';
	if ((value = (long int)va_arg(args, int)) < 0)
	{
		value *= -1;
		cdata->int_isneg = 1;
	}
	need_free = 0;
	if (value == 0 && cdata->prec == 0)
		str = "";
	else
	{
		str = ft_ltoa(value);
		need_free = 1;
	}
	str_len = (int)ft_strlen(str);
	while (str_len < cdata->prec)
	{
		temp = ft_strjoin("0", str);
		free(str);
		str = temp;
		str_len++;
	}
	if ((cdata->int_isneg == 1 && filler == '0'))
		ft_putchar_fd('-', 1);
	if (cdata->width > (str_len + cdata->int_isneg) && cdata->flag_minus == 0)
		ft_putxchary_fd(cdata->width - (str_len + cdata->int_isneg), filler, 1);
	if ((cdata->int_isneg == 1 && filler == ' '))
		ft_putchar_fd('-', 1);
	ft_putstr_fd(str, 1);
	if (cdata->width > (str_len + cdata->int_isneg) && cdata->flag_minus == 1)
		ft_putxchary_fd(cdata->width - (str_len + cdata->int_isneg), filler, 1);
	if (cdata->width > (str_len + cdata->int_isneg))
		cdata->printed += cdata->width;
	else
		cdata->printed += (str_len + cdata->int_isneg);
	if (need_free)
		free(str);
}
