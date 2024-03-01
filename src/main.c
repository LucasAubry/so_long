/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:05 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/01 17:03:21 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "so_long.h"


// void texture(mlx_t* mlx)
// {
// 	int i = 0;
// }

int main(void)
{
	void	*mlx;
	t_game *game;
	
	mlx = mlx_init(800,400,"so_long",true);
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
	game->place_character[1] = 0;
	game->place_character[2] = 0;
	mlx_loop_hook(mlx, &set_key, game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
