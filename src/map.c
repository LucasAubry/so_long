/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:07 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/19 18:26:10 by Laubry           ###   ########.fr       */
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
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4) != 0)
	{
		printf("Le fichier n'a pas ete trouve ou c'est pas un .ber idiot\n");
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
			point++;
		i++;
	}
	if (point > 1)
	{
		ft_printf("le nom du fichier n'est pas correcte\n");
		return (0);
	}
	return (1);
}

int	perror_free(t_game *game, int fd)
{
	if (!check_perror(fd))
	{
		free(game);
		return (0);
	}
	return (1);
}

int	init_map(t_game *game, char **argv, int x)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (x == 1)
	{
		if (!perror_free(game, fd))
			return (0);
	}
	else
	{
		set_size_y(game, argv);
		game->map = malloc(sizeof(char *) * (game->size_y + 1));
		if (!check_perror(fd))
			return (0);
		if (!map_in_tab(game, argv))
		{
			close(fd);
			return (0);
		}
		set_size_x(game, argv);
		close(fd);
	}
	close(fd);
	return (1);
}
