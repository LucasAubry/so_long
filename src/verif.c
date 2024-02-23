/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:23:31 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/23 16:53:13 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int size_map(t_game *game)
{
	int i;
	
	i = 0;
	while (game->map[i]) {
		if (i > 0 && ft_strlen(game->map[i - 1]) != ft_strlen(game->map[i])) {
			return 1;
		}
		i++;
	}
	return 0;
}

int wall_up_down(t_game *game)
{
	int j;

	j = 0;
	//up
	while(game->map[0][j])
	{
		if(game->map[0][j] != '1')
			return(0);
		j++;
	}
	j = 0;
	//down
	while(game->map[game->size_y - 1][j])
	{
		if (game->map[game->size_y - 1][j] != '1')
			return(0);
		j++;
	}
	return(1);
}

int wall_left_right(t_game *game)
{
	int j;

	j = 0;
	//left
	while(j != game->size_y)
	{
		if (game->map[j][0] != '1')
			return(0);
		j++;
	}
	j = 0;
	//right
	while(j != game->size_y)
	{
		if(game->map[j][game->size_x - 1] != '1')
			return(0);
		j++;
	}
	return(1);
}

int check_the_wall(t_game *game)
{
	if (!wall_up_down(game) || !wall_left_right(game))
		return(0);
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
	else if (size_map(game) == 2)
	{
		return (0);
	}
	if (!check_the_wall(game))
	{
		ft_printf("Error : la Map n'est pas compris entre des murs");
		return(0);
	}
	return(1);
}
