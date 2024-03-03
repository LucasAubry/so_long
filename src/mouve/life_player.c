/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 02:25:39 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/03 07:36:41 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lose_hp(t_game *game)
{
	if (game->life_of_player == 2)
	{
		game->life_of_player -= 1;
		mlx_set_instance_depth(&game->image_explosion->instances[game->image_explosion->count - 1], CHARACTER +49);
		// mlx_set_instance_depth(&game->image_vide_player->instances[game->image_vide->count +1], CHARACTER +50 );
		mlx_set_instance_depth(&game->image_brock_character->instances[0], CHARACTER + 52);
		mlx_set_instance_depth(&game->image_brock_character_f1->instances[0], CHARACTER + 51);
		game->speed = 20;
	}
	else if (game->life_of_player == 1)
	{
		game->life_of_player -= 1;
		mlx_set_instance_depth(&game->image_explosion->instances[game->image_explosion->count - 1], CHARACTER +49);
		// mlx_set_instance_depth(&game->image_vide_player->instances[game->image_vide->count +1], CHARACTER +50);
		mlx_set_instance_depth(&game->image_brock_character->instances[0], CHARACTER + 52);
		mlx_set_instance_depth(&game->image_brock_character_f1->instances[0], CHARACTER + 51);
		game->speed = 20;
	}
	else if (game->life_of_player <= 0)
		end_game(game);
}

