/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 03:36:15 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 18:30:13 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_depth_item_1(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_item_f1,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f1_1,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f1_2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f1_3,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_set_instance_depth(&game->image_item_f1->instances
	[game->image_item_f1->count - 1], ITEM);
	mlx_set_instance_depth(&game->image_item_f1_1->instances
	[game->image_item_f1_1->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f1_2->instances
	[game->image_item_f1_2->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f1_3->instances
	[game->image_item_f1_3->count - 1], ITEM -3);
}

void	set_depth_item_2(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_item_f2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f2_1,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f2_2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f2_3,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_set_instance_depth(&game->image_item_f2->instances
	[game->image_item_f2->count - 1], ITEM);
	mlx_set_instance_depth(&game->image_item_f2_1->instances
	[game->image_item_f2_1->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f2_2->instances
	[game->image_item_f2_2->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f2_3->instances
	[game->image_item_f2_3->count - 1], VIDE -1);
}

void	set_depth_item_3(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_item_f3,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f3_1,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f3_2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_item_f3_3,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_set_instance_depth(&game->image_item_f3->instances
	[game->image_item_f3->count - 1], ITEM);
	mlx_set_instance_depth(&game->image_item_f3_1->instances
	[game->image_item_f3_1->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f3_2->instances
	[game->image_item_f3_2->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_item_f3_3->instances
	[game->image_item_f3_3->count - 1], VIDE -1);
}

void	set_item(t_game *game, int x, int y)
{
	int	i;

	i = ft_rand_int(5);
	if (i <= 1)
		set_depth_item_1(game, x, y);
	else if (i == 2)
		set_depth_item_2(game, x, y);
	if (i == 3)
		set_depth_item_3(game, x, y);
	if (i == 4)
		set_depth_item_4(game, x, y);
	else if (i == 5)
		set_depth_item_5(game, x, y);
}
