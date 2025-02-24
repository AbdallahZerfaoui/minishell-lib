/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_cleanup_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:15 by azerfaou          #+#    #+#             */
/*   Updated: 2025/02/24 14:57:18 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/garbage_collector.h"

// void	remove_node(t_gc_node *target, t_gc_node **head)
// {
// 	t_gc_node	*current;
// 	t_gc_node	*prev;

// 	current = *head;
// 	prev = NULL;
// 	while (current)
// 	{
// 		if (current == target)
// 		{
// 			if (prev)
// 				prev->next = current->next;
// 			else
// 				*head = current->next;
// 			free(current);
// 			return ;
// 		}
// 		prev = current;
// 		current = current->next;
// 	}
// }

void	gc_cleanup_all(void)
{
	t_garbage_collector	*gc;
	t_gc_node			*current;
	t_gc_node			*prev;

	gc = gc_get_instance();
	current = gc->head;
	prev = NULL;
	while (current)
	{
		if (current->pointer)
			free(current->pointer);
		prev = current;
		current = current->next;
		if (prev)
		{
			free(prev);
			prev = NULL;
		}
	}
	gc = NULL;
}
