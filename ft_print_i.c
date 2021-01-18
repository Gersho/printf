/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:09:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/18 14:20:01 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_i(t_cdata *cdata, va_list args)
{
	char		*str;
	int			value;
	char		filler;
	char		*ptr;


	if ((value = va_arg(args, int)) < 0)
	{
		value *= -1;
		cdata->int_isneg = 1;
	}
	if (cdata->prec == 0 && value == 0)
	{
		return ;
	}
	str = ft_itoa(value);
	if ( (cdata->prec < ((int)ft_strlen(str) + 1) && cdata->int_isneg == 1)\
		|| (cdata->prec < (int)ft_strlen(str) && cdata->int_isneg == 0))
		cdata->prec = (int)ft_strlen(str);

/* 	if (cdata->prec == 0 || cdata->prec < 0)
		cdata->prec = (int)ft_strlen(str); */
	filler = ' ';
/*  	if (cdata->flag_zero == 1 && cdata->flag_minus == 0)
		filler = '0';  */
	ptr = ft_substr(str, 0, cdata->prec);
	if ((cdata->int_isneg == 1 && cdata->flag_minus == 1) \
		|| (cdata->int_isneg == 1 && cdata->flag_minus == 0 && cdata->flag_zero == 1))
	{
		ft_putchar_fd('-', 1);
		cdata->printed++;
	}
	if (cdata->width > (cdata->prec + cdata->int_isneg) && cdata->flag_minus == 0)
		{
			ft_putxchary_fd(cdata->width - (cdata->prec + cdata->int_isneg), filler, 1);
			cdata->printed += cdata->width - (cdata->prec + cdata->int_isneg);
		}
	if (cdata->int_isneg == 1 && cdata->flag_minus == 0)
		{
			ft_putchar_fd('-', 1);
			cdata->printed++;
		}
	if (cdata->prec > (int)ft_strlen(str))
		{
			ft_putxchary_fd(cdata->prec - (int)ft_strlen(str), '0', 1);
			cdata->printed += cdata->prec - (int)ft_strlen(str);
		}
	ft_putstr_fd(ptr, 1);
	cdata->printed += (int)ft_strlen(ptr);
	if (cdata->width > (cdata->prec + cdata->int_isneg) && cdata->flag_minus == 1)
		{
			ft_putxchary_fd(cdata->width - (cdata->prec + cdata->int_isneg), filler, 1);
			cdata->printed += cdata->width - (cdata->prec + cdata->int_isneg);
		}
	free(ptr);
	free(str);
	
	//add cdata->printed


}
	// add cdata->printed
	//NE PAS OUBLIER DE FREE.
	/*
	if (filler == ' ')
	{
		if (cdata->width > (cdata->prec + cdata->int_isneg) && cdata->flag_minus == 0)
			ft_putxchary_fd(cdata->width - (cdata->prec + cdata->int_isneg), filler, 1);
		if (cdata->int_isneg == 1)
			ft_putchar_fd('-', 1);
		if (cdata->prec > ft_strlen(str))
			ft_putxchary_fd(cdata->prec - ft_strlen(str), '0', 1);
		ft_putstr_fd(ptr, 1);
		if (cdata->width > (cdata->prec + cdata->int_isneg) && cdata->flag_minus == 1)
			ft_putxchary_fd(cdata->width - (cdata->prec + cdata->int_isneg), filler, 1);
	}
	else
	{
		
	}
	*/
	// add cdata->printed
	//NE PAS OUBLIER DE FREE.

