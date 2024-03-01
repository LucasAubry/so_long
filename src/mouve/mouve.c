/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:20:02 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/01 22:34:39 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_up(t_game *game, int x, int y, char z)
{
	if (game->map[y-1][x] == z)
		return (0);
	else
	{
		if (game->map[y-1][x] == 'C')
		{
			game->map[y-1][x] = 0;
			printf("%d\n", y);
			printf("%d\n", x);
			mlx_image_to_window(game->mlx, game->image_vide, x * TILE_SIZE, (y-1) * TILE_SIZE);
			mlx_set_instance_depth(&game->image_vide->instances[game->image_vide->count -1], VIDE +4);
			take_item(game);
		}
		return (1);
	}
}

int	ft_down(t_game *game, int x, int y, char z)
{
	if (game->map[y+1][x] == z)
			return(0);
	else
	{
		if (game->map[y+1][x] == 'C')
		{
			game->map[y+1][x] = 0;
			mlx_image_to_window(game->mlx, game->image_vide, x * TILE_SIZE, (y+1) * TILE_SIZE);
			mlx_set_instance_depth(&game->image_vide->instances[game->image_vide->count -1], VIDE +4);
			take_item(game);
		}
		return (1);
	}
}

int	ft_left(t_game *game, int x, int y, char z)
{
	if (game->map[y][x-1] == z)
			return(0);
	else
	{
		if (game->map[y][x-1] == 'C')
		{
			game->map[y][x-1] = 0;
			mlx_image_to_window(game->mlx, game->image_vide, (x-1) * TILE_SIZE, y * TILE_SIZE);
			mlx_set_instance_depth(&game->image_vide->instances[game->image_vide->count -1], VIDE +4);
			take_item(game);
		}
		return (1);
	}
}

int	ft_right(t_game *game, int x, int y, char z)
{
	if (game->map[y][x+1] == z)
			return(0);
	else
	{
		if (game->map[y][x+1] == 'C')
		{
			game->map[y][x+1] = 0;
			mlx_image_to_window(game->mlx, game->image_vide, (x+1) * TILE_SIZE, y * TILE_SIZE);
			mlx_set_instance_depth(&game->image_vide->instances[game->image_vide->count -1], VIDE +4);
			take_item(game);
		}
		return (1);
	}
}