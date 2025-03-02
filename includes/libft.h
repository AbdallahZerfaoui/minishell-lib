/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:01:32 by azerfaou          #+#    #+#             */
/*   Updated: 2025/03/02 19:40:58 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "garbage_collector.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// Functions of libc (23)
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t nitems, size_t size);
char				*ft_strdup(const char *s);

// Addictional functions (12)
char				*ft_strncpy(char *destination, const char *source,
						size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_all(char *str, ...);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int value);
void				ft_putstr_fd(int fd, char *s);
void				ft_putnbr_fd(int n, int fd);

#endif