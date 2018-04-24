/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:16:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/24 14:52:54 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	str(t_stuff *stuff)
{
	char *arg;
	int i;
	
	if (stuff->mods)
		i = 0;
	arg = va_arg(stuff->ap, char*);
	i = -1;
	while (arg[++i])
		stuff->buf[stuff->bytes++] = arg[i];
	return (i);
}
