/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:40:33 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/21 08:38:43 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int 	main(int argc, char **argv)
{
	int 	i;
	char	*str;

	if (argc >= 2)
	{
		i = 0;
		while (++i < argc)
		{
			str = argv[i];
			printf("printf:\t%s\n", str);
			ft_printf("ft_printf:\t%s\n", str);
		}
	}
	return (0);
}
