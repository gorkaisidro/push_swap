/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:11:45 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/10 13:57:27 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **destRef, t_stack **sourceRef, char *str)
{
	t_stack	*new_node;

	if (*sourceRef == NULL)
		return ;
	new_node = *sourceRef;
	*sourceRef = (*sourceRef)->next;
	if (*sourceRef)
		(*sourceRef)->prev = NULL;
	new_node->prev = NULL;
	if (*destRef == NULL)
	{
		*destRef = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *destRef;
		new_node->next->prev = new_node;
		*destRef = new_node;
	}
	if (str)
		user_message(str);
}
