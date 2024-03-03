/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 02:25:39 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/03 04:45:16 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lose_hp(t_game *game)
{
	if (game->life_of_player == 2)
	{
		game->life_of_player -= 1;
		mlx_set_instance_depth(&game->image_explosion->instances[game->image_explosion->count - 1], CHARACTER +50);
	}
	else if (game->life_of_player == 1)
	{
		game->life_of_player -= 1;
		mlx_set_instance_depth(&game->image_explosion->instances[game->image_explosion->count - 1], CHARACTER +50);
	}
	else if (game->life_of_player <= 0)
		end_game(game);
}

