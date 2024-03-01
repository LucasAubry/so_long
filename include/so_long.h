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
#define CHARACTER 6
#define VIDE 1
#define WALL 2
#define ITEM 3
#define EXIT 4


typedef struct s_game
{
	mlx_image_t		*image_vide;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_item;
	mlx_image_t		*image_exit_close;
	mlx_image_t		*image_exit_open;
	mlx_image_t		*image_character_left;
	mlx_image_t		*image_character_right;
	mlx_image_t		*image_character;
	mlx_image_t		*image_count_mouve;

	mlx_texture_t		*vide;
	mlx_texture_t		*wall;
	mlx_texture_t		*item;
	mlx_texture_t		*exit_close;
	mlx_texture_t		*exit_open;
	mlx_texture_t		*character_left;
	mlx_texture_t		*character_rigth;
	mlx_texture_t		*count_mouve;

	int				place_character[3];
	int				size_y;
	int				size_x;
	int				mouve;
	int				how_item_collect;
	int				nbr_item;
	mlx_t			*mlx;
	char			**map;
	struct s_game	*next;
}					t_game;

/**********************************/
/*********INISIALISATION***********/
/**********************************/

//data:
void	set_data(t_game *game);
void	set_size_y(t_game *game);
void	set_size_x(t_game *game);
int	where_is(t_game *game, char c, char z);
void	how_item(t_game *game);
//utils:
int	init_map(t_game *game);
void	printf_map_terminal(t_game *game);
void	free_all(t_game *game);
int	check_perror(int fd);
void	take_item(t_game *game);
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
int	ft_up(t_game *game, int x, int y, char z);
int	ft_down(t_game *game, int x, int y, char z);
int	ft_left(t_game *game, int x, int y, char z);
int	ft_right(t_game *game, int x, int y, char z);
#endif
