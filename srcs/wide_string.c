/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:01:16 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/21 16:24:32 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wstr(t_m *m, char buf[MAX])
{
	wchar_t	*arg;
	int		l;
	int		i;
	int		p;
	int		w;

	m->place->precision = m->place->precision == -1 ? 0 : m->place->precision;
	arg = (arg = va_arg(m->ap, wchar_t*)) ? arg : L"(null)";
	if (!ft_strncmp((const char*)arg, (const char*)L"", ((l = ft_strlen((const char*)arg)) ? l : 1)))
	{
		arg = m->place->precision ? (wchar_t*)ft_strnew(m->place->precision) : arg;
		m->place->precision = 0;
	}
	p = !m->place->precision ? ft_strlen((const char*)arg) : m->place->precision;
	w = m->place->width - p;
	i = -1;
	if (!(m->place->flags & MINUS))
		while (w-- > 0)
			buf[m->pos_b++] = L' ';
	while (arg[++i] && i < p)
		buf[m->pos_b++] = arg[i];
	if (m->place->flags & MINUS)
		while (w-- > 0)
			buf[m->pos_b++] = L' ';
	return (0);
}
