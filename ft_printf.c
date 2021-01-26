/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:45:21 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/26 13:45:01 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_conversion(const char *str, t_cdata *cdata, va_list args)
{
	ft_initialise_cdata(cdata);
	ft_parse_convert(str, cdata, args);
	if ((ft_print_conversion(cdata, args)) == -1)
		return (-1);
	return (0);
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
			if ((manage_conversion(str + i, cdata, args)) == -1)
				return (-1);
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
