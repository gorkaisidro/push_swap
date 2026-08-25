/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:14:43 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/10 13:34:37 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **headRef, char *str)
{
	t_stack	*last_node;
	t_stack	*old_head;
	int		len;

	len = stack_len(*headRef);
	if (!*headRef || len <= 1)
		return ;
	last_node = find_last_node(*headRef);
	old_head = *headRef;
	*headRef = old_head->next;
	(*headRef)->prev = NULL;
	last_node->next = old_head;
	old_head->prev = last_node;
	old_head->next = NULL;
	if (str)
		user_message(str);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	user_message("rr");
}
