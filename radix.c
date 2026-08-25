/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:45:00 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/10 13:38:45 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bits(int n, int bit_index)
{
	return ((n >> bit_index) & 1);
}

static void	radix_operations(t_stack **a, t_stack **b, int bit_index, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (get_bits((*a)->value, bit_index))
			rotate(a, "ra");
		else
			push(b, a, "pb");
		i++;
	}
	while (*b)
		push(a, b, "pa");
}

static int	count_bits(int len)
{
	int	bits;

	bits = 0;
	while ((len - 1) >> bits)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, int len)
{
	int	i;
	int	bits;

	if (len == 2)
		swap(a, "sa");
	else if (len == 3)
		sort_three(a);
	else if (len == 4 || len == 5)
		sort_four_and_five(a, b);
	else
	{
		bits = count_bits(len);
		i = 0;
		while (i < bits && !stack_sorted(*a))
		{
			radix_operations(a, b, i, len);
			i++;
		}
	}
}
