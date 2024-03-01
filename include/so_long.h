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

//depth
#define CHARACTER 5
#define VIDE 1
#define WALL 2
#define ITEM 3
#define EXIT 4


typedef struct s_game
{
	mlx_image_t		*image_vide;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_item;
	mlx_image_t		*image_exit;
	mlx_image_t		*image_character_left;
	mlx_image_t		*image_character_right;
	mlx_image_t		*image_character;

	mlx_texture_t		*vide;
	mlx_texture_t		*wall;
	mlx_texture_t		*item;
	mlx_texture_t		*exit;
	mlx_texture_t		*character_left;
	mlx_texture_t		*character_rigth;

	int				place_character[3];
	int				size_y;
	int				size_x;
	mlx_t			*mlx;
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
void	set_floor(t_game *game);
//move:
void	set_key(void *param);
#endif
