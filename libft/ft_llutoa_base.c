/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:28:26 by kzennoun          #+#    #+#             */
/*   Updated: 2021/01/20 16:42:47 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_digit_count(long int n)
{
	int		i;

	if (n < 0)
		n *= -1;
	i = 1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_lltuoa_base(unsigned long long int nbr, char *base)
{
	int			base_len;

	base_len = ft_strlen(base);
	if (!check_base_is_valid(base) || base_len < 2)
		return ;
	while (nbr >= 0)
	{
		if (nbr < base_len)
		{
			ft_putchar(base[nbr]);
		}
		else
		{
			ft_putnbr_base(nbr / base_len, base);
			ft_putnbr_base(nbr % base_len, base);
		}
		nbr = -1;
	}
}

int		check_base_is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (base[i + j])
		{
			if (base[i] == base[i + j + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
