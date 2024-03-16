/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:02:11 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/16 19:09:44 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_size_y(t_game *game, char **argv)
{
	int		fd;
	char	*temp;

	fd = open(argv[1], O_RDONLY);
	if (!check_perror(fd))
		return ;
	game->size_y = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		game->size_y += 1;
		free(temp);
	}
	close(fd);
}

void	set_size_x(t_game *game, char **argv)
{
	int	j;
	int	fd;

	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (!check_perror(fd))
		return ;
	game->size_x = 0;
	while (game->map[0][j] && game->map[0][j] != '\n')
		j++;
	game->size_x = j;
	close(fd);
}

void	how_item(t_game *game)
{
	int	i;
	int	j;
	int	nbr_item;

	i = 0;
	j = 0;
	nbr_item = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				nbr_item++;
			j++;
		}
		i++;
	}
	game->nbr_item = nbr_item;
}

void	init_data_befor_map(t_game *game)
{
	game->c_vide = 0;
	game->c_wall = 0;
	game->c_item = 0;
	game->c_exit = 0;
	game->c_player = 0;
	game->c_bot = 0;
	game->string = NULL;
	// where_is_character(game);
	// how_item(game);
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
	// how_item(game);
	how_bot(game);
}

void	how_bot(t_game *game)
{
	int	i;
	int	j;
	int	nbr_bot;

	i = 0;
	j = 0;
	nbr_bot = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'B')
				nbr_bot++;
			j++;
		}
		i++;
	}
	game->nbr_bot = nbr_bot;
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
	int i;
	int j;

	i = 0;
	j = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
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
