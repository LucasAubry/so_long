/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:03:27 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 18:31:38 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	l_if(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_left->instances
	[game->image_character_left->count - 1], CHARACTER -12);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances
	[game->image_character_left_frame2->count - 1], CHARACTER +12);
}

void	l_else(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_left->instances
	[game->image_character_left->count - 1], CHARACTER +12);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances
	[game->image_character_left_frame2->count - 1], CHARACTER -12);
}

void	e_if(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right->count - 1], CHARACTER -12);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right_frame2->count - 1], CHARACTER +12);
}

void	e_else(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right->count - 1], CHARACTER +12);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right_frame2->count - 1], CHARACTER -12);
}
