/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:03:14 by Laubry            #+#    #+#             */
/*   Updated: 2024/02/27 21:39:16 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42.h"

int	load_texture(t_game *game)
{
	game->vide = mlx_load_png("asset/textures/stone.png");
	if (game->vide == NULL)//message derreur
		return(0);
	game->wall = mlx_load_png("asset/textures/wood.png");
	if (game->wall == NULL)//message derreur
		return(0);
	game->item = mlx_load_png("asset/textures/poop.png");
	if (game->item == NULL)//message derreur
		return(0);
	game->exit = mlx_load_png("asset/textures/door.png");
	if (game->exit == NULL)//message derreur
		return(0);
	game->character = mlx_load_png("asset/textures/among_us_back.png");
	if (game->character == NULL)//message derreur
		return(0);
	return(1);
}

void	texture_to_image(t_game *game, void *mlx)
{
	game->image_vide = mlx_texture_to_image(mlx, game->vide);
	game->image_wall = mlx_texture_to_image(mlx, game->wall);
	game->image_item = mlx_texture_to_image(mlx, game->item);
	game->image_exit = mlx_texture_to_image(mlx, game->exit);
	game->image_character = mlx_texture_to_image(mlx, game->character);
	mlx_delete_texture(game->vide);
	mlx_delete_texture(game->wall);
	mlx_delete_texture(game->item);
	mlx_delete_texture(game->exit);
	mlx_delete_texture(game->character);
}

void	image_to_windows(t_game *game, void *mlx)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == '0')
				mlx_image_to_window(mlx, game->image_vide, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == '1')
				mlx_image_to_window(mlx, game->image_wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(mlx, game->image_item, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(mlx, game->image_exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'P')
				mlx_image_to_window(mlx, game->image_character, x * TILE_SIZE, y * TILE_SIZE);
		x += 1;
		}
	y += 1;
	}
}

int	set_texture(t_game *game, void *mlx)
{
	if (!load_texture(game))
		return(0);
	else
	{
		texture_to_image(game, mlx);
		image_to_windows(game, mlx);
	}
	return(1);
}



// mlx_texture_t *test;
// mlx_image_t *image;

// test = mlx_load_png("png/test1.png")
// 	if (test == NULL)
// 		error
// 	else 
// 		image = mlx_texture_to_image(mlx, test);
// 		mlx_delete_texture(test);
// 		mlx_image_to_window(mlx, image, x * 32, y * 32);
