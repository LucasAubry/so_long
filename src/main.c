/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:05 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/22 23:55:37 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "so_long.h"


// void texture(mlx_t* mlx)
// {
// 	int i = 0;
// }

int main(void){
	mlx_t	*mlx;
	t_game *game;
	game = NULL;

	mlx = mlx_init(500,500,"so_long",true);
	//texture(mlx);
	init_map(game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}