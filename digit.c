/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:49:20 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/26 13:46:54 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dig(t_m *m, char buf[MAX])
{
	int		arg;

	arg = va_arg((m->ap), long long);
	if (m->place->flags & PLUS && arg >= 0)
		buf[m->pos_b++] = '+';
	ft_pn(arg, m, buf, 10);
	return (1);
}
