/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:45:21 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/12 13:17:31 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		manage_conversion(char *str, t_cdata *convert_data)
{
	ft_initialise_cdata(convert_data);
	ft_parse_convert(str, convert_data);
	//if valid, print conversion, else return -1
	//doit return -1 en cas de probleme
}

int		ft_printf(const char *str, ...)
{
	va_list		start;
	int			i;
	int			error_handler;
	t_cdata		*convert_data;
	int			print_len;

	i = 0;
	va_start(start, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(convert_data = malloc(sizeof(t_cdata))))
				return (-1);
			if (!(error_handler = manage_conversion(str + i + 1, convert_data)))
				return (-1);
			i += convert_data->len;
			free(convert_data);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(start);
	return (i);
}
