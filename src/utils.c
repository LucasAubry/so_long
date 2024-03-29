/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:06:33 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 17:32:11 by Laubry           ###   ########.fr       */
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
