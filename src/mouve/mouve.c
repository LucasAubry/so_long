/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:20:02 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/02 15:29:51 by Laubry           ###   ########.fr       */
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
			set_carpet(game, x, y, 'U');
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
			set_carpet(game, x, y, 'D');
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
			set_carpet(game, x, y, 'L');
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
			set_carpet(game, x, y, 'R');
		return (1);
	}
}
