/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:54:16 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/28 14:41:23 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	converts numbers to base and places in buffer
*/

void	ft_pn(long long n, t_m *m, char *buf, int base)
{
	long long tmp;

	tmp = n;
	if (tmp < 0)
	{
		tmp = -tmp;
		buf[m->pos_b++] = '-';
	}
	if (tmp >= base)
	{
		ft_pn(tmp / base, m, buf, base);
		ft_pn(tmp % base, m, buf, base);
	}
	else
		buf[m->pos_b++] = tmp > 9 ? tmp - 10 + (m->place->type == 'X' ? 'A' : 'a') : tmp + '0';
}

/*
**	checks that a character is a flag
*/

int		is_flag(char c)
{
	int		i;
	char 	*flags;

	flags = FLAGS;
	i = -1;
	while (flags[++i])
		if (c == flags[i])
			return (i + 1);
	return (0);
}

/*
**	prints the result
*/

void	put(t_m *m, char buf[MAX])
{
	write(1, buf, m->pos_b + 1);
}

/*
**	cleanup
*/

void	dstry(t_m *m)
{
	if (m->place)
		ft_memdel((void**)&m->place);
	va_end(m->ap);
	ft_memdel((void**)&m);
} 
