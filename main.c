/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:40:33 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/27 14:26:02 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void 	s_test(char *str)
{
	printf("--------------\n-STRING TESTS-\n--------------\n\n");
	printf("A:\t%s\n", str);
	ft_printf("B:\t%s\n", str);
	ft_putendl("\n");
	
	printf("A:\t%.3s\n", str);
	ft_printf("B:\t%.3s\n", str);
	ft_putendl("\n");
	
	printf("A:\t%.*s\n", 3, str);
	ft_printf("B:\t%.*s\n", 3, str);
	ft_putendl("\n");

	printf("A: %6.3s\n", str);
	ft_printf("B: %6.3s\n", str);
	ft_putendl("\n");

	printf("A: %*.3s\n", 6, str);
	ft_printf("B: %*.3s\n", 6, str);
	ft_putendl("\n");

	printf("A: %6.3s%6.3s\n", str, str);
	ft_printf("B: %6.3s%6.3s\n", str, str);
	ft_putendl("\n");
}

void	p_test(char **str)
{
	printf("---------------\n-POINTER TESTS-\n---------------\n\n");
	printf("A:\t%p\n", str);
	ft_printf("B:\t%p\n", str);
	ft_putendl("\n");
}

void	d_test(int n)
{
	printf("---------------\n-DIGIT TESTS-\n---------------\n\n");
	printf("A:\t%d\n", n);
	ft_printf("B:\t%d\n", n);
	ft_putendl("\n");

	printf("A:\t%.*d\n", 2, n);
	ft_printf("B:\t%.*d\n", 2, n);
	ft_putendl("\n");
	
	printf("A:\t%*d\n", 7, n);
	ft_printf("B:\t%*d\n", 7, n);
	ft_putendl("\n");
	
	printf("A:\t%*.*d\n", 7, 10, n);
	ft_printf("B:\t%*.*d\n", 7, 10, n);
	ft_putendl("\n");

	printf("A:\t%*.*d%*.*d\n", 7, 10, n, 10, 7, n);
	ft_printf("B:\t%*.*d%*.*d\n", 7, 10, n, 10, 7, n);
	ft_putendl("\n");

	printf("A:\t%*.*d%0*.*d\n", 7, 10, n, 7, 10, n);
	ft_printf("B:\t%*.*d%0*.*d\n", 7, 10, n, 7, 10, n);
	ft_putendl("\n");

	printf("A:\t%*.*d%-*.*d\n", 7, 10, n, 7, 10, n);
	ft_printf("B:\t%*.*d%-*.*d\n", 7, 10, n, 1, 10, n);
	ft_putendl("\n");
	
	printf("A:\t%*.*d%+*.*d\n", 7, 10, n, 7, 10, n);
	ft_printf("B:\t%*.*d%+*.*d\n", 7, 10, n, 7, 10, n);
	ft_putendl("\n");
	
	printf("A:\t%*.*d% *.*d\n", 7, 10, n, 7, 10, n);
	ft_printf("B:\t%*.*d% *.*d\n", 7, 10, n, 7, 10, n);
	ft_putendl("\n");

}

void	o_test(int n)
{
	printf("---------------\n-OCTAL TESTS-\n---------------\n\n");
	printf("A:\t%o\n", n);
	ft_printf("B:\t%o\n", n);
	ft_putendl("\n");
	
	printf("A:\t%.*o\n", 2, n);
	ft_printf("B:\t%.*o\n", 2, n);
	ft_putendl("\n");
}

void	us_test(char **str)
{
	printf("A:\t%p\n", str);
	ft_printf("B:\t%p\n", str);
	ft_putchar('\n');
}

void	h_test(int n)
{
	printf("---------------\n-HEX TESTS-\n---------------\n\n");
	printf("A:\t%x\n", n);
	ft_printf("B:\t%x\n", n);
	ft_putendl("\n");

	printf("A:\t%.*x\n", 2, n);
	ft_printf("B:\t%.*x\n", 2, n);
	ft_putendl("\n");
}

void	uc_test(char **str)
{
	printf("A:\t%p\n", str);
	ft_printf("B:\t%p\n", str);
	ft_putchar('\n');
}

void	nt_test(char **str)
{
	printf("A:\t%p\n", str);
	ft_printf("B:\t%p\n", str);
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
