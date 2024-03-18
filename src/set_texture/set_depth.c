/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:02:56 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:39:30 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_depth_2(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_character_right,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_character_left,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_character_right_frame2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_character_left_frame2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_explosion,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_brock_character,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_brock_character_f1,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_vide,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_vide_player,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	set_depth_3(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_right->instances
	[game->image_character_right->count - 1], CHARACTER);
	mlx_set_instance_depth(&game->image_character_left->instances
	[game->image_character_left->count - 1], CHARACTER);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right_frame2->count - 1], CHARACTER);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances
	[game->image_character_left_frame2->count - 1], CHARACTER);
	mlx_set_instance_depth(&game->image_explosion->instances
	[game->image_explosion->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_brock_character->instances
	[game->image_brock_character->count -1], VIDE -1);
	mlx_set_instance_depth(&game->image_brock_character_f1->instances
	[game->image_brock_character_f1->count -1], VIDE -1);
	mlx_set_instance_depth(&game->image_vide->instances
	[game->image_vide->count -1], VIDE -10);
	mlx_set_instance_depth(&game->image_vide_player->instances[0],
		VIDE -10);
}

void	set_depth_4(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_wall,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_wall_frame2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_wall_frame3,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_set_instance_depth(&game->image_wall->instances
	[game->image_wall->count - 1], WALL);
	mlx_set_instance_depth(&game->image_wall->instances
	[game->image_wall_frame2->count - 1], WALL -2);
	mlx_set_instance_depth(&game->image_wall->instances
	[game->image_wall_frame3->count - 1], WALL -2);
}

void	set_depth(t_game *game, char w, int x, int y)
{
	if (w == 'P')
	{
		set_depth_2(game, x, y);
		set_depth_3(game);
	}
	else if (w == '1')
		set_depth_4(game, x, y);
	else if (w == 'C')
		set_item(game, x, y);
	else if (w == 'E')
	{
		mlx_image_to_window(game->mlx, game->image_exit_close,
			x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_exit_close->instances
		[game->image_exit_close->count - 1], EXIT +10);
		mlx_image_to_window(game->mlx, game->image_exit_open,
			x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_exit_open->instances
		[game->image_exit_open->count - 1], EXIT -10);
	}
	else if (w == 'B')
		set_depth_bot(game, x, y);
	else if (w == '0')
		return ;
}
