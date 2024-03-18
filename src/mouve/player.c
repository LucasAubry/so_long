/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:19 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:59:54 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	where_is(t_game *game, char c, char z)
{
	int	x;
	int	y;

	x = game->image_character_right->instances[0].x / TILE_SIZE;
	y = game->image_character_right->instances[0].y / TILE_SIZE;
	if (c == 'U' && !ft_up(game, x, y, z))
		return (0);
	else if (c == 'D' && !ft_down(game, x, y, z))
		return (0);
	else if (c == 'L' && !ft_left(game, x, y, z))
		return (0);
	else if (c == 'R' && !ft_right(game, x, y, z))
		return (0);
	mlx_set_instance_depth(&game->image_explosion->instances
	[game->image_explosion->count - 1], CHARACTER -53);
	return (1);
}

void	keys(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		if (where_is(game, 'U', '1'))
			up_key(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		if (where_is(game, 'D', '1'))
			down_key(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		if (where_is(game, 'L', '1'))
			left_key(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		if (where_is(game, 'R', '1'))
			right_key(game);
}

void	set_key(void *param)
{
	t_game		*game;
	static int	tick = 0;

	tick++;
	game = (t_game *)param;
	if_is_finish(param);
	anim_bot(param);
	if (game->life_of_player == 1)
	{
		mlx_set_instance_depth
			(&game->image_brock_character->instances[0], CHARACTER + 51);
		mlx_set_instance_depth
			(&game->image_explosion->instances[0], CHARACTER -53);
	}
	game->tick = tick;
	if (tick % game->speed)
		return ;
	animation(game, 'E');
	keys(game);
	mlx_set_instance_depth
		(&game->image_brock_character_f1->instances[0], CHARACTER - 51);
}
