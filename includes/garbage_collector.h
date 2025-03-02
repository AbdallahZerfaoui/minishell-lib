/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:34:21 by iziane            #+#    #+#             */
/*   Updated: 2025/03/02 19:43:31 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include "../../minishell.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>

typedef struct s_gc_node
{
	void				*pointer;
	struct s_gc_node	*next;
}						t_gc_node;

typedef struct s_garbage_collector
{
	t_gc_node			*head;
	t_gc_node			*tail;
	size_t				size;
}						t_garbage_collector;

// entry point
t_garbage_collector		*gc_init(void);
t_garbage_collector		*gc_get_instance(void);

// main funtion
void					*ft_malloc(size_t size);

// add a pointer to the garbage collector
void					gc_track(void *ptr);
int						gc_contains(void *target);
void					gc_error(const char *msg, char *file, int line,
							uint8_t exit_stat);
t_gc_node				*gc_create_node(void *pointer2mem);
t_garbage_collector		*gc_get_instance(void);

// shutdown the garbage collector
void					gc_shutdown(void);
void					gc_cleanup_all(void);

//	extra
void					gc_untracked_free(char *str);

#endif
