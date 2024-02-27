/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:23:31 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/27 15:03:31 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int size_map(t_game *game)
{
	int i;
	
	i = 0;
	while (game->map[i])
	{
		if (i > 0 && ft_strlen(game->map[i - 1]) != ft_strlen(game->map[i]))
			return 1;
		i++;
	}
	return 0;
}

int check_the_wall(t_game *game)
{
	if (!wall_up_down(game) || !wall_left_right(game))
		return(0);
	else
		return(1);
}

int	check_the_character(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			character(game, i, j, 0);
			j++;
		}
		i++;
	}
	if (!character(game, i, j, 1))
		return (0);
	else
		return(1);
}

int verif_map(t_game *game)
{
	if (size_map(game) == 1)
	{
		ft_printf("Error : Ligne de taille differente\n");
		return (0);
	}
	if (!check_the_wall(game))
	{
		ft_printf("Error : la Map n'est pas compris entre des murs\n");
		return(0);
	}
	if (!check_the_character(game))
	{
		ft_printf("Error : La Map contient un doublou ou manque d'un element\n");
		return(0);
	}
	return(1);
}
