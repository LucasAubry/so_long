/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:04:40 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:05:09 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	character(t_game *game, int i, int j, int boule)
{
	if (boule == 1)
	{
		if (game->c_vide == 1 && game->c_wall == 1 && game->c_item == 1
			&& game->c_exit == 1 && game->c_player == 1)
			return (1);
		else
			return (0);
	}
	if (game->map[i][j] == '0')
		game->c_vide = 1;
	if (game->map[i][j] == '1')
		game->c_wall = 1;
	if (game->map[i][j] == 'C')
		game->c_item = 1;
	if (game->map[i][j] == 'E')
		game->c_exit += 1;
	if (game->map[i][j] == 'P')
		game->c_player += 1;
	if (game->map[i][j] == 'B')
		game->c_bot += 1;
	return (0);
}

int	size_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (i > 0 && ft_strlen(game->map[i - 1]) != ft_strlen(game->map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_modif_negatif(t_game *game, int nb_item, int exit)
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
			if (game->map[i][j] < 0)
			{
				game->map[i][j] *= -1;
				if (game->map[i][j] == 'C')
					nb_item++;
				else if (game->map[i][j] == 'E')
					exit = 1;
			}
			j++;
		}
		i++;
	}
	if (!verif_item_end(game, nb_item, exit))
		return (0);
	return (1);
}
