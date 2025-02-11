/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:04:13 by azerfaou          #+#    #+#             */
/*   Updated: 2025/02/11 14:10:12 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_all(char *str, ...)
{
	va_list	args;
	char	*current_str;
	char	*result;

	va_start(args, str);
	result = ft_strdup(str);
	current_str = va_arg(args, char *);
	while (current_str)
	{
		result = ft_strjoin(result, current_str);
		current_str = va_arg(args, char *);
	}
	va_end(args);
	return (result);
}
