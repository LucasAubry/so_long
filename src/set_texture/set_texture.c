/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:03:14 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/01 01:59:53 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42.h"

int	load_texture(t_game *game)
{
		game->character_left = mlx_load_png("asset/textures/among_us_left.png");
		if (game->character_left == NULL)//message derreur
			return(0);
		game->character_rigth = mlx_load_png("asset/textures/among_us_right.png");
		if (game->character_rigth == NULL)
			return(0);
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
		return(1);
}

void	texture_to_image(t_game *game, void *mlx)
{
	game->image_character_left = mlx_texture_to_image(mlx, game->character_left);
	game->image_character_right = mlx_texture_to_image(mlx, game->character_rigth);
	game->image_vide = mlx_texture_to_image(mlx, game->vide);
	game->image_wall = mlx_texture_to_image(mlx, game->wall);
	game->image_item = mlx_texture_to_image(mlx, game->item);
	game->image_exit = mlx_texture_to_image(mlx, game->exit);
	mlx_delete_texture(game->vide);
	mlx_delete_texture(game->wall);
	mlx_delete_texture(game->item);
	mlx_delete_texture(game->exit);
	mlx_delete_texture(game->character_rigth);
	mlx_delete_texture(game->character_left);
	
}


void	set_depth(t_game *game, char w, int x, int y)
{
	if (w == 'P')
	{
		mlx_image_to_window(game->mlx, game->image_character_right, x * TILE_SIZE, y * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->image_character_left, x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_character_right->instances[game->image_character_right->count - 1], CHARACTER);
		mlx_set_instance_depth(&game->image_character_left->instances[game->image_character_left->count - 1], CHARACTER);
	}
	else if (w == '1')
	{
		mlx_image_to_window(game->mlx, game->image_wall, x * TILE_SIZE, y * TILE_SIZE);	
		mlx_set_instance_depth(&game->image_wall->instances[game->image_wall->count - 1], WALL);
	}
	else if (w == 'C')
	{
		mlx_image_to_window(game->mlx, game->image_item, x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_item->instances[game->image_item->count - 1], ITEM);
	}
	else if (w == 'E')
	{
		mlx_image_to_window(game->mlx, game->image_exit, x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_exit->instances[game->image_exit->count - 1], EXIT);
	}
	else if (w == '0')
		return ;
}

char	what_texture(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
		return('P');
	else if (game->map[y][x] == '1')
		return ('1');
	else if (game->map[y][x] == 'C')
		return('C');
	else if (game->map[y][x] == 'E')
		return ('E');
	else if (game->map[y][x] == '0')
		return('0');
	return ('0');
}
void	image_to_windows(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			set_depth(game, what_texture(game, x, y), x, y);
			x++;
		}
		y++;
	}
}

int	set_texture(t_game *game, void *mlx)
{
	if (!load_texture(game))
		return(0);
	else
	{
		texture_to_image(game, mlx);
		set_floor(game);
		image_to_windows(game);
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
