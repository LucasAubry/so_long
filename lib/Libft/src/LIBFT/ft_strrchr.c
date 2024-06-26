/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 01:45:27 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/18 13:38:30 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str != NULL)
		i++;
	while (i >= 0)
	{
		if (str[i] == (const char)c)
			return ((char *)(str + i));
		i--;
	}
	return ((char *)str);
}
