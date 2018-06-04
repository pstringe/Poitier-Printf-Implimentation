/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:49:20 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/04 16:21:34 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	handels conversion for number types
*/

int		dig(t_m *m, char buf[MAX])
{
	t_num 		n;

	get_base(m, &n);
	get_num(m, &n);
	num_prcs(&n, m->place->precision);
	num_wdth(&n, m->place->width, m->place->flags);
	return(replace(m, buf, n.b_conv));
}
