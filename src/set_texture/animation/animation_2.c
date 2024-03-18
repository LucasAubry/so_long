/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:50:46 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 18:32:03 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation(t_game *game, char c)
{
	static char	x = 'E';
	static int	tick = 0;

	tick++;
	if (c != 'E')
		x = c;
	if (x == 'L')
	{
		if (tick % 5)
			l_if(game);
		else
			l_else(game);
	}
	else if (x == 'R')
	{
		if (tick % 5)
			e_if(game);
		else
			e_else(game);
	}
}

void	anim_bot_1(t_game *game, int rand, int i)
{
	if (i == 5)
	{
		mlx_set_instance_depth(&game->image_bot_1->instances
		[game->image_bot_1->count - rand], WALL +5);
		mlx_set_instance_depth(&game->image_bot_2->instances
		[game->image_bot_2->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_3->instances
		[game->image_bot_3->count - rand], WALL -5);
	}
	else if (i == 10)
	{
		mlx_set_instance_depth(&game->image_bot_1->instances
		[game->image_bot_1->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_2->instances
		[game->image_bot_2->count - rand], WALL +5);
		mlx_set_instance_depth(&game->image_bot_3->instances
		[game->image_bot_3->count - rand], WALL -5);
	}
}

void	anim_bot(t_game *game)
{
	static int	tick = 0;
	static int	rand = 0;

	tick++;
	if (!game->nbr_bot)
		return ;
	rand = ft_rand_int(game->nbr_bot);
	if (tick == 5 || tick == 20)
		anim_bot_1(game, rand, 5);
	else if (tick == 10 || tick == 25)
		anim_bot_1(game, rand, 10);
	else if (tick == 15 || tick == 30)
	{
		mlx_set_instance_depth(&game->image_bot_1->instances
		[game->image_bot_1->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_2->instances
		[game->image_bot_2->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_3->instances
		[game->image_bot_3->count - rand], WALL +5);
		if (tick != 15)
			tick = 0;
	}
}
