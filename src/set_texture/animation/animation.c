/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:03:27 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/16 17:57:19 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	L_if(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_left->instances
	[game->image_character_left->count - 1], CHARACTER -12);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances
	[game->image_character_left_frame2->count - 1], CHARACTER +12);
}
void	L_else(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_left->instances
	[game->image_character_left->count - 1], CHARACTER +12);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances
	[game->image_character_left_frame2->count - 1], CHARACTER -12);
}

void	E_if(t_game *game)
{	
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right->count - 1], CHARACTER -12);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right_frame2->count - 1], CHARACTER +12);
}

void	E_else(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right->count - 1], CHARACTER +12);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right_frame2->count - 1], CHARACTER -12);
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


// void	anim_item(t_game *game)
// {
// 	int	rand;
// 	int tick_2;

// 	tick_2 = game->tick;
	
// 	if (tick_2 % 3 == 0 && game->image_item_f1->count > 0)
// 	{
// 		// printf("%lu gives : %p\n", game->image_item_f1->count, &game->image_item_f1->instances[game->image_item_f1->count]);
// 		rand = ft_rand_int(game->image_item_f1->count);
// 		mlx_set_instance_depth(&game->image_item_f1->instances[rand], ITEM +5);
// 		rand = ft_rand_int(game->image_item_f1_1->count);
// 		mlx_set_instance_depth(&game->image_item_f1_1->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f1_2->count);
// 		mlx_set_instance_depth(&game->image_item_f1_2->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f1_3->count);
// 		mlx_set_instance_depth(&game->image_item_f1_3->instances[rand], ITEM -5);
// 	}
// 	else if (tick_2 % 6 == 0 && game->image_item_f2->count > 0)
// 	{
// 		rand = ft_rand_int(game->image_item_f2->count);
// 		mlx_set_instance_depth(&game->image_item_f2->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f2_1->count);
// 		mlx_set_instance_depth(&game->image_item_f2_1->instances[rand], ITEM +5);
// 		rand = ft_rand_int(game->image_item_f2_2->count);
// 		mlx_set_instance_depth(&game->image_item_f2_2->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f2_3->count);
// 		mlx_set_instance_depth(&game->image_item_f2_3->instances[rand], ITEM -5);
// 	}
// 	else if (tick_2 % 9 == 0 && game->image_item_f3->count > 0)
// 	{
// 		rand = ft_rand_int(game->image_item_f3->count);
// 		mlx_set_instance_depth(&game->image_item_f3->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f3_1->count);
// 		mlx_set_instance_depth(&game->image_item_f3_1->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f3_2->count);
// 		mlx_set_instance_depth(&game->image_item_f3_2->instances[rand], ITEM +5);
// 		rand = ft_rand_int(game->image_item_f3_3->count);
// 		mlx_set_instance_depth(&game->image_item_f3_3->instances[rand], ITEM -5);
// 	}
// 	else if (tick_2 % 12 == 0 && game->image_item_f4->count > 0)
// 	{
// 		rand = ft_rand_int(game->image_item_f4->count);
// 		mlx_set_instance_depth(&game->image_item_f4->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f4_1->count);
// 		mlx_set_instance_depth(&game->image_item_f4_1->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f4_2->count);
// 		mlx_set_instance_depth(&game->image_item_f4_2->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f4_3->count);
// 		mlx_set_instance_depth(&game->image_item_f4_3->instances[rand], ITEM +5);
// 	}
// 	else if (tick_2 % 15 == 0 && game->image_item_f5->count > 0)
// 	{
// 		rand = ft_rand_int(game->image_item_f5->count);
// 		mlx_set_instance_depth(&game->image_item_f5->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f5_1->count);
// 		mlx_set_instance_depth(&game->image_item_f5_1->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f5_2->count);
// 		mlx_set_instance_depth(&game->image_item_f5_2->instances[rand], ITEM -5);
// 		rand = ft_rand_int(game->image_item_f5_3->count);
// 		mlx_set_instance_depth(&game->image_item_f5_3->instances[rand], ITEM +5);
// 	}
// }
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
	tick++;
	static int	rand = 0;

	if (!game->nbr_bot)
		return ;
	rand = ft_rand_int(game->nbr_bot);
	if (tick == 5 ||tick == 20)
		anim_bot_1(game, rand, 5);
	else if (tick == 10 ||tick == 25)
		anim_bot_1(game, rand, 10);
	else if (tick == 15 || tick == 30)
	{
		mlx_set_instance_depth(&game->image_bot_1->instances
		[game->image_bot_1->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_2->instances[game->image_bot_2->count - rand], WALL -5);
		mlx_set_instance_depth(&game->image_bot_3->instances
		[game->image_bot_3->count - rand], WALL +5);
		if (tick != 15)
			tick = 0;
	}
}

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
	// anim_item(game);
	// anim_wall(game);
}
