/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:50:58 by pstringe          #+#    #+#             */
/*   Updated: 2018/07/23 11:26:34 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	determines what base should be passed to ft_pn base on the type of the
**	conversion
*/

int		get_base(t_m *m)
{
	if (m->place->type == 3)
		return (10);
	if (m->place->type == 4)
		return (10);
	if (m->place->type == 5)
		return (10);
	if (m->place->type == 6)
		return (8);
	if (m->place->type == 7)
		return (8);
	if (m->place->type == 10)
		return (16);
	if (m->place->type == 11)
		return (16);
	return (0);
}

/*
**	edits string according to precision
*/

void	num_prcs(char buf[100], int pr, int *i)
{
	int		l;
	char	*tmp;
	char	*p;

	p = (l = ft_strlen(buf)) < pr ? ft_strnew(pr - l) : NULL;
	if (p)
	{
		tmp = ft_strdup(buf);
		ft_memset(p, '0', pr - l);
		ft_memcpy(buf, p, pr - l);
		ft_memdel((void**)&p);
		ft_memcpy(buf + pr - l, tmp, l);
		ft_memdel((void**)&tmp);
	}
	*i += pr - l;
}

/*
**	edits string according to width specifications
*/

void 	num_wdth(char buf[100], int wd, int flags, int *neg, int *i)
{
	int		l;
	int		z;
	char 	*tmp;
	char	*w;

	z = flags & ZERO;
	w = (l = ft_strlen(buf)) < wd ? ft_strnew(wd - l) : NULL;
	if (w)
		ft_memset(w, (z ? '0' : ' '), (!z && wd - l > 0 ? wd - l : wd - l - 1));
	if (w && !(flags & MINUS))
	{
		tmp = ft_strdup(buf);
		ft_memcpy(buf, w, wd - l);
		if (!z && *neg < 0)
		{
			buf[wd - l - 1] = '-';
			*neg = 1;	
		}
		ft_memdel((void**)&w);
		ft_memcpy(buf + wd - l, tmp, l);
		ft_memdel((void**)&tmp);
	}
	else if (w && (flags & MINUS))
		ft_memcpy(buf + ft_strlen(buf), w, wd - 1);
	*i += wd - l;
}
