/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:49:19 by iziane            #+#    #+#             */
/*   Updated: 2025/01/06 18:27:18 by azerfaou         ###   ########.fr       */
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
		g_data->exit_status = MALLOC_ERROR;
		return (NULL);
	}
	gc_add_begin(ptr);
	return (ptr);
}
