/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/12 09:36:34 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_m		*m;
	char	buf[MAX];

	m = (t_m*)ft_memalloc(sizeof(t_m));
	va_start(m->ap, format);
	init(m, format, buf);
	while (cpy(m, buf))
		if (get_placeholder(m))
			convert(m, buf);
	put(m, buf);
	dstry(m);
	return (0);
}
