/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:35:58 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/03 01:41:39 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_texture_bot(t_game *game)
{
	game->texture_bot_1 = mlx_load_png("asset/textures/bot/bot.png");
	if (game->texture_bot_1 == NULL)//message derreur
		return(0);

	game->texture_bot_2 = mlx_load_png("asset/textures/bot/bot_f1.png");
	if (game->texture_bot_2 == NULL)//message derreur
		return(0);

	game->texture_bot_3 = mlx_load_png("asset/textures/bot/bot_f2.png");
	if (game-> texture_bot_3== NULL)//message derreur
		return(0);


	game->texture_bot_4 = mlx_load_png("asset/textures/bot/bot_up_f1.png");
	if (game->texture_bot_4 == NULL)//message derreur
		return(0);


	game->texture_bot_5 = mlx_load_png("asset/textures/bot/bot_up_f2.png");
	if (game->texture_bot_5 == NULL)//message derreur
		return(0);

		
	game->texture_bot_6 = mlx_load_png("asset/textures/bot/bot_up_f3.png");
	if (game->texture_bot_6 == NULL)//message derreur
		return(0);
	return (1);
}


void	texture_to_image_bot(t_game *game, void *mlx)
{
	game->image_bot_1 = mlx_texture_to_image(mlx, game->texture_bot_1);
	game->image_bot_2 = mlx_texture_to_image(mlx, game->texture_bot_2);
	game->image_bot_3 = mlx_texture_to_image(mlx, game->texture_bot_3);
	game->image_bot_4 = mlx_texture_to_image(mlx, game->texture_bot_4);
	game->image_bot_5 = mlx_texture_to_image(mlx, game->texture_bot_5);
	game->image_bot_6 = mlx_texture_to_image(mlx, game->texture_bot_6);
	mlx_delete_texture(game->texture_bot_1);
	mlx_delete_texture(game->texture_bot_2);
	mlx_delete_texture(game->texture_bot_3);
	mlx_delete_texture(game->texture_bot_4);
	mlx_delete_texture(game->texture_bot_5);
	mlx_delete_texture(game->texture_bot_6);
}

void	set_depth_bot(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_bot_1, x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_bot_2, x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_bot_3, x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_bot_4, x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_bot_5, x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_bot_6, x * TILE_SIZE, y * TILE_SIZE);
	mlx_set_instance_depth(&game->image_bot_1->instances[game->image_bot_1->count - 1], BOT);
	mlx_set_instance_depth(&game->image_bot_2->instances[game->image_bot_2->count - 1], BOT -10);
	mlx_set_instance_depth(&game->image_bot_3->instances[game->image_bot_3->count - 1], BOT -10);
	mlx_set_instance_depth(&game->image_bot_4->instances[game->image_bot_4->count - 1], BOT -10);
	mlx_set_instance_depth(&game->image_bot_5->instances[game->image_bot_5->count - 1], BOT -10);
	mlx_set_instance_depth(&game->image_bot_6->instances[game->image_bot_6->count - 1], BOT -10);
}
