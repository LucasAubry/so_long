#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft_up.h"
# include "MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_game
{
	long			content;
	int				nbr_line;
	char			**map;
	struct s_game	*next;
}					t_game;

#endif
