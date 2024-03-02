/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:03:27 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/02 17:06:15 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	L_if(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_left->instances[game->image_character_left->count - 1], CHARACTER -12);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances[game->image_character_left_frame2->count - 1], CHARACTER +12);
}
void	L_else(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_left->instances[game->image_character_left->count - 1], CHARACTER +12);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances[game->image_character_left_frame2->count - 1], CHARACTER -12);
}

void	E_if(t_game *game)
{	
	mlx_set_instance_depth(&game->image_character_right_frame2->instances[game->image_character_right->count - 1], CHARACTER -12);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances[game->image_character_right_frame2->count - 1], CHARACTER +12);
}

void	E_else(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_right_frame2->instances[game->image_character_right->count - 1], CHARACTER +12);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances[game->image_character_right_frame2->count - 1], CHARACTER -12);
}

void	animation(t_game *game, char c)
{
	static char x = 'E';
	static int tick = 0;

	tick++;
	if (c != 'E')
		x = c;
	if (x == 'L')
	{
		if (tick % 5)
			L_if(game);
		else
			L_else(game);
	}
	else if (x == 'R')
	{
		if (tick % 5)
			E_if(game);
		else
			E_else(game);
	}
}
