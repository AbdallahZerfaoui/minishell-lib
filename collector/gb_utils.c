/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:49:19 by iziane            #+#    #+#             */
/*   Updated: 2025/01/07 19:37:40 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/garbage_collector.h"

t_garbage_collector	*get_gc(void)
{
	static t_garbage_collector	gc = {0};

	return (&gc);
}

void	gc_print_linked_list(t_garbage_collector *gc)
{
	if (!gc)
		return ;
	printf("Len of Linked List: %zu\n", gc->size);
	return ;
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		return (NULL);
	}
	gc_add_begin(ptr);
	return (ptr);
}
