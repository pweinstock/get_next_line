/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:27:43 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/17 16:19:09 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*temp;
	int				check = 0;
	int				nlpos;
	char			*line;
	int				rt;
	static int		static_check;

	if (static_check == 1 || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!temp)
		temp = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_bzero(buff, BUFFER_SIZE + 1);
	while (check == 0)
	{
		rt = read(fd, buff, BUFFER_SIZE);
		if (rt == 0)
			break;
		temp = ft_strjoin(temp, buff);
		nlpos = 0;
		while (buff[nlpos])
		{
			if (buff[nlpos] == '\n')
				check = 1;
			nlpos++;	
		}
		ft_bzero(buff, BUFFER_SIZE);
	}
	free(buff);
	if (temp[0] == 0)
		return (0);
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
