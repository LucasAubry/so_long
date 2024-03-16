/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:46:58 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/05 19:33:08 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_game *game)
{
	mlx_set_instance_depth(&game->image_exit_open->instances
		[game->image_exit_open->count -1], EXIT +10);
	mlx_set_instance_depth(&game->image_exit_close->instances
		[game->image_exit_close->count -1], EXIT -10);
}

void	take_item(t_game *game)
{
	game->how_item_collect += 1;
	if (game->how_item_collect == game->nbr_item)
		open_exit(game);
	return ;
}
