/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:06:17 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/06 21:30:12 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	determines what charater should be prepended to the number string
*/

int 	get_signchar(t_num *n, int flags)
{
	if (n->sign < 0)
		return ('-');
	if (flags & SPACE)
		return (' ');
	if (flags & PLUS)
		return ('+');
	return (0);
}

/*
**	edits number string to accomodate precision specification
*/

void	num_prcs(t_m *m, t_num *n, int pr)
{
	int		l;
	char 	*tmp;
	char	*p;
	int		h;

	h = (m->place->flags & HASH) ? 2 : 0;
	p = (l = ft_strlen(n->b_conv)) < pr ? ft_strnew(pr - l - h) : NULL;
	if (p)
	{
		tmp = ft_strdup(n->b_conv);
		ft_memset(p, '0', pr - l - (h ? 2 : 0));
		if (h)
			ft_memcpy(n->b_conv, (m->place->type == 10 ? "0x" : "0X"), 2);
		ft_memcpy(n->b_conv + (h ? 2 : 0), p, pr - l);
		ft_memdel((void**)&p);
		ft_memcpy(n->b_conv + pr - l + (h ? 2 : 0), tmp, l);
		ft_memdel((void**)&tmp);
	}
	else if (h)
	{
		tmp = ft_strdup(n->b_conv);
		ft_memcpy(n->b_conv, (m->place->type == 10 ? "0x" : "0X"), 2);
		ft_memcpy(n->b_conv + 2, tmp, ft_strlen(tmp));
	}
	n->idx += pr - l;
}

/*
**	appplies padding at the begining of the string while prepending the appropriate extara
**	characters as determines by flags
*/

void		append(t_num *n, t_w *spec, int wd, int flags)
{
	char	*tmp;
	
	spec->l = ft_strlen(n->b_conv);
	tmp = ft_strdup(n->b_conv);
	ft_memcpy(n->b_conv, spec->w, wd - spec->l);
	if ((spec->e_char = (!spec->z && (n->sign < 0 || flags & SPACE || flags & PLUS))))
	{
		n->b_conv[wd - spec->l - 1] = get_signchar(n, flags);
		n->neg = 1;	
	}
	ft_memdel((void**)&spec->w);
	ft_memcpy(n->b_conv + wd - spec->l, tmp, spec->l);
	ft_memdel((void**)&tmp);
}

/*
**	applies padding at the end of the string  while prepending the appropriate extara
**	characters as determines by flags
*/

void		prepend(t_num *n, t_w *spec, int wd, int flags)
{
	char	*tmp;

	spec->l = ft_strlen(n->b_conv);
	tmp = ft_strdup(n->b_conv);
	if ((spec->e_char = (!spec->z && (n->sign < 0 || flags & SPACE || flags & PLUS))))
	{
		n->b_conv[0] = get_signchar(n, flags);
		ft_memcpy(n->b_conv + 1, tmp, ft_strlen(n->b_conv));
	}
	else
		ft_memcpy(n->b_conv, tmp, ft_strlen(n->b_conv));
	ft_memcpy(n->b_conv + ft_strlen(tmp) + (spec->e_char ? 1 : 0), spec->w, wd + (spec->e_char ? -2 : -1));
	ft_memdel((void**)&spec->w);
	ft_memdel((void**)&tmp);
}

/*
**	edits string to accomadte sign and any other extra characters needed for flags
**	while complying with width specification
*/

void 	num_wdth(t_num *n, int wd, int flags)
{
	t_w	spec;
	char *tmp;
	char s;

	spec.z = flags & ZERO;
	spec.w = (spec.l = ft_strlen(n->b_conv)) < wd ? ft_strnew(wd - spec.l) : NULL;
	spec.e_char = 0;
	if (spec.w)
		ft_memset(spec.w, (spec.z ? '0' : ' '), (!spec.z && wd - spec.l > 0 ? wd - spec.l : wd - spec.l));
	if (spec.w && !(flags & MINUS))
		append(n, &spec, wd, flags);
	else if (spec.w && (flags & MINUS))
		prepend(n, &spec, wd, flags);
	else if ((s = get_signchar(n, flags)))
	{
		tmp = ft_strdup(n->b_conv);
		n->b_conv[0] = get_signchar(n, flags);
		ft_memcpy(n->b_conv + 1, tmp, ft_strlen(n->b_conv));
		ft_memdel((void**)&tmp);
	}
	n->idx += wd - spec.l + (spec.e_char ? -1 : 0);
}
