/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:25:11 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/13 13:52:37 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_conversion(t_cdata *cdata, va_list args)
{
	if (cdata->type == 'c')
		ft_handle_c(cdata, args);
	if (cdata->type == 's')
		ft_handle_s(cdata, args);
	if (cdata->type == 'p')
		ft_handle_p(cdata, args);
	if (cdata->type == 'd' || cdata->type == 'i')
		ft_handle_i(cdata, args);
	if (cdata->type == 'u')
		ft_handle_u(cdata, args);
	if (cdata->type == 'x')
		ft_handle_xlow(cdata, args);
	if (cdata->type == 'X')
		ft_handle_xupp(cdata, args);
	if (cdata->type == '%')
		ft_handle_prct(cdata);
	return ;
}
