/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:22:20 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/10 13:56:21 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **headRef, char *str)
{
	t_stack	*last_node;
	t_stack	*old_head;
	int		len;

	len = stack_len(*headRef);
	if (!*headRef || len <= 1)
		return ;
	last_node = find_last_node(*headRef);
	old_head = *headRef;
	last_node->prev->next = NULL;
	last_node->next = old_head;
	last_node->prev = NULL;
	old_head->prev = last_node;
	*headRef = last_node;
	if (str)
		user_message(str);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	user_message("rrr");
}
