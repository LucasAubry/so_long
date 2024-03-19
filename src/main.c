/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:05 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/19 17:57:55 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "so_long.h"

void	ft_loop(t_game *game)
{
	mlx_loop_hook(game->mlx, &set_key, game);
	mlx_loop(game->mlx);
	free_all(game, 1);
}

int	init_setting(t_game *game, void *mlx)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	if (!mlx)
		return (1);
	game->mlx = mlx;
	return (0);
}

void	dtf(t_game *game)
{
	init_data(game);
	ft_loop(game);
	free(game);
}

int	gv(t_game *game, char **argv)
{
	init_data_befor_map(game);
	if (!game || !verif_ber(argv))
	{
		free(game);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		if (!gv(game, argv) || !init_map(game, argv, 1))
			return (1);
		if (!init_map(game, argv, 0) || !verif_map(game))
		{
			free_all(game, 0);
			free(game);
			return (1);
		}
		mlx = mlx_init(game->size_x * 64, game->size_y * 64, "so_long", true);
		if (init_setting(game, mlx))
			return (1);
		if (!set_texture(game, mlx))
		{
			free_all(game, 0);
			return (1);
		}
		dtf(game);
	}
	return (0);
}
