/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:03:14 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/02 16:28:51 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42.h"

int	load_texture(t_game *game)
{
		game->character_left = mlx_load_png("asset/textures/after/64/rocket_left_big.png");
		if (game->character_left == NULL)//message derreur
			return(0);
		game->character_rigth = mlx_load_png("asset/textures/after/64/rocket_right_big.png");
		if (game->character_rigth == NULL)
			return(0);
		game->character_left_frame2 = mlx_load_png("asset/textures/after/64/rocket_left_litle.png");
		if (game->character_left_frame2 == NULL)//messge derreur
			return(0);
		game->character_right_frame2 = mlx_load_png("asset/textures/after/64/rocket_right_litle.png");
		if (game->character_right_frame2 == NULL)//messge derreur
			return(0);
		game->vide = mlx_load_png("asset/textures/after/64/big_back.png");
		if (game->vide == NULL)//message derreur
			return(0);
		game->wall = mlx_load_png("asset/textures/after/64/black_hole.png");
		if (game->wall == NULL)//message derreur
			return(0);
		game->item = mlx_load_png("asset/textures/poop.png");
		if (game->item == NULL)//message derreur
			return(0);
		game->exit_close = mlx_load_png("asset/textures/door.png");
		if (game->exit_close == NULL)//message derreur
			return(0);
		game->exit_open = mlx_load_png("asset/textures/door_open.png");
		if (game->exit_open == NULL)
			return (0);
		// game->count_mouve = mlx_load_png("");
		return(1);
}

void	texture_to_image(t_game *game, void *mlx)
{
	game->image_character_left = mlx_texture_to_image(mlx, game->character_left);
	game->image_character_left_frame2 = mlx_texture_to_image(mlx, game->character_left_frame2);
	game->image_character_right = mlx_texture_to_image(mlx, game->character_rigth);
	game->image_character_right_frame2 = mlx_texture_to_image(mlx, game->character_right_frame2);
	game->image_vide = mlx_texture_to_image(mlx, game->vide);
	game->image_wall = mlx_texture_to_image(mlx, game->wall);
	game->image_item = mlx_texture_to_image(mlx, game->item);
	game->image_exit_close = mlx_texture_to_image(mlx, game->exit_close);
	game->image_exit_open = mlx_texture_to_image(mlx, game->exit_open);
	mlx_delete_texture(game->vide);
	mlx_delete_texture(game->wall);
	mlx_delete_texture(game->item);
	mlx_delete_texture(game->exit_close);
	mlx_delete_texture(game->exit_open);
	mlx_delete_texture(game->character_left);
	mlx_delete_texture(game->character_left_frame2);
	mlx_delete_texture(game->character_rigth);
	mlx_delete_texture(game->character_right_frame2);
	
	
}

void	set_depth(t_game *game, char w, int x, int y)
{
	if (w == 'P')
	{
		mlx_image_to_window(game->mlx, game->image_character_right, x * TILE_SIZE, y * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->image_character_left, x * TILE_SIZE, y * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->image_character_right_frame2, x * TILE_SIZE, y * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->image_character_left_frame2, x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_character_right->instances[game->image_character_right->count - 1], CHARACTER);
		mlx_set_instance_depth(&game->image_character_left->instances[game->image_character_left->count - 1], CHARACTER);
		mlx_set_instance_depth(&game->image_character_right_frame2->instances[game->image_character_right_frame2->count - 1], CHARACTER);
		mlx_set_instance_depth(&game->image_character_left_frame2->instances[game->image_character_left_frame2->count - 1], CHARACTER);
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
		mlx_image_to_window(game->mlx, game->image_exit_close, x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_exit_close->instances[game->image_exit_close->count - 1], EXIT +10);
		mlx_image_to_window(game->mlx, game->image_exit_open, x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_exit_open->instances[game->image_exit_open->count - 1], EXIT -10);
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
