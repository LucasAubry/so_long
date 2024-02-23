/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:23:31 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/23 12:22:03 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_verif(t_game *game)
{
	if (!size_map(game))
	{
		ft_printf("Error : Ligne de taille differante\n");
		return (0);
	}
}

int size_map(t_game *game)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	while(game->map[i])
	{
		
		i++;
	}
	while (game->map[i])
	{
		while(game->map[i][j])
			j++;
		if(temp != j)
			return(0);
		temp = j;
		j = 0;
		i++;
	}
	
	return(1);
}