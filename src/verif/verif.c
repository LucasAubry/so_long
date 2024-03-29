/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:23:31 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:32:33 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_the_wall(t_game *game)
{
	if (!wall_up_down(game) || !wall_left_right(game))
		return (0);
	else
		return (1);
}

int	check_the_character(t_game *game)
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
			character(game, i, j, 0);
			j++;
		}
		i++;
	}
	if (!character(game, i, j, 1))
		return (0);
	else
		return (1);
}

int	check(t_game *game)
{
	if (!check_the_wall(game))
	{
		ft_printf("Error : la Map n'est pas compris entre des murs\n");
		return (0);
	}
	if (!check_the_character(game))
	{
		ft_printf
			("Error : La Map contient un doublou ou manque d'un element\n");
		return (0);
	}
	return (1);
}

int	verif_map(t_game *game)
{
	where_is_character(game);
	how_item(game);
	if (size_map(game) == 1)
	{
		ft_printf("Error : Ligne de taille differente\n");
		return (0);
	}
	if (check(game) == 0)
		return (0);
	if (!can_get_items(game))
	{
		ft_printf("Error : Un collectible n'est pas accessible\n");
		return (0);
	}
	if (!verif_finish(game))
	{
		ft_printf("Error : La Map n'est pas terminable\n");
		return (0);
	}
	return (1);
}

int	verif_finish(t_game *game)
{
	int	nb_item;
	int	exit;

	nb_item = 0;
	exit = 0;
	can_i_finish(game, game->character_first_place[1],
		game->character_first_place[2]);
	if (!check_modif_negatif(game, nb_item, exit))
		return (0);
	return (1);
}
