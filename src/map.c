/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:07 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/01 17:59:48 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "so_long.h"

int	check_perror(int fd)
{
	if (fd == -1)
	{
		perror("Error_fd");
		return (0);
	}
	else
		return (1);
}

int	map_in_tab(t_game *game)
{
	int i;
	int fd;
	char *temp;

	i = 0;
	fd = open("asset/maps/maps.ber", O_RDONLY);
	if (!check_perror(fd))
		return (0);
	while(i < game->size_y)
	{
		temp = get_next_line(fd);
		game->map[i++] = ft_strtrim(temp, "\n");
		free(temp);
	}
	game->map[i] = NULL;
	close(fd);
	return(1);
}

int	init_map(t_game *game)
{
	int fd;

	fd = 0;
	set_size_y(game);
	game->map = malloc(sizeof(char *) * (game->size_y + 1));
	fd = open("asset/maps/maps.ber", O_RDONLY);
	if (!check_perror(fd))
		return (0);
	if (!map_in_tab(game))
		return(0);
	set_size_x(game);
	close(fd);
	return(1);
}
