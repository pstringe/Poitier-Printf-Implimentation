/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:33:58 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/19 17:52:03 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		chr(t_m *m, char buf[MAX])
{
	int		arg;
	int 	w;
	int		i;

	w =	m->place->width - ((arg = va_arg(m->ap, int)) ? 1 : 0);
	i = -1;
	if (!(m->place->flags & MINUS))
		while (w-- > 0)
			buf[m->pos_b++] = ' ';
	buf[m->pos_b++] = !arg ? '\0' : arg;
	if (m->place->flags & MINUS)
		while (w-- > 0)
			buf[m->pos_b++]	= ' ';
	return (0);
}	
