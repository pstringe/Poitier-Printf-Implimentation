/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:18:34 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/13 12:25:40 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void init_f(t_f *flags, t_m *m)
{
	int f;

	f = m->place->flags;
	flags->m = f & MINUS;
	flags->p = f & PLUS;
	flags->s = f & SPACE;
	flags->z = f & ZERO;
	flags->h = f & HASH;
}

static int	space_left(t_num *n, t_f f)
{
	char	w;
	int		s;
	int		i;

	s = n->base == 16 ? 2 : 1;
	w = f.z ? '0' : ' ';
	i = -1;
	while (n->b_conv[++i] == w);
	return (i >= s ? i : 0);
}

void 		flags(t_m *m, t_num *n)
{
	int		ol;
	int		pos;
	t_f		flags;
	char 	tmp[100];

	init_f(&flags, m);
	ol = ft_strlen(n->b_conv);
	if (flags.h && ft_strncmp("0", n->b_conv, ft_strlen(n->b_conv)))
	{
		if (n->base == 16)
		{
			if ((pos = space_left(n, flags)))
				ft_memcpy(n->b_conv + (*n->b_conv == ' '? pos - 2 : 0), (m->place->type == 10 ? "0x": "0X"), 2);
			else
			{
				ft_bzero(tmp, 100);
				ft_memcpy(tmp, (m->place->type == 10 ? "0x": "0X"), 2);
				ft_strlcat(tmp, n->b_conv, 100);
				ft_memcpy(n->b_conv, tmp, ((flags.m && ol <= m->place->width) ? m->place->width : ft_strlen(tmp)));
			}
		}
		else if (n->base == 8 && n->b_conv[0] != '0')
		{
			if ((pos = space_left(n, flags)))
				n->b_conv[pos - 1] = '0';
			else
			{
				ft_bzero(tmp, 100);
				ft_memcpy(tmp, "0", 1);
				ft_strlcat(tmp, n->b_conv, 100);
				ft_memcpy(n->b_conv, tmp, ft_strlen(tmp));
			}
		}
	}
}
