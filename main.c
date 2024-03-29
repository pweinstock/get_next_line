/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:23:01 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/21 14:45:44 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*buf;
	int		fd;
	int		i;

	i = 0;
	fd = open("tester/files/alternate_line_nl_with_nl", O_RDONLY);
	while (i <= 15)
	{
		buf = get_next_line(fd);
		printf("fd: %s", buf);
		free(buf);
		i++;
	}
	return (0);
}
