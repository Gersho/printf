/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:25:11 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/24 15:43:35 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(t_cdata *cdata, va_list args)
{
	if (cdata->type == 'c')
		ft_print_c(cdata, args);
	if (cdata->type == 's')
		if ((ft_print_s(cdata, args)) == -1)
			return (-1);
	if (cdata->type == 'p')
		if ((ft_print_p(cdata, args)) == -1)
			return (-1);
	if (cdata->type == 'd' || cdata->type == 'i')
		if ((ft_print_i(cdata, args)) == -1)
			return (-1);
	if (cdata->type == 'u')
		if ((ft_print_u(cdata, args)) == -1)
			return (-1);
	if (cdata->type == 'x' || cdata->type == 'X')
		if ((ft_print_x(cdata, args)) == -1)
			return (-1);
	if (cdata->type == '%')
		ft_print_prct(cdata);
	return (0);
}
