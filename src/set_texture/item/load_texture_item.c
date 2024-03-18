/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 06:25:49 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 18:29:20 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_texture_item_1(t_game *game)
{
	game->item_f1 = mlx_load_png
		("asset/textures/item/all_orange.png");
	if (game->item_f1 == NULL)
		return (0);
	game->item_f1_1 = mlx_load_png
		("asset/textures/item/all_orange_f1.png");
	if (game->item_f1_1 == NULL)
		return (0);
	game->item_f1_2 = mlx_load_png
		("asset/textures/item/all_orange_f2.png");
	if (game->item_f1_2 == NULL)
		return (0);
	game->item_f1_3 = mlx_load_png
		("asset/textures/item/all_orange_f3.png");
	if (game->item_f1_3 == NULL)
		return (0);
	return (1);
}

int	load_texture_item_2(t_game *game)
{
	game->item_f2 = mlx_load_png
		("asset/textures/item/bleu.png");
	if (game->item_f2 == NULL)
		return (0);
	game->item_f2_1 = mlx_load_png("asset/textures/item/bleu_f1.png");
	if (game->item_f2_1 == NULL)
		return (0);
	game->item_f2_2 = mlx_load_png("asset/textures/item/bleu_f2.png");
	if (game->item_f2_2 == NULL)
		return (0);
	game->item_f2_3 = mlx_load_png("asset/textures/item/bleu_f3.png");
	if (game->item_f2_3 == NULL)
		return (0);
	return (1);
}

int	load_texture_item_3(t_game *game)
{
	game->item_f3 = mlx_load_png("asset/textures/item/orange.png");
	if (game->item_f3 == NULL)
		return (0);
	game->item_f3_1 = mlx_load_png("asset/textures/item/orange_f1.png");
	if (game->item_f3_1 == NULL)
		return (0);
	game->item_f3_2 = mlx_load_png("asset/textures/item/orange_f2.png");
	if (game->item_f3_2 == NULL)
		return (0);
	game->item_f3_3 = mlx_load_png("asset/textures/item/orange_f3.png");
	if (game->item_f3_3 == NULL)
		return (0);
	return (1);
}

int	load_texture_item_4(t_game *game)
{
	game->item_f4 = mlx_load_png("asset/textures/item/rouge.png");
	if (game->item_f4 == NULL)
		return (0);
	game->item_f4_1 = mlx_load_png("asset/textures/item/rouge_f1.png");
	if (game->item_f4_1 == NULL)
		return (0);
	game->item_f4_2 = mlx_load_png("asset/textures/item/rouge_f2.png");
	if (game->item_f4_2 == NULL)
		return (0);
	game->item_f4_3 = mlx_load_png("asset/textures/item/rouge_f3.png");
	if (game->item_f4_3 == NULL)
		return (0);
	game->item_f5 = mlx_load_png("asset/textures/item/red.png");
	if (game->item_f5 == NULL)
		return (0);
	game->item_f5_1 = mlx_load_png("asset/textures/item/red_f1.png");
	if (game->item_f5_1 == NULL)
		return (0);
	game->item_f5_2 = mlx_load_png("asset/textures/item/red_f2.png");
	if (game->item_f5_2 == NULL)
		return (0);
	game->item_f5_3 = mlx_load_png("asset/textures/item/red_f3.png");
	if (game->item_f5_3 == NULL)
		return (0);
	return (1);
}

int	load_texture_item(t_game *game)
{
	int	i;

	i = 1;
	i = load_texture_item_1(game);
	i = load_texture_item_2(game);
	i = load_texture_item_3(game);
	i = load_texture_item_4(game);
	if (i == 0)
		return (0);
	else
		return (1);
}
