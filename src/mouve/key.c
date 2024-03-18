/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:47:28 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:57:30 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_key(t_game *game)
{
	game->image_character_left->instances[0].y -= TILE_SIZE;
	game->image_character_right->instances[0].y -= TILE_SIZE;
	game->image_character_right_frame2->instances[0].y -= TILE_SIZE;
	game->image_character_left_frame2->instances[0].y -= TILE_SIZE;
	game->image_explosion->instances[0].y -= TILE_SIZE;
	game->image_brock_character->instances[0].y -= TILE_SIZE;
	game->image_brock_character_f1->instances[0].y -= TILE_SIZE;
	game->image_vide_player->instances[0].y -= TILE_SIZE;
	game->mouve += 1;
}

void	down_key(t_game *game)
{
	game->image_character_left->instances[0].y += TILE_SIZE;
	game->image_character_right->instances[0].y += TILE_SIZE;
	game->image_character_right_frame2->instances[0].y += TILE_SIZE;
	game->image_character_left_frame2->instances[0].y += TILE_SIZE;
	game->image_explosion->instances[0].y += TILE_SIZE;
	game->image_brock_character->instances[0].y += TILE_SIZE;
	game->image_brock_character_f1->instances[0].y += TILE_SIZE;
	game->image_vide_player->instances[0].y += TILE_SIZE;
	game->mouve += 1;
}

void	left_key(t_game *game)
{
	game->image_character_left->instances[0].x -= TILE_SIZE;
	game->image_character_right->instances[0].x -= TILE_SIZE;
	game->image_character_right_frame2->instances[0].x -= TILE_SIZE;
	game->image_character_left_frame2->instances[0].x -= TILE_SIZE;
	game->image_explosion->instances[0].x -= TILE_SIZE;
	game->image_brock_character->instances[0].x -= TILE_SIZE;
	game->image_brock_character_f1->instances[0].x -= TILE_SIZE;
	game->image_vide_player->instances[0].x -= TILE_SIZE;
	mlx_set_instance_depth
		(&game->image_character_right->instances[0], CHARACTER - 10);
	mlx_set_instance_depth
		(&game->image_character_left->instances[0], CHARACTER + 10);
	mlx_set_instance_depth
		(&game->image_character_left_frame2->instances[0], CHARACTER - 10);
	mlx_set_instance_depth
		(&game->image_character_right_frame2->instances[0], CHARACTER - 10);
	animation(game, 'L');
	game->mouve += 1;
}

void	right_key(t_game *game)
{
	game->image_character_left->instances[0].x += TILE_SIZE;
	game->image_character_right->instances[0].x += TILE_SIZE;
	game->image_character_right_frame2->instances[0].x += TILE_SIZE;
	game->image_character_left_frame2->instances[0].x += TILE_SIZE;
	game->image_explosion->instances[0].x += TILE_SIZE;
	game->image_brock_character->instances[0].x += TILE_SIZE;
	game->image_brock_character_f1->instances[0].x += TILE_SIZE;
	game->image_vide_player->instances[0].x += TILE_SIZE;
	mlx_set_instance_depth
		(&game->image_character_right->instances[0], CHARACTER + 10);
	mlx_set_instance_depth
		(&game->image_character_left->instances[0], CHARACTER - 10);
	mlx_set_instance_depth
		(&game->image_character_left_frame2->instances[0], CHARACTER - 10);
	mlx_set_instance_depth
		(&game->image_character_right_frame2->instances[0], CHARACTER - 10);
	animation(game, 'R');
	game->mouve += 1;
}
