/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:55:25 by azerfaou          #+#    #+#             */
/*   Updated: 2025/01/07 19:41:27 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_result;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len == 0 || start > s_len)
		return (ft_calloc(1, sizeof(char)));
	if ((start + len) > s_len)
		len = s_len - start;
	str_result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str_result)
		return (NULL);
	str_result = ft_strncpy(str_result, s + start, len);
	return (str_result);
}
