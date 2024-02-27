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

# define TILE_SIZE 32


typedef struct s_game
{
	mlx_image_t		*image_vide;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_item;
	mlx_image_t		*image_exit;
	mlx_image_t		*image_character;

	mlx_texture_t		*vide;
	mlx_texture_t		*wall;
	mlx_texture_t		*item;
	mlx_texture_t		*exit;
	mlx_texture_t		*character;
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
void	free_all(t_game *game);
//data:
void	set_data(t_game *game);
void	set_size_y(t_game *game);
void	set_size_x(t_game *game);
//utils:
void	printf_map_terminal(t_game *game);
//verif:
int	verif_map(t_game *game);
int	character(t_game *game, int i, int j, int boule);
int wall_up_down(t_game *game);
int wall_left_right(t_game *game);
//texture:
int	set_texture(t_game *game, void *mlx);

#endif
