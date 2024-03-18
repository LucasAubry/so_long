/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:02:11 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:58:15 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data_befor_map(t_game *game)
{
	game->c_vide = 0;
	game->c_wall = 0;
	game->c_item = 0;
	game->c_exit = 0;
	game->c_player = 0;
	game->c_bot = 0;
	game->string = NULL;
}

void	init_data(t_game *game)
{
	game->how_item_collect = 0;
	game->place_character[1] = 0;
	game->place_character[2] = 0;
	game->mouve = 0;
	game->life_of_player = 2;
	game->speed = 3;
	where_is_exit(game);
	how_bot(game);
}

void	where_is_exit(t_game *game)
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
			if (game->map[i][j] == 'E')
			{
				game->place_exit[1] = i;
				game->place_exit[2] = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	where_is_character(t_game *game)
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
			if (game->map[i][j] == 'P')
			{
				game->character_first_place[1] = i;
				game->character_first_place[2] = j;
			}
			j++;
		}
		i++;
	}
}
