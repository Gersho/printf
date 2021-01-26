/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:09:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/26 16:53:10 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_print(t_cdata *cdata, int str_len, char *str)
{
	char	filler;

	filler = ' ';
	if (cdata->flag_zero == 1 && cdata->flag_minus == 0)
		filler = '0';
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
}

int		ft_print_i(t_cdata *cdata, va_list args)
{
	long int	value;
	int			str_len;
	char		*str;
	int			need_free;
	char		*temp;

	if (cdata->prec != -1)
		cdata->flag_zero = 0;
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
		if (!str)
			return (-1);
		need_free = 1;
	}
	str_len = (int)ft_strlen(str);
	while (str_len < cdata->prec)
	{
		temp = ft_strjoin("0", str);
		free(str);
		if (!temp)
			return (-1);
		str = temp;
		str_len++;
	}
	ft_handle_print(cdata, str_len, str);
	if (need_free)
		free(str);
	return (0);
}
