CC =		cc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -g -O0

LIB = lib/libft.a
MLX = lib/libmlx42.a
LFLAGS = -Llib -lft -ldl -lglfw -pthread

FILES = main \
		map \
		data/data \
		data/data_2 \
		free \
		utils \
		verif/verif \
		verif/verif_2 \
		verif/verif_3 \
		set_texture/set_floor \
		set_texture/set_texture \
		set_texture/set_texture_2 \
		set_texture/set_depth \
		set_texture/load_texture \
		mouve/mouve \
		mouve/player \
		mouve/key \
		mouve/life_player \
		set_texture/item/item \
		set_texture/animation/animation \
		set_texture/animation/animation_2 \
		set_texture/bot/set_bot \
		end_game \
		set_texture/item/set_item \
		set_texture/item/set_item_2 \
		set_texture/item/load_texture_item \
		set_texture/item/texture_to_image_item \
		verif/if_finish

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix obj/, $(addsuffix .o, $(FILES)))

define generate_random_color
python3 -c "import random; \
print(''.join(['\033[38;5;' + str(random.randint(16, 255)) + 'm' + c + '\033[0m' for c in '$(1)']))"
endef

NAME = so_long

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIB) $(OBJS)
		@$(call generate_random_color, $(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(LIB) $(MLX))
		@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(LIB) $(MLX)

$(LIB):
	make -C lib/Libft
	cp lib/Libft/libft.a lib/
$(MLX):
	make -C MLX42/build

obj/%.o: src/%.c
	@$(call generate_random_color, $(CC) $(CFLAGS) -c $< -o $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

clean:
		rm -f $(OBJS) $(BONUSOBJS)

fclean:	clean
		rm -f $(NAME)
		rm -f lib/libft.a
		make fclean -C lib/Libft

re:	fclean all

.PHONY: all clean fclean re
