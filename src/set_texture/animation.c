/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:03:27 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/03 07:41:15 by Laubry           ###   ########.fr       */
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




// void	anim_wall(t_game *game)
// {
// 	// if (tick % 10)
// 	// {
// 	// 	mlx_set_instance_depth(&game->image_wall->instances[game->image_wall->count - 1], WALL +5);
// 	// 	mlx_set_instance_depth(&game->image_wall_frame2->instances[game->image_wall->count - 1], WALL -5);
// 	// 	mlx_set_instance_depth(&game->image_wall_frame3->instances[game->image_wall->count - 1], WALL -5);
// 	// }
// 	// else if (tick %  55)
// 	// {
// 	// 	mlx_set_instance_depth(&game->image_wall->instances[game->image_wall->count - 1], WALL -5);
// 	// 	mlx_set_instance_depth(&game->image_wall_frame2->instances[game->image_wall->count - 1], WALL +5);
// 	// 	mlx_set_instance_depth(&game->image_wall_frame3->instances[game->image_wall->count - 1], WALL -5);
// 	// }
// 	// else if (tick % 32)
// 	// {
// 	// 	mlx_set_instance_depth(&game->image_wall->instances[game->image_wall->count - 1], WALL -5);
// 	// 	mlx_set_instance_depth(&game->image_wall_frame2->instances[game->image_wall->count - 1], WALL -5);
// 	// 	mlx_set_instance_depth(&game->image_wall_frame3->instances[game->image_wall->count - 1], WALL +5);
// 	// }
// }




void	anim_bot(t_game *game)
{
	static int tick = 0;
	tick++;
	static int rand = 0;
	rand = ft_rand_int(game->nbr_bot);
	if (tick == 5 ||tick == 20)
	{
		mlx_set_instance_depth(&game->image_bot_1->instances[game->image_bot_1->count - rand], WALL +5);
		mlx_set_instance_depth(&game->image_bot_2->instances[game->image_bot_2->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_3->instances[game->image_bot_3->count - rand], WALL -5);
	}
	else if (tick == 10 ||tick == 25)
	{
		mlx_set_instance_depth(&game->image_bot_1->instances[game->image_bot_1->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_2->instances[game->image_bot_2->count - rand], WALL +5);
		mlx_set_instance_depth(&game->image_bot_3->instances[game->image_bot_3->count - rand], WALL -5);
	}
	else if (tick == 15 || tick == 30)
	{
		mlx_set_instance_depth(&game->image_bot_1->instances[game->image_bot_1->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_2->instances[game->image_bot_2->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_3->instances[game->image_bot_3->count - rand], WALL +5);
		if (tick != 15)
			tick = 0;
	}
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
	// anim_wall(game);
}
