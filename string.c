/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:16:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/26 16:10:49 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	str(t_m *m, char buf[MAX])
{
	char *arg;
	int i;
	int	p;

	arg = va_arg(m->ap, char*);
	p = !m->place->precision ? ft_strlen(arg) : m->place->precision;
	i = -1;
	while (arg[++i] && i < p)
		buf[m->pos_b++] = arg[i];
	return (i);
}
