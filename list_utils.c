/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:36:02 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/06 14:09:18 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack **headRef, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	node = xmalloc(sizeof(t_stack));
	node->value = nbr;
	node->next = NULL;
	node->prev = NULL;
	if (!(*headRef))
		*headRef = node;
	else
	{
		last_node = find_last_node(*headRef);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

bool	stack_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
