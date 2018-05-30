/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:54:55 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/29 16:33:05 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		uni(t_m *m, char buf[MAX])
{
	char	*arg;
	int		i;
	int		p;
	int		w;

	arg = va_arg(m->ap, char*);
	p = !m->place->precision ? ft_strlen(arg) : m->place->precision;
	w = m->place->width - p;
	i = -1;
	while (w-- > 0)
		buf[m->pos_b++] = ' ';
	while (arg[++i] && i < p)
		buf[m->pos_b++] = arg[i];
	return (i);
}
