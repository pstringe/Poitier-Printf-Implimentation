/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 06:28:44 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/23 07:23:48 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		poi(char *buf, int mod, va_list args)
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
	if (!buf && !mod && !args)
		return (-1);
	return(0);
}
