/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:54:16 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/02 19:43:12 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	converts numbers to base and places in buffer
*/

void	ft_spn(intmax_t nb, t_num *n, t_m *m)
{
	int			c;

	if (nb < 0)
	{
		nb = -nb;
		n->sign = -1;
	}
	if (nb >= (intmax_t)n->base)
	{
		ft_spn(nb / n->base, n, m);
		ft_spn(nb % n->base, n, m);
	}
	else
	{
		c = (m->place->type == 11) ? 'A' : 'a';
		n->b_conv[(n->idx)++] = nb > 9 ? nb - 10 + c : nb + '0';
	}
}

void	ft_upn(uintmax_t nb, t_num *n, t_m *m)
{
	int			c;

	if (nb >= (uintmax_t)n->base)
	{
		ft_upn(nb / n->base, n, m);
		ft_upn(nb % n->base, n, m);
	}
	else
	{
		c = (m->place->type == 11) ? 'A' : 'a';
		n->b_conv[(n->idx)++] = nb > 9 ? nb - 10 + c : nb + '0';
	}
}

/*
**	checks that a character is a flag
*/

int		is_flag(char c)
{
	int		i;
	char	*flags;

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
	write(1, buf, m->pos_b);
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
