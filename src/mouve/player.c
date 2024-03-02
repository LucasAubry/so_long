/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:19 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/02 16:58:00 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	where_is(t_game *game, char c, char z)
{
	int x;
	int y;

	x = game->image_character_right->instances[0].x /TILE_SIZE;
	y = game->image_character_right->instances[0].y /TILE_SIZE;
	if (c == 'U' && !ft_up(game, x, y, z))
			return(0);
	else if (c == 'D' && !ft_down(game, x, y, z))
			return(0);
	else if (c == 'L' && !ft_left(game, x, y, z))
			return(0);
	else if (c == 'R' && !ft_right(game, x, y, z))
			return(0);
	return (1);
}

void up_key(t_game *game)
{
	game->image_character_left->instances[0].y -=TILE_SIZE;
	game->image_character_right->instances[0].y -=TILE_SIZE;
	game->image_character_right_frame2->instances[0].y -=TILE_SIZE;
	game->image_character_left_frame2->instances[0].y -=TILE_SIZE;
	game->mouve +=1;
}

void down_key(t_game *game)
{
	game->image_character_left->instances[0].y +=TILE_SIZE;
	game->image_character_right->instances[0].y +=TILE_SIZE;
	game->image_character_right_frame2->instances[0].y +=TILE_SIZE;
	game->image_character_left_frame2->instances[0].y +=TILE_SIZE;
	game->mouve +=1;
}

void left_key(t_game *game)
{
	game->image_character_left->instances[0].x -=TILE_SIZE;
	game->image_character_right->instances[0].x -=TILE_SIZE;
	game->image_character_right_frame2->instances[0].x -=TILE_SIZE;
	game->image_character_left_frame2->instances[0].x -=TILE_SIZE;
	mlx_set_instance_depth(&game->image_character_right->instances[0], CHARACTER - 10);
	mlx_set_instance_depth(&game->image_character_left->instances[0], CHARACTER + 10);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances[0], CHARACTER - 10);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances[0], CHARACTER - 10);
	animation(game, 'L');
	game->mouve +=1;
}

void right_key(t_game *game)
{
	game->image_character_left->instances[0].x +=TILE_SIZE;
	game->image_character_right->instances[0].x +=TILE_SIZE;
	game->image_character_right_frame2->instances[0].x +=TILE_SIZE;
	game->image_character_left_frame2->instances[0].x +=TILE_SIZE;
	mlx_set_instance_depth(&game->image_character_right->instances[0], CHARACTER + 10);
	mlx_set_instance_depth(&game->image_character_left->instances[0], CHARACTER - 10);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances[0], CHARACTER - 10);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances[0], CHARACTER - 10);
	animation(game, 'R');
	game->mouve +=1;
}

void	set_key(void *param)
{
	t_game *game;
	static int tick = 0;

	tick++;
	if (tick % 3)
		return ;
	game =(t_game *)param;
	animation(game, 'E');
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(game->mlx, MLX_KEY_W))
		if (where_is(game, 'U', '1'))
			up_key(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S))
		if (where_is(game, 'D', '1'))
			down_key(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A))
		if (where_is(game, 'L', '1'))
			left_key(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		if (where_is(game, 'R', '1'))
			right_key(game);
}
