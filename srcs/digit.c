/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:49:20 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/04 14:30:39 by pstringe         ###   ########.fr       */
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
**	edits string to accomadte sign and any other extra characters needed for flags
**	while complying with width specification
*/

void 	num_wdth(t_num *n, int wd, int flags)
{
	int		l;
	int		z;
	char 	*tmp;
	char	*w;
	int		e_char;

	z = flags & ZERO;
	w = (l = ft_strlen(n->b_conv)) < wd ? ft_strnew(wd - l) : NULL;
	e_char = 0;
	if (w)
		ft_memset(w, (z ? '0' : ' '), (!z && wd - l > 0 ? wd - l : wd - l - 1));
	tmp = ft_strdup(n->b_conv);
	if (w && !(flags & MINUS))
	{
		ft_memcpy(n->b_conv, w, wd - l);
		if ((e_char = (!z && (n->neg < 0 || flags & SPACE || flags & PLUS))))
		{
			n->b_conv[wd - l - 1] = get_signchar(n, flags);
			n->neg = 1;	
		}
		ft_memdel((void**)&w);
		ft_memcpy(n->b_conv + wd - l, tmp, l);
		ft_memdel((void**)&tmp);
	}
	else if (w && (flags & MINUS))
	{
		if ((e_char = (!z && (n->neg < 0 || flags & SPACE || flags & PLUS))))
		{
			n->b_conv[0] = get_signchar(n, flags);
			n->neg = 1;
			ft_memcpy(n->b_conv + 1, tmp, ft_strlen(n->b_conv));
		}
		else
			ft_memcpy(n->b_conv, tmp, ft_strlen(n->b_conv));
		ft_memcpy(n->b_conv + ft_strlen(tmp) + (e_char ? 1 : 0), w, wd + (e_char ? -2 : -1));
	}
	n->idx += wd - l + (e_char ? -1 : 0);
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
	//int			base;
	//int			i;
	//char		b_conv[100];
	//int			neg;
	//int			arg;

	get_base(m, &n);
	get_num(m, &n);
	num_prcs(&n, m->place->precision);
	num_wdth(&n, m->place->width, m->place->flags);
	/*
	n.idx = 0;	
	n.base = get_base(m);
	ft_bzero(n.b_conv, 100);
	n.arg = va_arg((m->ap), long long);
	n.neg = n.arg < 0 ? -1 : 1;
	if (n.neg < 0 && !(m->place->type >= 3 && m->place->type <= 5))
		n.arg = (((n.arg * -1) ^ 0xfffffff) & 0xfffffff) + 1;
	if (m->place->flags & PLUS && n.arg >= 0)
		buf[m->pos_b++] = '+';
	else if (m->place->flags & SPACE && n.arg >= 0)
		buf[m->pos_b++] = ' ';
	ft_pn((n.arg < 0 && !(m->place->type >= 3 && m->place->type <= 5) ? n.arg * -1 : n.arg) , n.b_conv, m->place->type, &(n.idx), n.base);
	num_prcs(n.b_conv, m->place->precision, &(n.idx));
	num_wdth(n.b_conv, m->place->width, m->place->flags, &(n.neg),  &(n.idx));
	if (n.neg < 0 && (m->place->type >= 3 && m->place->type <= 5))
		buf[m->pos_b++] = '-';
	if (n.neg < 0 && (m->place->type == 10 || m->place->type <= 11))
		buf[m->pos_b++] = m->place->type == 10 ? 'f' : 'F';
	*/
	return(replace(m, buf, n.b_conv));
}
