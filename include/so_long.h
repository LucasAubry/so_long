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
	int				size_y;
	int				size_x;
	char			**map;
	struct s_game	*next;
}					t_game;

/**********************************/
/*********INISIALISATION***********/
/**********************************/

int	init_map(t_game *game);
int	check_perror(int fd);
int	verif_map(t_game *game);
void	free_all(t_game *game);
//data:
void	set_data(t_game *game);
void	set_size_y(t_game *game);
void	set_size_x(t_game *game);
//utils:
void	printf_map_terminal(t_game *game);


#endif
