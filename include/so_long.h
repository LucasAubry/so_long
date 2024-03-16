/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:17:33 by Laubry            #+#    #+#             */
/*   Updated: 2024/03/16 19:46:53 by Laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define TILE_SIZE 64

//depth
# define CHARACTER 6
# define VIDE 1
# define WALL 2
# define ITEM 3
# define EXIT 4
# define BOT 5

typedef struct s_game
{
	mlx_texture_t		*texture_bot_1;
	mlx_texture_t		*texture_bot_2;
	mlx_texture_t		*texture_bot_3;
	mlx_texture_t		*texture_bot_4;
	mlx_texture_t		*texture_bot_5;
	mlx_texture_t		*texture_bot_6;
	mlx_texture_t		*vide;
	mlx_texture_t		*vide_player;
	mlx_texture_t		*wall;
	mlx_texture_t		*wall_frame2;
	mlx_texture_t		*wall_frame3;
	//item
	mlx_texture_t		*item_f1;
	mlx_texture_t		*item_f1_1;
	mlx_texture_t		*item_f1_2;
	mlx_texture_t		*item_f1_3;
	mlx_texture_t		*item_f2;
	mlx_texture_t		*item_f2_1;
	mlx_texture_t		*item_f2_2;
	mlx_texture_t		*item_f2_3;	
	mlx_texture_t		*item_f3;
	mlx_texture_t		*item_f3_1;
	mlx_texture_t		*item_f3_2;
	mlx_texture_t		*item_f3_3;	
	mlx_texture_t		*item_f4;
	mlx_texture_t		*item_f4_1;
	mlx_texture_t		*item_f4_2;
	mlx_texture_t		*item_f4_3;
	mlx_texture_t		*item_f5;
	mlx_texture_t		*item_f5_1;
	mlx_texture_t		*item_f5_2;
	mlx_texture_t		*item_f5_3;
	//fin item
	mlx_texture_t		*exit_close;
	mlx_texture_t		*exit_open;
	mlx_texture_t		*character_left;
	mlx_texture_t		*character_left_frame2;
	mlx_texture_t		*character_right_frame2;
	mlx_texture_t		*character_rigth;
	mlx_texture_t		*count_mouve;
	mlx_texture_t		*explosion;
	mlx_texture_t		*brock_character;
	mlx_texture_t		*brock_character_f1;

	mlx_image_t			*image_vide;
	mlx_image_t			*image_vide_player;
	mlx_image_t			*image_wall;
	mlx_image_t			*image_wall_frame2;
	mlx_image_t			*image_wall_frame3;
	//item
	mlx_image_t			*image_item_f1;
	mlx_image_t			*image_item_f1_1;
	mlx_image_t			*image_item_f1_2;
	mlx_image_t			*image_item_f1_3;
	mlx_image_t			*image_item_f2;
	mlx_image_t			*image_item_f2_1;
	mlx_image_t			*image_item_f2_2;
	mlx_image_t			*image_item_f2_3;
	mlx_image_t			*image_item_f3;
	mlx_image_t			*image_item_f3_1;
	mlx_image_t			*image_item_f3_2;
	mlx_image_t			*image_item_f3_3;
	mlx_image_t			*image_item_f4;
	mlx_image_t			*image_item_f4_1;
	mlx_image_t			*image_item_f4_2;
	mlx_image_t			*image_item_f4_3;
	mlx_image_t			*image_item_f5;
	mlx_image_t			*image_item_f5_1;
	mlx_image_t			*image_item_f5_2;
	mlx_image_t			*image_item_f5_3;
	//fin item
	mlx_image_t			*image_exit_close;
	mlx_image_t			*image_exit_open;
	mlx_image_t			*image_character_left;
	mlx_image_t			*image_character_left_frame2;
	mlx_image_t			*image_character_right;
	mlx_image_t			*image_character_right_frame2;
	mlx_image_t			*image_character;
	mlx_image_t			*image_count_mouve;
	mlx_image_t			*image_explosion;
	mlx_image_t			*image_brock_character;
	mlx_image_t			*image_brock_character_f1;
	//bot
	mlx_image_t			*image_bot_1;
	mlx_image_t			*image_bot_2;
	mlx_image_t			*image_bot_3;
	mlx_image_t			*image_bot_4;
	mlx_image_t			*image_bot_5;
	mlx_image_t			*image_bot_6;
	//str
	mlx_image_t			*string;
	//rocket
	int					place_character[3];
	int					size_y;
	int					size_x;
	int					mouve;
	int					how_item_collect;
	int					nbr_item;
	int					tick;
	int					life_of_player;
	int					place_exit[3];
	int					speed;
	int					c_vide;
	int					c_wall;
	int					c_item;
	int					c_exit;
	int					c_player;
	int					c_bot;
	char				*mouve_str;
	int					i;
	int					j;
	int					character_first_place[3];
	//bot	
	int					nbr_bot;

	mlx_t				*mlx;
	char				**map;
	struct s_game		*next;
}					t_game;

/**********************************/
/*********INISIALISATION***********/
/**********************************/

//data:
void	set_data(t_game *game);
void	set_size_y(t_game *game, char **argv);
void	set_size_x(t_game *game, char **argv);
int		where_is(t_game *game, char c, char z);
void	how_item(t_game *game);
void	init_data(t_game *game);
void	init_data_befor_map(t_game *game);
void	where_is_exit(t_game *game);
void	where_is_character(t_game *game);
//utils:
int	init_map(t_game *game, char **argv);
void	printf_map_terminal(t_game *game);
void	free_all(t_game *game, int x);
int		check_perror(int fd);
void	take_item(t_game *game);
int		nbr_random(int x, int y);
void	how_bot(t_game *game);
int		ft_rand_int(int max);
void	put_my_string(t_game *game, void *mlx);
int		ft_strcmp(char *s1, char *s2);
//verif:
int		verif_map(t_game *game);
int		character(t_game *game, int i, int j, int boule);
int		wall_up_down(t_game *game);
int		wall_left_right(t_game *game);
void	end_game(t_game *game);
void	lose_hp(t_game *game);
void	if_is_finish(t_game *game);
int		can_get_items(t_game *game);
void	can_i_finish(t_game *game, int i, int j);
int		verif_finish(t_game *game);
//texture:
void	set_floor(t_game *game);
void	anim_bot(t_game *game);
int		load_texture_floor(t_game *game);
int		load_texture_wall(t_game *game);
int		load_texture_exit(t_game *game);
int		set_texture(t_game *game, void *mlx);
void	animation(t_game *game, char c);
int		load_texture_character(t_game *game);
int		load_texture_explosion(t_game *game);
void	set_carpet(t_game *game, int x, int y, char c);
//item_texure
int		load_texture_item(t_game *game);
void	set_item(t_game *game, int x, int y);
void	texure_to_image_item(t_game *game, void *mlx);
//bot;
int		load_texture_bot(t_game *game);
void	set_depth_bot(t_game *game, int x, int y);
void	texture_to_image_bot(t_game *game, void *mlx);
//move:
void	set_key(void *param);
int		ft_up(t_game *game, int x, int y, char z);
int		ft_down(t_game *game, int x, int y, char z);
int		ft_left(t_game *game, int x, int y, char z);
int		ft_right(t_game *game, int x, int y, char z);
#endif
