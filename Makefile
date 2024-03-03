CC =		cc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -g -O0

LIB = lib/libft.a
MLX = lib/libmlx42.a
LFLAGS = -Llib -lft -ldl -lglfw -pthread

FILES = main \
		map \
		data \
		free \
		utils \
		verif/verif \
		verif/verif_2 \
		set_texture/set_floor \
		set_texture/set_texture \
		mouve/mouve \
		mouve/player \
		mouve/life_player \
		item \
		set_texture/animation \
		set_texture/bot/set_bot \
		end_game

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix obj/, $(addsuffix .o, $(FILES)))

NAME = so_long

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIB) $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(LIB) $(MLX)

$(LIB):
	make -C lib/Libft
	cp lib/Libft/libft.a lib/
$(MLX):
	make -C MLX42/build

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

clean:
		rm -f $(OBJS) $(BONUSOBJS)

fclean:	clean
		rm -f $(NAME)
		rm -f lib/libft.a
		make fclean -C lib/Libft

re:	fclean all

.PHONY: all clean fclean re
