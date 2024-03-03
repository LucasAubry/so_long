/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:06:33 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/03 01:42:49 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void printf_map_terminal(t_game *game)
{
	for (int i = 0; game->map[i]; i++)
			printf("%s\n", game->map[i]);
}

int ft_rand_int(int max)
{
	int fd;
	int i;
	i = 0;
	fd = open("/dev/random", O_RDONLY);
	read(fd, &i, sizeof(int));
	if (i <= 0)
		i = -i;
	i = i % max;
	close(fd);
	return (i);
}
