/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:28:44 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/24 14:39:34 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		poi(t_stuff *stuff)
{
	/*
	void **arg;
	int	n;

	if (mod)
		i = 0;
	arg = va_args(args, void**);
	n = 0;
	while (arg)
	{
					
	}
	*/
	if (!stuff->buf && !stuff->mods && !stuff->flag)
		return (-1);
	return(0);
}
