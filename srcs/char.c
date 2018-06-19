/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:33:58 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/19 16:42:47 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		chr(t_m *m, char buf[MAX])
{
	int		arg;
	int 	w;
	int		i;
	int		p;

	m->place->precision = m->place->precision == -1 ? 0 : m->place->precision;
	p = !m->place->precision ? ((arg = va_arg(m->ap, int)) ? 1 : 0) : m->place->precision - 1;
	w =	m->place->width - p;
	i = -1;
	if (!(m->place->flags & MINUS))
		while (w-- > 0)
			buf[m->pos_b++] = ' ';
	buf[m->pos_b++] = arg;
	while (++i < p)
		buf[m->pos_b++] = ' ';
	if (m->place->flags & MINUS)
		while (w-- > 0)
			buf[m->pos_b++]	= ' ';
	return (0);
}	
