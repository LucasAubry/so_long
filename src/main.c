/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:05 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/19 13:08:12 by Laubry           ###   ########.fr       */
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
	t_list	*data;

	mlx = mlx_init(500,500,"so_long",true);
	//texture(mlx);
	get_map();
	mlx_loop(mlx);
	mlx_terminate(mlx);
}