/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:16:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/04 14:10:17 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str(t_m *m, char buf[MAX])
{
	char	*arg;
	int		i;
	int		p;
	int		w;

	arg = va_arg(m->ap, char*);
	p = !m->place->precision ? ft_strlen(arg) : m->place->precision;
	w = m->place->width - p;
	i = -1;
	if (!(m->place->flags & MINUS))
		while (w-- > 0)
			buf[m->pos_b++] = ' ';
	while (arg[++i] && i < p)
		buf[m->pos_b++] = arg[i];
	if (m->place->flags & MINUS)
		while (w-- > 0)
			buf[m->pos_b++] = ' ';
	return (0);
}
