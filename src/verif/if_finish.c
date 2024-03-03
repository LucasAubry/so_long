/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 04:53:56 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/03 06:04:05 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_is_finish(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = game->image_character_right->instances[0].y /TILE_SIZE;
	j = game->image_character_right->instances[0].x /TILE_SIZE;
	x = game->place_exit[1];
	y = game->place_exit[2];
	if (game->how_item_collect == game->nbr_item && i == x && j == y)
		end_game(game);
	return ;
}