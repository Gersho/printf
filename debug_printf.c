/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:38:37 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/17 13:29:07 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	debug_print_cdata(t_cdata *cdata)
{
	printf("----------------\n");
	printf("cdata->type: %c\n", cdata->type);
	printf("cdata->type(int): %i\n", (int)cdata->type);
	printf("cdata->flag_minus: %i\n", cdata->flag_minus);
	printf("cdata->flag_zero: %i\n", cdata->flag_zero);
	printf("cdata->width: %i\n", cdata->width);
	printf("cdata->prec: %i\n", cdata->prec);
	printf("cdata->int_isneg: %i\n", cdata->int_isneg);
	printf("cdata->len: %i\n", cdata->len);
	printf("cdata->printed: %i\n", cdata->printed);
	printf("----------------\n");
}
