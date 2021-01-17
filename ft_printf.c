/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:45:21 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/16 16:59:45 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_conversion(const char *str, t_cdata *cdata, va_list args)
{
	ft_initialise_cdata(cdata);

	if (ft_parse_convert(str + cdata->len, cdata, args) == -1)
		return (-1);
	//print
	ft_print_conversion(cdata, args);
	return (cdata->printed);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			error_handler;
	t_cdata		*cdata;
	//int			print_len;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(cdata = malloc(sizeof(t_cdata))))
				return (-1);
			if (!(error_handler = manage_conversion(str + i, cdata, args)))
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


/*

Fusionner ft_parse_width et ft_parse_prec


en cas de mauvaie conversion, abort conversion en cour et continuer
*/