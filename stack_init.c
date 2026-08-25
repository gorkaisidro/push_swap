/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:13:12 by gisidro-          #+#    #+#             */
/*   Updated: 2025/12/03 11:07:06 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	user_message(char *str)
{
	if (!ft_strncmp(str, "pa", 2))
		write(1, PA, ft_strlen(PA));
	else if (!ft_strncmp(str, "pb", 2))
		write(1, PB, ft_strlen(PB));
	else if (!ft_strncmp(str, "rra", 3))
		write(1, RRA, ft_strlen(RRA));
	else if (!ft_strncmp(str, "rrb", 3))
		write(1, RRB, ft_strlen(RRB));
	else if (!ft_strncmp(str, "rrr", 3))
		write(1, RRR, ft_strlen(RRR));
	else if (!ft_strncmp(str, "ra", 2))
		write(1, RA, ft_strlen(RA));
	else if (!ft_strncmp(str, "rb", 2))
		write(1, RB, ft_strlen(RB));
	else if (!ft_strncmp(str, "rr", 2))
		write(1, RR, ft_strlen(RR));
	else if (!ft_strncmp(str, "sa", 2))
		write(1, SA, ft_strlen(SA));
	else if (!ft_strncmp(str, "sb", 2))
		write(1, SB, ft_strlen(SB));
	else if (!ft_strncmp(str, "ss", 2))
		write(1, SS, ft_strlen(SS));
}

static void	create_list(t_stack **a, long long *nbrs, int ac)
{
	int	i;

	i = 0;
	while (i < ac -1)
	{
		append_node(a, nbrs[i]);
		i++;
	}
	free (nbrs);
}

void	stack_init(t_stack **a, char **av, int ac, bool flag_ac_2)
{
	long		nbr;
	int			i;
	long long	*stack;

	i = -1;
	stack = xmalloc(sizeof(long long) * (ac - 1));
	while (++i < ac - 1)
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ac_2);
		nbr = ft_atoll(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			write(1, OVERFLOW, ft_strlen(OVERFLOW));
			free(stack);
			error_free(a, av, flag_ac_2);
		}
		stack[i] = (int)nbr;
	}
	if (error_repetition(stack, ac - 1))
		error_free(a, av, flag_ac_2);
	stack = normalize(stack, ac - 1);
	create_list(a, stack, ac);
	if (flag_ac_2)
		free_matrix(av);
}
