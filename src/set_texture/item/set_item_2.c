/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_item_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:43:03 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 18:09:19 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_depth_item_4(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_item_f4,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f4_1,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f4_2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f4_3,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_set_instance_depth(&game->image_item_f4->instances
	[game->image_item_f4->count - 1], ITEM);
	mlx_set_instance_depth(&game->image_item_f4_1->instances
	[game->image_item_f4_1->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f4_2->instances
	[game->image_item_f4_2->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f4_3->instances
	[game->image_item_f4_3->count - 1], VIDE -1);
}

void	set_depth_item_5(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_item_f5,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f5_1,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f5_2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f5_3,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_set_instance_depth(&game->image_item_f5->instances
	[game->image_item_f5->count - 1], ITEM);
	mlx_set_instance_depth(&game->image_item_f5_1->instances
	[game->image_item_f5_1->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f5_2->instances
	[game->image_item_f5_2->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f5_3->instances
	[game->image_item_f5_3->count - 1], VIDE -1);
}
