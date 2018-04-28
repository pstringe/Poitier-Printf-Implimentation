/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:40:33 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/28 12:52:37 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void 	s_test(char *str)
{
	printf("--------------\n-STRING TESTS-\n--------------\n\n");
	printf("printf:\t\t%s\n", str);
	ft_printf("ft_printf:\t%s\n", str);
	ft_putendl("\n");
	
	printf("printf precision inline:\t%.3s\n", str);
	ft_printf("ft_printf precision inline:\t%.3s\n", str);
	ft_putendl("\n");
	
	printf("printf precision wild card:\t%.*s\n", 3, str);
	ft_printf("ft_printf precision wild card:\t%.*s\n", 3, str);
	ft_putendl("\n");

	printf("printf field width inline: %6.3s\n", str);
	ft_printf("ft_printf field width inline: %6.3s\n", str);
	ft_putendl("\n");

	printf("printf field width wildcard: %*.3s\n", 6, str);
	ft_printf("ft_printf field width wildcard: %*.3s\n", 6, str);
	ft_putendl("\n");

	printf("printf multiple: %6.3s%6.3s\n", str, str);
	ft_printf("ft_printf multiple: %6.3s%6.3s\n", str, str);
	ft_putendl("\n");

	printf("printf multiple wildcard: %*.*s %*.*s\n", 6, 3, str, 6, 3, str);
	ft_printf("ft_printf multiple wildcard: %*.*s %*.*s\n", 6, 3, str, 6, 3, str);
	ft_putendl("\n");

}

void	p_test(char **str)
{
	printf("---------------\n-POINTER TESTS-\n---------------\n\n");
	printf("printf:\t\t%p\n", str);
	ft_printf("ft_printf:\t%p\n", str);
	ft_putendl("\n");
}

void	d_test(int n)
{
	printf("---------------\n-DIGIT TESTS-\n---------------\n\n");
	printf("printf:\t\t%d\n", n);
	ft_printf("ft_printf:\t%d\n", n);
	ft_putendl("\n");

	printf("printf:\t\t%.*d\n", 2, n);
	ft_printf("ft_printf:\t%.*d\n", 2, n);
	ft_putendl("\n");
}

void	o_test(int n)
{
	printf("---------------\n-OCTAL TESTS-\n---------------\n\n");
	printf("printf:\t\t%o\n", n);
	ft_printf("ft_printf:\t%o\n", n);
	ft_putendl("\n");
	
	printf("printf:\t\t%.*o\n", 2, n);
	ft_printf("ft_printf:\t%.*o\n", 2, n);
	ft_putendl("\n");
}

void	us_test(char **str)
{
	printf("printf:\t\t%p\n", str);
	ft_printf("ft_printf:\t%p\n", str);
	ft_putchar('\n');
}

void	h_test(int n)
{
	printf("---------------\n-HEX TESTS-\n---------------\n\n");
	printf("printf:\t\t%x\n", n);
	ft_printf("ft_printf:\t%x\n", n);
	ft_putendl("\n");

	printf("printf:\t\t%.*x\n", 2, n);
	ft_printf("ft_printf:\t%.*x\n", 2, n);
	ft_putendl("\n");
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
			h_test(ft_atoi(str));
			o_test(ft_atoi(str));

		}
	}
	return (0);
}
