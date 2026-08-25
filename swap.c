/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:27:12 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/10 13:55:22 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **headRef, char *str)
{
	int	len;
	int	tmp;

	len = stack_len(*headRef);
	if (!*headRef || len <= 1)
		return ;
	tmp = ((*headRef)->value);
	(*headRef)->value = (*headRef)->next->value;
	(*headRef)->next->value = tmp;
	if (str)
		user_message(str);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, NULL);
	swap(b, NULL);
	user_message("ss");
}
