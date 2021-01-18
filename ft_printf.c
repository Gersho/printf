/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:45:21 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/18 14:17:00 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_conversion(const char *str, t_cdata *cdata, va_list args)
{
	//printf("in manage conversion str:%s\n", str);
	ft_initialise_cdata(cdata);
	/*
	if (ft_parse_convert(str + cdata->len, cdata, args) == -1)
		return (-1);
		*/
	ft_parse_convert(str, cdata, args);
	//printf("coucou3\n");
	debug_print_cdata(cdata);
	ft_print_conversion(cdata, args);
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
		//printf("CURRENT:str[%i]:%c ==>str:%s\n", i, str[i], (str+i));
		if (str[i] == '%')
		{
			if (!(cdata = malloc(sizeof(t_cdata))))
				return (-1);
			//printf("%%found i:%i -- str+i:%s\n", i, (str+i));
			manage_conversion(str + i, cdata, args);
			//printf(" AFTER PRINT i:%i  // cdata->len:%i\n", i, cdata->len);
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


/*

Fusionner ft_parse_width et ft_parse_prec


en cas de mauvaie conversion, abort conversion en cour et continuer
*/