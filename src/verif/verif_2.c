/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:03:12 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:05:03 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_up_down(t_game *game)
{
	int	j;

	j = 0;
	while (game->map[0][j])
	{
		if (game->map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (game->map[game->size_y - 1][j])
	{
		if (game->map[game->size_y - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	wall_left_right(t_game *game)
{
	int	j;

	j = 0;
	while (j != game->size_y)
	{
		if (game->map[j][0] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (j != game->size_y)
	{
		if (game->map[j][game->size_x - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	can_get_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				if (game->map[i +1][j] == '1' && game->map[i -1][j] == '1' &&
					game->map[i][j +1] == '1' && game->map[i][j -1] == '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	can_i_finish(t_game *game, int i, int j)
{
	game->map[i][j] *= -1;
	if (ft_strchr("0ECB", game->map[i +1][j]))
		can_i_finish(game, i +1, j);
	if (ft_strchr("0ECB", game->map[i -1][j]))
		can_i_finish(game, i -1, j);
	if (ft_strchr("0ECB", game->map[i][j +1]))
		can_i_finish(game, i, j +1);
	if (ft_strchr("0ECB", game->map[i][j -1]))
		can_i_finish(game, i, j -1);
}

int	verif_item_end(t_game *game, int nb_item, int exit)
{
	if (nb_item == game->nbr_item && exit == 1)
		return (1);
	else
		return (0);
}
