/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:03:14 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/05 19:47:02 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42.h"

int	load_texture(t_game *game)
{
	if (!load_texture_bot(game))
		return (0);
	if (!load_texture_item(game))
		return (0);
	if (!load_texture_character(game))
		return (0);
	if (!load_texture_floor(game))
		return (0);
	if (!load_texture_wall(game))
		return (0);
	if (!load_texture_exit(game))
		return (0);
	if (!load_texture_explosion(game))
		return (0);
	// game->count_mouve = mlx_load_png("");
	return (1);
}

void	texture_to_image_2(t_game *game, void *mlx)
{
	game->image_character_left = mlx_texture_to_image
		(mlx, game->character_left);
	game->image_character_left_frame2 = mlx_texture_to_image
		(mlx, game->character_left_frame2);
	game->image_character_right = mlx_texture_to_image
		(mlx, game->character_rigth);
	game->image_character_right_frame2 = mlx_texture_to_image
		(mlx, game->character_right_frame2);
	game->image_brock_character = mlx_texture_to_image
		(mlx, game->brock_character);
	game->image_brock_character_f1 = mlx_texture_to_image
		(mlx, game->brock_character_f1);
	game->image_vide = mlx_texture_to_image
		(mlx, game->vide);
	game->image_vide_player = mlx_texture_to_image
		(mlx, game->vide_player);
	game->image_exit_close = mlx_texture_to_image
		(mlx, game->exit_close);
	game->image_exit_open = mlx_texture_to_image
		(mlx, game->exit_open);
}

void	texture_to_image(t_game *game, void *mlx)
{
	texure_to_image_item(game, mlx);
	texture_to_image_bot(game, mlx);
	texture_to_image_2(game, mlx);
	game->image_wall = mlx_texture_to_image
		(mlx, game->wall);
	game->image_wall_frame2 = mlx_texture_to_image
		(mlx, game->wall_frame2);
	game->image_wall_frame3 = mlx_texture_to_image
		(mlx, game->wall_frame3);
	game->image_explosion = mlx_texture_to_image
		(mlx, game->explosion);
	mlx_delete_texture(game->vide);
	mlx_delete_texture(game->vide_player);
	mlx_delete_texture(game->wall);
	mlx_delete_texture(game->exit_close);
	mlx_delete_texture(game->exit_open);
	mlx_delete_texture(game->character_left);
	mlx_delete_texture(game->character_left_frame2);
	mlx_delete_texture(game->character_rigth);
	mlx_delete_texture(game->character_right_frame2);
	mlx_delete_texture(game->wall_frame2);
	mlx_delete_texture(game->wall_frame3);
	mlx_delete_texture(game->explosion);
	mlx_delete_texture(game->brock_character);
	mlx_delete_texture(game->brock_character_f1);
}

void	set_depth_2(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_character_right,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_character_left,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_character_right_frame2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_character_left_frame2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_explosion,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_brock_character,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_brock_character_f1,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_vide,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_vide_player,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	set_depth_3(t_game *game)
{
	mlx_set_instance_depth(&game->image_character_right->instances
	[game->image_character_right->count - 1], CHARACTER);
	mlx_set_instance_depth(&game->image_character_left->instances
	[game->image_character_left->count - 1], CHARACTER);
	mlx_set_instance_depth(&game->image_character_right_frame2->instances
	[game->image_character_right_frame2->count - 1], CHARACTER);
	mlx_set_instance_depth(&game->image_character_left_frame2->instances
	[game->image_character_left_frame2->count - 1], CHARACTER);
	mlx_set_instance_depth(&game->image_explosion->instances
	[game->image_explosion->count - 1], VIDE -1);
	mlx_set_instance_depth(&game->image_brock_character->instances
	[game->image_brock_character->count -1], VIDE -1);
	mlx_set_instance_depth(&game->image_brock_character_f1->instances
	[game->image_brock_character_f1->count -1], VIDE -1);
	mlx_set_instance_depth(&game->image_vide->instances
	[game->image_vide->count -1], VIDE -10);
	mlx_set_instance_depth(&game->image_vide_player->instances[0],
		VIDE -10);
}

void	set_depth_4(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image_wall,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_wall_frame2,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->image_wall_frame3,
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_set_instance_depth(&game->image_wall->instances
	[game->image_wall->count - 1], WALL);
	mlx_set_instance_depth(&game->image_wall->instances
	[game->image_wall_frame2->count - 1], WALL -2);
	mlx_set_instance_depth(&game->image_wall->instances
	[game->image_wall_frame3->count - 1], WALL -2);
}

void	set_depth(t_game *game, char w, int x, int y)
{
	if (w == 'P')
	{
		set_depth_2(game, x, y);
		set_depth_3(game);
	}
	else if (w == '1')
		set_depth_4(game, x, y);
	else if (w == 'C')
		set_item(game, x, y);
	else if (w == 'E')
	{
		mlx_image_to_window(game->mlx, game->image_exit_close,
			x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_exit_close->instances
		[game->image_exit_close->count - 1], EXIT +10);
		mlx_image_to_window(game->mlx, game->image_exit_open,
			x * TILE_SIZE, y * TILE_SIZE);
		mlx_set_instance_depth(&game->image_exit_open->instances
		[game->image_exit_open->count - 1], EXIT -10);
	}
	else if (w == 'B')
		set_depth_bot(game, x, y);
	else if (w == '0')
		return ;
}

char	what_texture(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
		return ('P');
	else if (game->map[y][x] == '1')
		return ('1');
	else if (game->map[y][x] == 'C')
		return('C');
	else if (game->map[y][x] == 'E')
		return ('E');
	else if (game->map[y][x] == '0')
		return ('0');
	else if (game->map[y][x] == 'B')
		return ('B');
	return ('0');
}

void	image_to_windows(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
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
		return (0);
	else
	{
		texture_to_image(game, mlx);
		set_floor(game);
		image_to_windows(game);
	}
	return (1);
}
