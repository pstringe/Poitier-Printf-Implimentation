/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:49:20 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/27 15:14:15 by pstringe         ###   ########.fr       */
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
	return (i);
}

int 	get_base(t_m *m)
{
	if (m->place->type == 3)
		return (10);
	if (m->place->type == 4)
		return (10);
	if (m->place->type == 5)
		return (8);
	if (m->place->type == 6)
		return (8);
	if (m->place->type == 9)
		return (16);
	if (m->place->type == 10)
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
	{
		tmp = ft_strdup(buf);
		ft_memset(w, (z ? '0' : ' '), (!z && wd - l > 0 ? wd - l : wd - l - 1));
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
	*i += wd - l;
}

int		dig(t_m *m, char buf[MAX])
{
	int			base;
	int			i;
	char		b_conv[100];
	int			neg;
	int			arg;

	i = 0;	
	base = get_base(m);
	ft_bzero(b_conv, 100);
	arg = va_arg((m->ap), long long);
	neg = arg < 0 ? -1 : 1;
	if (m->place->flags & PLUS && arg >= 0)
		buf[m->pos_b++] = '+';
	else if (m->place->flags & SPACE && arg >= 0)
		buf[m->pos_b++] = ' ';
	ft_pn((arg < 0 ? arg * -1 : arg) , b_conv, m->place->type, &i, base);
	num_prcs(b_conv, m->place->precision, &i);
	num_wdth(b_conv, m->place->width, m->place->flags, &neg,  &i);
	if (neg < 0)
		buf[m->pos_b++] = '-';
	return(replace(m, buf, b_conv));
}
