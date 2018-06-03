/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:59:56 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/31 18:12:30 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	handles unsigned conversions
*/

void	ft_upn(uintmax_t n, char *buf, int type, int *i, int base)
{
	uintmax_t	tmp;
	int			c;

	tmp = n;
	if (tmp < 0)
	{
		tmp = -tmp;
		buf[(*i)++] = '-';
	}
	if (tmp >= base)
	{
		ft_pn(tmp / base, buf, type, i, base);
		ft_pn(tmp % base, buf, type, i, base);
	}
	else
	{
		c = (type == 11) ? 'A' : 'a';
		buf[(*i)++] = tmp > 9 ? tmp - 10 + c : tmp + '0';
	}
}

/*
**	handles signed conversions
*/

void	ft_spn(intmax_t n, char *buf, int type, int *i, int base)
{
	intmax_t	tmp;
	int			c;

	tmp = n;
	if (tmp < 0)
	{
		tmp = -tmp;
		buf[(*i)++] = '-';
	}
	if (tmp >= base)
	{
		ft_pn(tmp / base, buf, type, i, base);
		ft_pn(tmp % base, buf, type, i, base);
	}
	else
	{
		c = (type == 11) ? 'A' : 'a';
		buf[(*i)++] = tmp > 9 ? tmp - 10 + c : tmp + '0';
	}
}
