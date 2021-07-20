/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:27:43 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/20 16:19:03 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_readnjoin(int fd, char *buff, char *temp)
{
	int	check;
	int	rt;
	int i;

	rt = 0;
	check = 0;
	while (check == 0)
	{
		rt = read(fd, buff, BUFFER_SIZE);
		if (rt <= 0)
			break;
		temp = ft_strjoin(temp, buff);
		i = 0;
		while (buff[i])
		{
			if (buff[i] == '\n')
				check = 1;
			i++;	
		}
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*temp;
	int				nlpos;
	char			*line;
	static int		static_check;

	if (static_check == 1 || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!temp)
		temp = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp || !buff)
		return (0);
	temp = ft_readnjoin(fd, buff, temp);
	if (temp[0] == 0)
	{
		free(temp);
		temp = 0;
		return (0);
	}
	nlpos = 0;
	while (temp[nlpos] != 0)
	{	
		if (temp[nlpos] == '\n' )
		{
			line = ft_strdup(temp);
			ft_memmove(temp, temp + nlpos + 1);
			return (line);
		}
		nlpos++;
	}
	static_check = 1;
	line = ft_strdup(temp);
	free(temp);
	return (line);
}
