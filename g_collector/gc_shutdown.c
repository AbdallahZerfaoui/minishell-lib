/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_shutdown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:16:49 by azerfaou          #+#    #+#             */
/*   Updated: 2025/02/24 13:27:24 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/garbage_collector.h"

void	gc_shutdown(void)
{
	t_garbage_collector	*gc;

	gc = gc_get_instance();
	gc_cleanup_all();
	ft_bzero(gc, sizeof(t_garbage_collector));
}
