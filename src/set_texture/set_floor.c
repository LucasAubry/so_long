/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:29:23 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/29 21:57:25 by Laubry           ###   ########.fr       */
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