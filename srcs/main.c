/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:40:33 by pstringe          #+#    #+#             */
/*   Updated: 2018/07/20 19:44:19 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	test_93()
{
	int a;
	int b;

	ft_putstr("93\n");
	a = printf("A res: @moulitest: %.o %.0o\n", 0, 0);
	b = ft_printf("B res: @moulitest: %.o %.0o\n", 0, 0);
	printf("A ret: %d\n", a);
	printf("B ret: %d\n", b);
	ft_putchar('\n');
}

void	test_94()
{
	int a;
	int b;

	ft_putstr("94\n");
	a = printf("A res: @moulitest: %5.o %5.0o\n", 0, 0);
	b = ft_printf("B res: @moulitest: %5.o %5.0o\n", 0, 0);
	printf("A ret: %d\n", a);
	printf("B ret: %d\n", b);
	ft_putchar('\n');
}

void	test_95()
{
	int a;
	int b;

	ft_putstr("95\n");
	a = printf("A res: @moulitest: %#.o %#.0o\n", 0, 0);
	b = ft_printf("B res: @moulitest: %#.o %#.0o\n", 0, 0);
	printf("A ret: %d\n", a);
	printf("B ret: %d\n", b);
	ft_putchar('\n');
}

void	test_167()
{
	int a;
	int b;

	ft_putstr("167\n");
	a = printf("A res: % 10.5d\n", 4242);
	b = ft_printf("B res: % 10.5d\n", 4242);
	printf("A ret: %d\n", a);
	printf("B ret: %d\n", b);
	ft_putchar('\n');
}

void	test_172()
{
	int a;
	int b;

	ft_putstr("172\n");
	a = printf("A res: %03.2d", -1);
	b = ft_printf("B res: %03.2d", -1);
	printf("A ret: %d\n", a);
	printf("B ret: %d\n", b);
	ft_putchar('\n');
}

int 	main(void)
{
	test_93();
	test_94();
	test_95();
	//test_167();
	//test_172();
	return (0);
}
