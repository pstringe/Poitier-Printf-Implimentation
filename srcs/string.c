/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:16:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/04 20:12:50 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str(t_m *m, char buf[MAX])
{
	char	*arg;
	int		i;
	int		p;
	int		w;

	arg = m->place->type == 12 ? ft_strnew(1) : va_arg(m->ap, char*);
	if (m->place->type == 12)
		arg[0] = va_arg(m->ap, int);
	arg = arg ? arg : "(null)";
	p = !m->place->precision ? ft_strlen(arg) : m->place->precision;
	w = m->place->width - p;
	i = -1;
	if (!(m->place->flags & MINUS))
		while (w-- > 0)
			buf[m->pos_b++] = ' ';
	while (arg[++i] && i < p)
		buf[m->pos_b++] = arg[i];
	if (m->place->type == 12)
		ft_memdel((void**)&arg);
	if (m->place->flags & MINUS)
		while (w-- > 0)
			buf[m->pos_b++] = ' ';
	return (0);
}
