/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:05 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/02 17:12:51 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "so_long.h"

void	ft_loop(t_game *game)
{
	mlx_loop_hook(game->mlx, &set_key, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

int main(void)
{
	void	*mlx;
	t_game *game;
	
	mlx = mlx_init(1500,1000,"so_long",true);
	if (!mlx)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1); //error message
	game->mlx = mlx;
	if (!init_map(game) || !verif_map(game))
	{
		free_all(game);
		return(1);
	}
	if (!set_texture(game, mlx))
	{
		free_all(game);
		return (1);
	}
	init_data(game);
	how_item(game);
	ft_loop(game);
	return (0);
}
