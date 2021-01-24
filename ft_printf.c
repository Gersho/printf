/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:45:21 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/24 14:21:54 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_conversion(const char *str, t_cdata *cdata, va_list args)
{
	ft_initialise_cdata(cdata);
	ft_parse_convert(str, cdata, args);
	ft_print_conversion(cdata, args);
	// wtf ?
	return (cdata->printed);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	t_cdata		*cdata;
	int			print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(cdata = malloc(sizeof(t_cdata))))
				return (-1);
			manage_conversion(str + i, cdata, args);
			i += cdata->len;
			print_len += cdata->printed;
			free(cdata);
		}
		else
		{
			write(1, &str[i], 1);
			print_len++;
			i++;
		}
	}
	va_end(args);
	return (print_len);
}
