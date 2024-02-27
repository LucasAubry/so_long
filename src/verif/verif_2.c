/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:03:12 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/26 23:27:38 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	character(t_game *game, int i, int j, int boule)
{
	static int vide = 0;
	static int wall = 0;
	static int item = 0;
	static int exit = 0;
	static int player = 0;

	if (boule == 1)
	{
		if(vide == 1 && wall == 1 && item == 1 && exit == 1 
			&& player == 1)
			return (1);
		else
			return (0);
	}
	if (game->map[i][j] == '0')
		vide = 1;
	if (game->map[i][j] == '1')
		wall = 1;
	if (game->map[i][j] == 'C')
		item = 1;
	if (game->map[i][j] == 'E')
		exit += 1;
	if (game->map[i][j] == 'P')
		player += 1;
	return(0);
}

int	wall_up_down(t_game *game)
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
