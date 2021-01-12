/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:45:21 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/12 17:15:37 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		manage_conversion(char *str, t_cdata *cdata, va_list args)
{
	ft_initialise_cdata(cdata);
	ft_parse_convert(str, cdata, args);
	//if valid, print conversion, else return -1
	//doit return -1 en cas de probleme
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			error_handler;
	t_cdata		*cdata;
	int			print_len;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(cdata = malloc(sizeof(t_cdata))))
				return (-1);
			if (!(error_handler = manage_conversion(str + i + 1, cdata, args)))
				return (-1);
			i += cdata->len;
			free(cdata);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (i);
}
