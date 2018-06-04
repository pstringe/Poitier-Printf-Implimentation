/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:49:20 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/04 15:29:46 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** writes resulting conversion to bufffer
*/

int		replace(t_m *m, char buf[MAX], char *conv)
{
	int	i;
	i = -1;
	while (conv[++i] && m->pos_b + i < MAX)
		buf[m->pos_b + i] = conv[i];
	m->pos_b += i;
	return (0);
}

/*
**	obtains the number's base depending on type
*/

void 	get_base(t_m *m, t_num *n)
{
	if (m->place->type == 3)
		n->base = 10;
	if (m->place->type == 4)
		n->base = 10;
	if (m->place->type == 6)
		n->base = 8;
	if (m->place->type == 7)
		n->base = 8;
	if (m->place->type == 10)
		n->base = 16;
	if (m->place->type == 11)
		n->base = 16;
}

/*
**	edits number string to accomodate precision specification
*/

void	num_prcs(t_num *n, int pr)
{
	int		l;
	char 	*tmp;
	char	*p;

	p = (l = ft_strlen(n->b_conv)) < pr ? ft_strnew(pr - l) : NULL;
	if (p)
	{
		tmp = ft_strdup(n->b_conv);
		ft_memset(p, '0', pr - l);
		ft_memcpy(n->b_conv, p, pr - l);
		ft_memdel((void**)&p);
		ft_memcpy(n->b_conv + pr - l, tmp, l);
		ft_memdel((void**)&tmp);
	}
	n->idx += pr - l;
}

/*
**	determines what charater should be prepended to the number string
*/

int 	get_signchar(t_num *n, int flags)
{
	if (n->neg < 0)
		return ('-');
	if (flags & SPACE)
		return (' ');
	if (flags & PLUS)
		return ('+');
	return (0);
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
	if ((spec->e_char = (!spec->z && (n->neg < 0 || flags & SPACE || flags & PLUS))))
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
	if ((spec->e_char = (!spec->z && (n->neg < 0 || flags & SPACE || flags & PLUS))))
	{
		n->b_conv[0] = get_signchar(n, flags);
		n->neg = 1;
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

	spec.z = flags & ZERO;
	spec.w = (spec.l = ft_strlen(n->b_conv)) < wd ? ft_strnew(wd - spec.l) : NULL;
	spec.e_char = 0;
	if (spec.w)
		ft_memset(spec.w, (spec.z ? '0' : ' '), (!spec.z && wd - spec.l > 0 ? wd - spec.l : wd - spec.l - 1));
	if (spec.w && !(flags & MINUS))
		append(n, &spec, wd, flags);
	else if (spec.w && (flags & MINUS))
		prepend(n, &spec, wd, flags);
	n->idx += wd - spec.l + (spec.e_char ? -1 : 0);
}

/*
**	determines how an argument is extracted for signed conversions
*/

void 	signed_conversion(t_m *m, t_num *n)
{
	if (m->place->len == -1)
		ft_spn((intmax_t)va_arg((m->ap), int), n, m);
	else if (m->place->len == 1)
		ft_spn((intmax_t)va_arg((m->ap), int), n, m);
	else if (m->place->len == 2)
		ft_spn((intmax_t)va_arg((m->ap), long), n, m);
	else if (m->place->len == 3)
		ft_spn((intmax_t)va_arg((m->ap), long long), n, m);
	else if (m->place->len == 4)
		ft_spn((intmax_t)va_arg((m->ap), intmax_t), n, m);
	else if (m->place->len == 5)
		ft_spn((intmax_t)va_arg((m->ap), size_t), n, m);
}

/*
**	determines how an argument is extracted fr unsigned conversions
*/

void 	unsigned_conversion(t_m *m, t_num *n)
{
	if (m->place->len == -1)
		ft_upn((uintmax_t)va_arg((m->ap), unsigned int), n, m);
	else if (m->place->len == 1)
		ft_upn((uintmax_t)va_arg((m->ap), unsigned int), n, m);
	else if (m->place->len == 2)
		ft_upn((uintmax_t)va_arg((m->ap), unsigned long), n, m);
	else if (m->place->len == 3)
		ft_upn((uintmax_t)va_arg((m->ap), unsigned long long), n, m);
	else if (m->place->len == 4)
		ft_upn((uintmax_t)va_arg((m->ap), uintmax_t), n, m);
	else if (m->place->len == 5)
		ft_upn((uintmax_t)va_arg((m->ap), size_t), n, m);
}

/*
**	initializes the number struct needed to carry out conversion
*/

void	get_num(t_m *m, t_num *n)
{
	int type;

	n->sign = 0;
	n->idx = 0;
	ft_bzero(n->b_conv, 100);
	n->neg = 0;
	type = m->place->type;
	if (type == 3 || type == 4 || type == 5)
		signed_conversion(m, n);
	else if (type == 6 || type == 7 || type == 10 || type == 11)
		unsigned_conversion(m, n);
}

/*
**	handels conversion for number types
*/

int		dig(t_m *m, char buf[MAX])
{
	t_num 		n;

	get_base(m, &n);
	get_num(m, &n);
	num_prcs(&n, m->place->precision);
	num_wdth(&n, m->place->width, m->place->flags);
	return(replace(m, buf, n.b_conv));
}
