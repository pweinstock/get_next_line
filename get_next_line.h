/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:28:15 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/20 16:14:22 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
int		ft_memmove(char *dst, char *src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_readnjoin(int fd, char *buff, char *temp);

#endif