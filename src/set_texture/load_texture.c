/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 03:08:58 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:52:48 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_texture_character(t_game *game)
{
	game->character_left = mlx_load_png
		("asset/textures/after/64/rocket_left_big.png");
	if (game->character_left == NULL)
		return (0);
	game->character_rigth = mlx_load_png
		("asset/textures/after/64/rocket_right_big.png");
	if (game->character_rigth == NULL)
		return (0);
	game->character_left_frame2 = mlx_load_png
		("asset/textures/after/64/rocket_left_litle.png");
	if (game->character_left_frame2 == NULL)
		return (0);
	game->character_right_frame2 = mlx_load_png
		("asset/textures/after/64/rocket_right_litle.png");
	if (game->character_right_frame2 == NULL)
		return (0);
	game->brock_character = mlx_load_png
		("asset/textures/bot/amongus.png");
	if (game->brock_character == NULL)
		return (0);
	game->brock_character_f1 = mlx_load_png
		("asset/textures/bot/amongus_fire.png");
	if (game->brock_character_f1 == NULL)
		return (0);
	return (1);
}

int	load_texture_floor(t_game *game)
{
	game->vide = mlx_load_png("asset/textures/after/64/big_back.png");
	if (game->vide == NULL)
		return (0);
	game->vide_player = mlx_load_png("asset/textures/after/64/big_back.png");
	if (game->vide_player == NULL)
		return (0);
	return (1);
}

int	load_texture_wall(t_game *game)
{
	game->wall = mlx_load_png
		("asset/textures/after/64/black_hole_frame1.png");
	if (game->wall == NULL)
		return (0);
	game->wall_frame2 = mlx_load_png
		("asset/textures/after/64/black_hole_frame2.png");
	if (game->wall_frame2 == NULL)
		return (0);
	game->wall_frame3 = mlx_load_png
		("asset/textures/after/64/black_hole_frame3.png");
	if (game->wall_frame3 == NULL)
		return (0);
	return (1);
}

int	load_texture_exit(t_game *game)
{
	game->exit_close = mlx_load_png("asset/textures/door.png");
	if (game->exit_close == NULL)
		return (0);
	game->exit_open = mlx_load_png("asset/textures/door_open.png");
	if (game->exit_open == NULL)
		return (0);
	return (1);
}

int	load_texture_explosion(t_game *game)
{
	game->explosion = mlx_load_png
		("asset/textures/bot/explosion.png");
	if (game->explosion == NULL)
		return (0);
	return (1);
}
