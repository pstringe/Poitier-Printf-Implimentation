/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:40:33 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/04 19:29:36 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void 	s_test(char *name, char *str)
{
	printf("%s\n", name);
	printf("A:%s\n", str);
	ft_printf("B:%s\n", str);
}

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
			printf("A: %d\t", printf("%c\n", 42));
			printf("B: %d\t", ft_printf("%c\n", 42));
		}
	}
	return (0);
}
