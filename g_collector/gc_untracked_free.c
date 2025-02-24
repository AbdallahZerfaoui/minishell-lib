/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_untracked_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:38:57 by azerfaou          #+#    #+#             */
/*   Updated: 2025/02/24 13:41:48 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/garbage_collector.h"

/***
 * Function that will free a pointer
 * that was not tracked by the gc
 */
// TODO improve the function by using void * instead of char *
void	gc_untracked_free(char *str)
{
	t_garbage_collector	*gc;
	t_gc_node			*current;
	size_t				i;

	if (!str)
		return ;
	i = 0;
	gc = gc_get_instance();
	current = gc->head;
	while (current && i < gc->size)
	{
		if (current->pointer == str)
			return ;
		current = current->next;
		i++;
	}
	free(str);
}
