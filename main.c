/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:23:01 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/20 10:42:02 by pweinsto         ###   ########.fr       */
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
	fd = open("tester/files/empty", O_RDONLY);
	while (i <= 15)
	{
		buf = get_next_line(1000);
		printf("fd: %s", buf);
		free(buf);
		i++;
	}
	return (0);
}
