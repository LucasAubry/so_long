/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:07 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/16 19:47:27 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "so_long.h"

int	check_perror(int fd)
{
	if (fd == -1)
	{
		perror("Error_fd");
		return (0);
	}
	else
		return (1);
}

int	map_in_tab(t_game *game, char **argv)
{
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (!check_perror(fd))
		return (0);
	while (i < game->size_y)
	{
		temp = get_next_line(fd);
		game->map[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}

int	verif_ber(char **argv)
{
	char *dot;

	dot = ft_strrchr(argv[1], '.');
	if (!ft_strcmp(dot, ".ber"))
		return (1);
	return (0);
}

int	init_map(t_game *game, char **argv)
{
	int	fd;

	fd = 0;
	if (!verif_ber(argv))
	{
		printf("le fichier n'est pas en .ber idiot\n");
		return (0);
	}
	set_size_y(game, argv);
	game->map = malloc(sizeof(char *) * (game->size_y + 1));
	fd = open(argv[1], O_RDONLY);
	if (!check_perror(fd))
		return (0);
	if (!map_in_tab(game, argv))
	{
		close(fd);
		return (0);
	}
	set_size_x(game, argv);
	close(fd);
	return (1);
}
