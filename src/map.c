/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:07 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/22 17:02:39 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "so_long.h"

int check_perror(fd)
{
		if (fd == -1)
		{
			perror("error_fd");
			return (1);
		}
		else
			return (0);
}

void	init_map(t_game *game)
{
	int fd;

	fd = open("maps/maps.ber", O_RDONLY);
	if (!check_perror(fd))
		return (0);
	while (get_next_line(fd) != NULL) 
		game->nbr_line +1;
	close(fd);
	game->map = malloc(sizeof(char *) * game->nbr_line);
	fd = open("maps/maps.ber", O_RDONLY);
	if (!check_perror(fd))
		return (0);
	map_in_tab(game);
	close(fd);
}
void	map_in_tab(t_game *game)
{
	int i;
	int fd;

	i = 0;
	fd = open("maps/maps.ber", O_RDONLY);
	if (!check_perror(fd))
		return (0);
	while(i < game->nbr_line || get_next_line(fd) != NULL)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}