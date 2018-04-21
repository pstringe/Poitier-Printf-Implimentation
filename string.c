/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:16:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/21 10:29:28 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	str(char *buf, int mod, va_list args)
{
	char *arg;
	int i;
	
	if (mod)
		i = 0;
	arg = va_arg(args, char*);
	i = -1;
	while (arg[++i])
	{
		buf[i] = arg[i];
	}
	return (i);
}
