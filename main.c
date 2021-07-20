/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:23:01 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/20 11:37:24 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*buf;
	int		fd;
	int		i;

	i = 0;
	fd = open("tester/files/43_no_nl", O_RDONLY);
	while (i <= 15)
	{
		buf = get_next_line(fd);
		printf("fd: %sx", buf);
		free(buf);
		i++;
	}
	return (0);
}
