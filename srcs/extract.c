/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:45:28 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/01 17:38:30 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	determines type for ssigned conversions
*/

static void	signed_arg(t_m *m, t_arg *arg)
{
	if (m->place->len == 0)
		arg->dhh = va_arg(m->ap, signed char);
	else if (m->place->len == 1)
		arg->dh = va_arg(m->ap, short);
	else if (m->place->len == 2)
		arg->dl = va_arg(m->ap, long);
	else if (m->place->len == 3)
		arg->dll = va_arg(m->ap, long long);
	else if (m->place->len == 4)
		arg->ddl = var_arg(m->ap, intmax_t);
	else if (m->place->len == 5)
		arg->dz = var_arg(m->ap, size_t);
}

/*
**	determines type for unsigned conversions
*/

static void 	unsigned_arg(t_m *m, t_arg *arg)
{
	if (m->place->len == 0)
		arg->dhh = va_arg(m->ap, signed char);
	else if (m->place->len == 1)
		arg->dh = va_arg(m->ap, short);
	else if (m->place->len == 2)
		arg->dl = va_arg(m->ap, long);
	else if (m->place->len == 3)
		arg->dll = va_arg(m->ap, long long);
	else if (m->place->len == 4)
		arg->ddl = var_arg(m->ap, intmax_t);
	else if (m->place->len == 5)
		arg->dz = var_arg(m->ap, size_t);
}

/*
**	extracts arguments, based on type and modifiers
*/

t_arg 	*get_arg(t_m *m, t_arg *arg)
{
	if (m->place->type == 3 || m->place->type == 4 || m->place->type == 5)
		arg->sign = 1;
	else
		arg->sign = 0;
	if (sign && m->len)
		signed_arg(m, arg);
	else if (sign && m->len)
		signed_arg(m, arg);
	else
		arg->def = va_arg(m->ap, def);
}

void	*extract_arg(arg)
{
	if (arg.sign)

}
