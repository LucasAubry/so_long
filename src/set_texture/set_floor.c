/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:29:23 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:40:02 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	carpet_u(t_game *game, int x, int y)
{
	game->map[y -1][x] = 0;
	mlx_image_to_window(game->mlx, game->image_vide,
		x * TILE_SIZE, (y -1) * TILE_SIZE);
	take_item(game);
}

void	carpet_d(t_game *game, int x, int y)
{
	game->map[y +1][x] = 0;
	mlx_image_to_window(game->mlx, game->image_vide,
		x * TILE_SIZE, (y +1) * TILE_SIZE);
	take_item(game);
}

void	carpet_l(t_game *game, int x, int y)
{
	game->map[y][x -1] = 0;
	mlx_image_to_window(game->mlx, game->image_vide,
		(x -1) * TILE_SIZE, y * TILE_SIZE);
	take_item(game);
}

void	carpet_r(t_game *game, int x, int y)
{
	game->map[y][x +1] = 0;
	mlx_image_to_window(game->mlx, game->image_vide,
		(x +1) * TILE_SIZE, y * TILE_SIZE);
	take_item(game);
}

void	set_carpet(t_game *game, int x, int y, char c)
{
	if (c == 'U')
		carpet_u(game, x, y);
	else if (c == 'D')
		carpet_d(game, x, y);
	else if (c == 'L')
		carpet_l(game, x, y);
	else if (c == 'R')
		carpet_r(game, x, y);
	mlx_set_instance_depth(&game->image_vide->instances
	[game->image_vide->count -1], VIDE +4);
}
