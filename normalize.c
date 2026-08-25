/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:57:45 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/15 11:16:42 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smaller_unmarked_index(long long *numbers, int len,
	const long long marker)
{
	int	i;
	int	smallest_idx;

	smallest_idx = -1;
	i = 0;
	while (i < len)
	{
		if (numbers[i] != marker)
		{
			if (smallest_idx == -1 || numbers[i] < numbers[smallest_idx])
				smallest_idx = i;
		}
		i++;
	}
	return (smallest_idx);
}

long long	*normalize(long long *numbers, int len)
{
	int				i;
	long long		*nbrs;
	int				smallest_idx;
	long long		new_max_marker;

	new_max_marker = LLONG_MAX;
	nbrs = xmalloc(sizeof(long long) * len);
	i = 0;
	while (i < len)
	{
		smallest_idx = get_smaller_unmarked_index(numbers, len, new_max_marker);
		if (smallest_idx != -1)
		{
			nbrs[smallest_idx] = i;
			numbers[smallest_idx] = new_max_marker;
		}
		i++;
	}
	free(numbers);
	return (nbrs);
}
