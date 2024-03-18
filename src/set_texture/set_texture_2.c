/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:39:02 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:40:42 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_floor(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->image_vide,
				x * TILE_SIZE, y * TILE_SIZE);
			mlx_set_instance_depth(&game->image_vide->instances
			[game->image_vide->count -1], VIDE);
			x++;
		}
		y++;
	}
}

int	set_texture(t_game *game, void *mlx)
{
	if (!load_texture(game))
		return (0);
	else
	{
		texture_to_image(game, mlx);
		set_floor(game);
		image_to_windows(game);
	}
	return (1);
}

void	image_to_windows(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			set_depth(game, what_texture(game, x, y), x, y);
			x++;
		}
		y++;
	}
}
