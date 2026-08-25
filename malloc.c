/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:50:07 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/06 13:57:04 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*xmalloc(size_t size)
{
	void	*ptr ;

	ptr = malloc(size);
	if (!ptr)
	{
		write(1, MALLOC_ERROR, ft_strlen(MALLOC_ERROR));
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
