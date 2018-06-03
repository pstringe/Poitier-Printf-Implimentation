/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:49:20 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/02 19:08:45 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		replace(t_m *m, char buf[MAX], char *conv)
{
	int	i;
	i = -1;
	while (conv[++i] && m->pos_b + i < MAX)
		buf[m->pos_b + i] = conv[i];
	m->pos_b += i;
	return (0);
}

int 	get_base(t_m *m)
{
	if (m->place->type == 3)
		return (10);
	if (m->place->type == 4)
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

void	num_prcs(char buf[100], int pr, int *i)
{
	int		l;
	char 	*tmp;
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

void	get_num (t_m *m, t_num *n)
{
	int type;

	type = m->place->type;
	if (type == 3 || type == 4 || type == 5)
		signed_conversion(m, n);
	else if (type == 6 || type == 7 || type == 11)
		unsigned_conversion(m, n);
}

void 	signed_conversions(t_m *m. t_num *n)
{
	if (m->place->len == 0)
		ft_spn((intmax_t)va_arg((m->ap), int), n);
	else if (m->place->len == 1)
		ft_spn((intmax_t)va_arg((m->ap), short), n);
	else if (m->place->len == 2)
		ft_spn((intmax_t)va_arg((m->ap), long), n);
	else if (m->place->len == 3)
		ft_spn((intmax_t)va_arg((m->ap), long long), n);
	else if (m->place->len == 4)
		ft_spn((intmax_t)va_arg((m->ap), intmax_t), n);
	else if (m->place->len == 5)
		ft_spn((intmax_t)va_arg((m->ap), size_t), n);
}

void 	signed_conversions(t_m *m. t_num *n)
{
	if (m->place->len == 0)
		ft_upn((uintmax_t)va_arg((m->ap), unsigned int), n);
	else if (m->place->len == 1)
		ft_upn((uintmax_t)va_arg((m->ap), unsigned short), n);
	else if (m->place->len == 2)
		ft_upn((uintmax_t)va_arg((m->ap), unsigned long), n);
	else if (m->place->len == 3)
		ft_upn((uintmax_t)va_arg((m->ap), unsigned long long), n);
	else if (m->place->len == 4)
		ft_upn((uintmax_t)va_arg((m->ap), unsigned intmax_t), n);
	else if (m->place->len == 5)
		ft_upn((uintmax_t)va_arg((m->ap), size_t), n);
}
int		dig(t_m *m, char buf[MAX])
{
	t_num 		n;
	//int			base;
	//int			i;
	//char		b_conv[100];
	//int			neg;
	//int			arg;


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
