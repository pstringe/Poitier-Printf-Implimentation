/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:40:33 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/24 17:45:18 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void 	s_test(char *str)
{
	printf("printf:\t\t%s\n", str);
	ft_printf("ft_printf:\t%s\n", str);
	ft_putchar('\n');
	printf("printf:\t\t%s\n", str);
	ft_printf("ft_printf:\t%.*s\n", 3, str);
	ft_putchar('\n');
}

void	p_test(char **str)
{
	printf("printf:\t\t%p\n", str);
	ft_printf("ft_printf:\t%p\n", str);
	ft_putchar('\n');
}

void	d_test(int n)
{
	printf("printf:\t\t%d\n", n);
	ft_printf("ft_printf:\t%d\n", n);
	ft_putchar('\n');
}

void	o_test(char **str)
{
	printf("printf:\t\t%p\n", str);
	ft_printf("ft_printf:\t%p\n", str);
	ft_putchar('\n');
}

void	us_test(char **str)
{
	printf("printf:\t\t%p\n", str);
	ft_printf("ft_printf:\t%p\n", str);
	ft_putchar('\n');
}

void	h_test(char **str)
{
	printf("printf:\t\t%p\n", str);
	ft_printf("ft_printf:\t%p\n", str);
	ft_putchar('\n');
}

void	uc_test(char **str)
{
	printf("printf:\t\t%p\n", str);
	ft_printf("ft_printf:\t%p\n", str);
	ft_putchar('\n');
}

void	nt_test(char **str)
{
	printf("printf:\t\t%p\n", str);
	ft_printf("ft_printf:\t%p\n", str);
	ft_putchar('\n');
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
			s_test(str);
			p_test(&str);
			d_test(ft_atoi(str));
		}
	}
	return (0);
}
