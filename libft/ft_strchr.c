/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:52:17 by azerfaou          #+#    #+#             */
/*   Updated: 2025/01/02 20:40:58 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function returns a pointer to the first
// occurrence of the character i.e.
// "search_chr" in the string(str), or NULL if the character is not found.

char	*ft_strchr(const char *str, int search_chr)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char) search_chr)
			return ((char *)str);
		str++;
	}
	if (*str == (char) search_chr)
		return ((char *)str);
	return (NULL);
}
