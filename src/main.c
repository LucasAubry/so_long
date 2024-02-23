/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:05 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/23 15:29:11 by Laubry           ###   ########.fr       */
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
	// mlx_t	*mlx;
	t_game *game;
	game = malloc(sizeof(t_game));

	// mlx = mlx_init(500,500,"so_long",true);
	//texture(mlx);
	if (!init_map(game))
	{
		free_all(game);
		return(0);
	}
	if (!verif_map(game))
	{
		free_all(game);
		return(0);
	}
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
}