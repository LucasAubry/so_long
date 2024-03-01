/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:19 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/01 18:10:55 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	where_is_wall(t_game *game, char c)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (c == 'U')
	{
		x = game->image_character_right->instances[0].x /32;
		y = game->image_character_right->instances[0].y /32;
		if (game->map[y-1][x] == '1')
			return(0);
	}
	else if (c == 'D')
	{
		x = game->image_character_right->instances[0].x /32;
		y = game->image_character_right->instances[0].y /32;
		if (game->map[y+1][x] == '1')
			return(0);
	}
	else if (c == 'L')
	{
		x = game->image_character_right->instances[0].x /32;
		y = game->image_character_right->instances[0].y /32;
		if (game->map[y][x-1] == '1')
			return(0);
	}
	else if (c == 'R')
	{
		x = game->image_character_right->instances[0].x /32;
		y = game->image_character_right->instances[0].y /32;
		if (game->map[y][x+1] == '1')
			return(0);
	}
	return (1);
}

void up_key(t_game *game)
{
	game->image_character_left->instances[0].y -=32;
	game->image_character_right->instances[0].y -=32;
	game->place_character[1] = game->image_character_right->instances[0].y;
}

void down_key(t_game *game)
{
	game->image_character_left->instances[0].y +=32;
	game->image_character_right->instances[0].y +=32;
	game->place_character[1] = game->image_character_right->instances[0].y;
}

void left_key(t_game *game)
{
	game->image_character_left->instances[0].x -=32;
	game->image_character_right->instances[0].x -=32;
	mlx_set_instance_depth(&game->image_character_right->instances[0], CHARACTER - 10);
	mlx_set_instance_depth(&game->image_character_left->instances[0], CHARACTER + 10);
	game->place_character[2] = game->image_character_right->instances[0].x;
}

void right_key(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_right->instances[0], CHARACTER + 10);
	mlx_set_instance_depth(&game->image_character_left->instances[0], CHARACTER - 10);
	game->image_character_left->instances[0].x +=32;
	game->image_character_right->instances[0].x +=32;
	game->place_character[2] = game->image_character_right->instances[0].x;
}

void	set_key(void *param)
{
	t_game *game;
	static int tick = 0;

	tick++;
	if (tick % 3)
		return ;
	game =(t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(game->mlx, MLX_KEY_W))
		if (where_is_wall(game, 'U'))
			up_key(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S))
		if (where_is_wall(game, 'D'))
			down_key(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A))
		if (where_is_wall(game, 'L'))
			left_key(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		if (where_is_wall(game, 'R'))
			right_key(game);
}
