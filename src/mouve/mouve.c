/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:20:02 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/19 17:29:04 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_up(t_game *game, int x, int y, char z)
{
	char	*str;

	if (game->map[y -1][x] == z)
		return (0);
	else
	{
		if (game->map[y -1][x] == 'C')
			set_carpet(game, x, y, 'U');
		else if (game->map[y -1][x] == 'B')
		{
			lose_hp(game);
			return (0);
		}
		str = ft_itoa(game->mouve);
		if (game->string)
			mlx_delete_image(game->mlx, game->string);
		game->string = mlx_put_string(game->mlx, str, 10, 50);
		free(str);
		ft_printf("%d\n", game->mouve);
		return (1);
	}
}

int	ft_down(t_game *game, int x, int y, char z)
{
	char	*str;

	if (game->map[y +1][x] == z)
		return (0);
	else
	{
		if (game->map[y +1][x] == 'C')
			set_carpet(game, x, y, 'D');
		else if (game->map[y +1][x] == 'B')
		{
			lose_hp(game);
			return (0);
		}
		str = ft_itoa(game->mouve);
		if (game->string)
			mlx_delete_image(game->mlx, game->string);
		game->string = mlx_put_string(game->mlx, str, 10, 50);
		free(str);
		ft_printf("%d\n", game->mouve);
		return (1);
	}
}

int	ft_left(t_game *game, int x, int y, char z)
{
	char	*str;

	if (game->map[y][x -1] == z)
		return (0);
	else
	{
		if (game->map[y][x -1] == 'C')
			set_carpet(game, x, y, 'L');
		else if (game->map[y][x -1] == 'B')
		{
			lose_hp(game);
			return (0);
		}
		str = ft_itoa(game->mouve);
		if (game->string)
			mlx_delete_image(game->mlx, game->string);
		game->string = mlx_put_string(game->mlx, str, 10, 50);
		free(str);
		ft_printf("%d\n", game->mouve);
		return (1);
	}
}

int	ft_right(t_game *game, int x, int y, char z)
{
	char	*str;

	if (game->map[y][x +1] == z)
		return (0);
	else
	{
		if (game->map[y][x +1] == 'C')
			set_carpet(game, x, y, 'R');
		else if (game->map[y][x +1] == 'B')
		{
			lose_hp(game);
			return (0);
		}
		str = ft_itoa(game->mouve);
		if (game->string)
			mlx_delete_image(game->mlx, game->string);
		game->string = mlx_put_string(game->mlx, str, 10, 50);
		free(str);
		ft_printf("%d\n", game->mouve);
		return (1);
	}
}
