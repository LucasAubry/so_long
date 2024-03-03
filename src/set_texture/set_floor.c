/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:29:23 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/03 04:27:19 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_floor(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->image_vide, x * TILE_SIZE, y * TILE_SIZE);
			mlx_set_instance_depth(&game->image_vide->instances[game->image_vide->count -1], VIDE);
			x++;
		}
		y++;
	}
}

void	set_carpet(t_game *game, int x, int y, char c)
{
	if (c == 'U')
	{
		game->map[y-1][x] = 0;
		mlx_image_to_window(game->mlx, game->image_vide, x * TILE_SIZE, (y-1) * TILE_SIZE);
		take_item(game);
	}
	else if (c == 'D')
	{
		game->map[y+1][x] = 0;
		mlx_image_to_window(game->mlx, game->image_vide, x * TILE_SIZE, (y+1) * TILE_SIZE);
		take_item(game);
	}
	else if (c == 'L')
	{
		game->map[y][x-1] = 0;
		mlx_image_to_window(game->mlx, game->image_vide, (x-1) * TILE_SIZE, y * TILE_SIZE);
		take_item(game);
	}
	else if (c == 'R')
	{
		game->map[y][x+1] = 0;
		mlx_image_to_window(game->mlx, game->image_vide, (x+1) * TILE_SIZE, y * TILE_SIZE);
		take_item(game);
	}
	mlx_set_instance_depth(&game->image_vide->instances[game->image_vide->count -1], VIDE +4);
}
