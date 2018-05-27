/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:49:20 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/26 19:16:45 by pstringe         ###   ########.fr       */
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
		memcpy(buf, p, pr - l);
		ft_memdel((void**)&p);
		memcpy(buf + pr - l, tmp, l);
		ft_memdel((void**)&tmp);
	}
	*i += pr - l;
}

int		dig(t_m *m, char buf[MAX])
{
	int			base;
	int			i;
	char		b_conv[100];
	int			arg;

	i = 0;	
	base = get_base(m);
	ft_bzero(b_conv, 100);
	arg = va_arg((m->ap), long long);
	if (m->place->flags & PLUS && arg >= 0)
		buf[m->pos_b++] = '+';
	ft_pn(arg, b_conv, m->place->type, &i, base);
	num_prcs(b_conv, m->place->precision, &i);
	return(replace(m, buf, b_conv));
}
