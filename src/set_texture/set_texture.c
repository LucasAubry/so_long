/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:03:14 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:39:47 by Laubry           ###   ########.fr       */
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

char	what_texture(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
		return ('P');
	else if (game->map[y][x] == '1')
		return ('1');
	else if (game->map[y][x] == 'C')
		return ('C');
	else if (game->map[y][x] == 'E')
		return ('E');
	else if (game->map[y][x] == '0')
		return ('0');
	else if (game->map[y][x] == 'B')
		return ('B');
	return ('0');
}
