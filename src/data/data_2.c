/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:15:59 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/19 15:30:37 by Laubry           ###   ########.fr       */
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
	if (game->map[0] == NULL)
		return ;
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
