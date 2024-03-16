/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:06:33 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/16 19:48:08 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rand_int(int max)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("/dev/random", O_RDONLY);
	read(fd, &i, sizeof(int));
	if (i <= 0)
		i = -i;
	i = i % max;
	close(fd);
	return (i +1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}


// void	put_my_string(t_game *game, void *mlx)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while(game->map[i][j])
// 			j++;
// 		i++;
// 	}
// 	game->i = i;
// 	game->j = j;
// 	mlx_put_string(mlx, ft_itoa(game->mouve), j+1 * TILE_SIZE, i * TILE_SIZE);
// }