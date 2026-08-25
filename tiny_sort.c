/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:14:28 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/10 13:37:56 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (stack_sorted(*a))
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		swap(a, "sa");
	else if (first > second && second > third)
	{
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	else if (first > second && second < third && first > third)
		rotate(a, "ra");
	else if (first < second && second > third && first < third)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a, "rra");
}

static int	get_min_index(t_stack *stack)
{
	int		min;
	int		idx;
	int		min_idx;
	t_stack	*tmp;

	if (!stack)
		return (0);
	min = stack->value;
	idx = 0;
	min_idx = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_idx = idx;
		}
		tmp = tmp->next;
		idx++;
	}
	return (min_idx);
}

static void	rotate_to_top(t_stack **stack, int index, char *ra_op, char *rra_op)
{
	int	len;
	int	moves;

	len = stack_len(*stack);
	if (index <= len / 2)
	{
		while (index-- > 0)
			rotate(stack, ra_op);
	}
	else
	{
		moves = len - index;
		while (moves-- > 0)
			reverse_rotate(stack, rra_op);
	}
}

void	sort_four_and_five(t_stack **a, t_stack **b)
{
	int	min_index;

	if (stack_sorted(*a))
		return ;
	while (stack_len(*a) > 3)
	{
		min_index = get_min_index(*a);
		if (min_index != 0 && stack_len(*a) > 3)
			rotate_to_top(a, min_index, "ra", "rra");
		if (stack_sorted(*a) && !(*b))
			return ;
		push(b, a, "pb");
		if (stack_sorted(*a) && !(*b))
			return ;
	}
	sort_three(a);
	if (stack_len(*b) == 2 && (*b)->value < (*b)->next->value)
		swap(b, "sb");
	while (*b)
		push(a, b, "pa");
}
