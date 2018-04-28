/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:50:52 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/27 13:56:39 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		oct(t_m *m, char buf[MAX])
{
	long long arg;

	arg = va_arg((m->ap), long long);
	ft_pn(arg, m, buf, 8);
	return (1);
}
