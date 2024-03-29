/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:43:38 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/21 15:36:17 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	ptr = (char *)ft_calloc(lens1 + lens2 + 1, sizeof(char));
	if (!ptr)
		return (0);
	while (i < lens1)
	{
		ptr[i] = s1[i];
		i++;
	}
	free(s1);
	while (i < lens1 + lens2)
	{
		ptr[i] = s2[i - lens1];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[len] != 0)
		len++;
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	ft_bzero(ptr, len + 1);
	if (!ptr)
		return (0);
	while (s1[i] != '\n' && s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = s1[i];
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

int	ft_memmove(char *dst, char *src)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	while (dst[i] != 0)
	{
		dst[i] = 0;
		i++;
	}
	return (0);
}
