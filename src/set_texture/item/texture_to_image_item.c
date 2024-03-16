/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_image_item.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 06:33:35 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/05 17:16:18 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delet_texture(t_game *game)
{
	mlx_delete_texture(game->item_f1);
	mlx_delete_texture(game->item_f1_1);
	mlx_delete_texture(game->item_f1_2);
	mlx_delete_texture(game->item_f1_3);
	mlx_delete_texture(game->item_f2);
	mlx_delete_texture(game->item_f2_1);
	mlx_delete_texture(game->item_f2_2);
	mlx_delete_texture(game->item_f2_3);
	mlx_delete_texture(game->item_f3);
	mlx_delete_texture(game->item_f3_1);
	mlx_delete_texture(game->item_f3_2);
	mlx_delete_texture(game->item_f3_3);
	mlx_delete_texture(game->item_f4);
	mlx_delete_texture(game->item_f4_1);
	mlx_delete_texture(game->item_f4_2);
	mlx_delete_texture(game->item_f4_3);
	mlx_delete_texture(game->item_f5);
	mlx_delete_texture(game->item_f5_1);
	mlx_delete_texture(game->item_f5_2);
	mlx_delete_texture(game->item_f5_3);
}

void	texure_to_image_item(t_game *game, void *mlx)
{
	game->image_item_f1 = mlx_texture_to_image(mlx, game->item_f1);
	game->image_item_f1_1 = mlx_texture_to_image(mlx, game->item_f1_1);
	game->image_item_f1_2 = mlx_texture_to_image(mlx, game->item_f1_2);
	game->image_item_f1_3 = mlx_texture_to_image(mlx, game->item_f1_3);
	game->image_item_f2 = mlx_texture_to_image(mlx, game->item_f2);
	game->image_item_f2_1 = mlx_texture_to_image(mlx, game->item_f2_1);
	game->image_item_f2_2 = mlx_texture_to_image(mlx, game->item_f2_2);
	game->image_item_f2_3 = mlx_texture_to_image(mlx, game->item_f2_3);
	game->image_item_f3 = mlx_texture_to_image(mlx, game->item_f3);
	game->image_item_f3_1 = mlx_texture_to_image(mlx, game->item_f3_1);
	game->image_item_f3_2 = mlx_texture_to_image(mlx, game->item_f3_2);
	game->image_item_f3_3 = mlx_texture_to_image(mlx, game->item_f3_3);
	game->image_item_f4 = mlx_texture_to_image(mlx, game->item_f4);
	game->image_item_f4_1 = mlx_texture_to_image(mlx, game->item_f4_1);
	game->image_item_f4_2 = mlx_texture_to_image(mlx, game->item_f4_2);
	game->image_item_f4_3 = mlx_texture_to_image(mlx, game->item_f4_3);
	game->image_item_f5 = mlx_texture_to_image(mlx, game->item_f5);
	game->image_item_f5_1 = mlx_texture_to_image(mlx, game->item_f5_1);
	game->image_item_f5_2 = mlx_texture_to_image(mlx, game->item_f5_2);
	game->image_item_f5_3 = mlx_texture_to_image(mlx, game->item_f5_3);
	delet_texture(game);
}
