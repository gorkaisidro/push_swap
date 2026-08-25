/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:44:33 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/29 17:10:40 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack **a, char **av, bool flag_ac_2)
{
	free_stack(a);
	if (flag_ac_2)
		free_matrix(av);
	exit(EXIT_FAILURE);
}

int	error_syntax(char *str_nbr)
{
	int	i;

	i = 0;
	while (str_nbr[i] == ' ' || (str_nbr[i] >= 9 && str_nbr[i] <= 13))
		i++;
	if (!str_nbr[i])
		return (write(1, SYNTAX, ft_strlen(SYNTAX)));
	if (str_nbr[i] == '+' || str_nbr[i] == '-')
	{
		if (!str_nbr[i + 1] || str_nbr[i + 1] == ' ')
			return (write(1, SYNTAX, ft_strlen(SYNTAX)));
		i++;
	}
	while (str_nbr[i])
	{
		if (!(str_nbr[i] >= '0' && str_nbr[i] <= '9'))
			return (write(1, SYNTAX, ft_strlen(SYNTAX)));
		i++;
	}
	return (0);
}

int	error_repetition(long long *stack, int len)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < (len - 1))
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j++])
			{
				flag = 1;
				break ;
			}
		}
		i++;
	}
	if (flag)
	{
		free(stack);
		write(1, REPEAT, ft_strlen(REPEAT));
	}
	return (flag);
}
