/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:24:26 by gisidro-          #+#    #+#             */
/*   Updated: 2025/11/05 11:47:56 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_counter(char **str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i + 1);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = ac;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = arg_counter(av);
	}
	else
		av += 1;
	stack_init(&a, av, ac, size == 2);
	if (!stack_sorted(a))
		radix_sort(&a, &b, stack_len(a));
	free_stack(&a);
	return (0);
}
