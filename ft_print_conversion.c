/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:25:11 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/18 14:27:11 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_conversion(t_cdata *cdata, va_list args)
{
	if (cdata->type == 'c')
		ft_print_c(cdata, args);
	if (cdata->type == 's')
		ft_print_s(cdata, args);
	//if (cdata->type == 'p')
	//	ft_print_p(cdata, args);
	if (cdata->type == 'd' || cdata->type == 'i')
		ft_print_i(cdata, args);
	if (cdata->type == 'u')
		ft_print_u(cdata, args);
	//if (cdata->type == 'x')
	//	ft_print_xlow(cdata, args);
	//if (cdata->type == 'X')
	//	ft_print_xupp(cdata, args);
	if (cdata->type == '%')
		ft_print_prct(cdata);
	return ;
}
