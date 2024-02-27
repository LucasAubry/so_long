/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:05 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/27 14:13:31 by Laubry           ###   ########.fr       */
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
	
	mlx = mlx_init(500,500,"so_long",true);
	if (!mlx)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1); //error message
	if (!init_map(game) || !verif_map(game))
	{
		free_all(game);
		return(1);
	}
	set_texture(game, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

// mlx init iamge windos 