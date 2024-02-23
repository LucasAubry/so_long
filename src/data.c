/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:02:11 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/23 16:12:24 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_size_y(t_game *game)
{	
	int fd;
	char *temp;
	
	fd = open("maps/maps.ber", O_RDONLY);
	if (!check_perror(fd))
		return ;
	game->size_y = 0;
	while (1) 
	{
		temp = get_next_line(fd);
		if (temp == NULL) break;
		game->size_y += 1;
		free(temp);
	}
	close(fd);
}
void	set_size_x(t_game *game)
{
	int j;

	j = 0;
	int fd;
	fd = open("maps/maps.ber", O_RDONLY);
	if (!check_perror(fd))
		return ;
	game->size_x = 0;
	while (game->map[0][j] && game->map[0][j] != '\n')
		j++;
	game->size_x = j;
	close(fd);
}
