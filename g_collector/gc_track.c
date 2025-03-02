/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_track.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:52:37 by azerfaou          #+#    #+#             */
/*   Updated: 2025/03/02 20:06:12 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/garbage_collector.h"

t_gc_node	*gc_create_node(void *pointer2mem)
{
	t_gc_node	*new_node;

	new_node = (t_gc_node *)malloc(sizeof(t_gc_node) * 1);
	if (!new_node)
		return (NULL);
	new_node->pointer = pointer2mem;
	return (new_node);
}

// TODO	forbidden function
void	gc_error(const char *msg, char *file, int line, uint8_t exit_stat)
{
	(void)exit_stat;
	ft_putstr_fd(2, "Error: File ");
	ft_putstr_fd(2, file);
	ft_putstr_fd(2, " line ");
	ft_putnbr_fd(2, line);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, (char *)msg);
	ft_putstr_fd(2, "\n");
	gc_shutdown();
}

int	gc_contains(void *target)
{
	t_gc_node			*current;
	t_garbage_collector	*gc;

	gc = gc_get_instance();
	current = gc->head;
	while (current)
	{
		if (current->pointer == target)
			return (1);
		current = current->next;
	}
	return (0);
}

void	gc_track(void *ptr)
{
	t_gc_node			*new_node;
	t_garbage_collector	*gc;

	gc = gc_get_instance();
	if (gc_contains(ptr))
		return ;
	new_node = gc_create_node(ptr);
	if (!new_node)
	{
		gc_error("Failed to create a new node", __FILE__, __LINE__, 1);
		return ;
	}
	new_node->next = gc->head;
	gc->head = new_node;
	gc->size++;
}
