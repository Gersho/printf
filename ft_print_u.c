/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:24:09 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/26 16:22:35 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_print(t_cdata *cdata, int len, char *str)
{
	char	filler;

	filler = ' ';
	if (cdata->flag_minus == 0 && cdata->flag_zero == 1 && cdata->prec < 0)
		filler = '0';
	if (cdata->prec < len)
		cdata->prec = len;
	if (cdata->flag_minus == 0)
		ft_putxchary_fd(cdata->width - cdata->prec, filler, 1);
	ft_putxchary_fd(cdata->prec - len, '0', 1);
	ft_putstr_fd(str, 1);
	if (cdata->flag_minus == 1)
		ft_putxchary_fd(cdata->width - cdata->prec, ' ', 1);
	cdata->printed = cdata->width > cdata->prec ? cdata->width : cdata->prec;
}

int			ft_print_u(t_cdata *cdata, va_list args)
{
	char			*str;
	int				len;
	unsigned int	value;

	value = va_arg(args, unsigned int);
	if (value == 0 && cdata->prec == 0)
		str = "";
	else if (!(str = ft_utoa(value)))
		return (-1);
	len = (int)ft_strlen(str);
	ft_handle_print(cdata, len, str);
	if (!(value == 0 && cdata->prec == 0))
		free(str);
	return (0);
}
