/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:55:35 by azerfaou          #+#    #+#             */
/*   Updated: 2025/02/24 13:08:10 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/garbage_collector.h"

/***
 * Function that will return the instance of the garbage collector
 * the magic of this function is that it does two things at once :
 * 1. If the gc does not exist, it will create it
 * 2. If the gc exists, it will return it
 * MAGIC !!
 */
t_garbage_collector	*gc_get_instance(void)
{
	static t_garbage_collector	gc = {0};

	return (&gc);
}

t_garbage_collector	*gc_init(void)
{
	t_garbage_collector	*gc;

	gc = gc_get_instance();
	gc->head = NULL;
	gc->tail = NULL;
	gc->size = 0;
	return (gc);
}
