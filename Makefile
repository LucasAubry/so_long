CC =		cc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -g -O0

LIB = include/libft_up.a
MLX = include/libmlx42.a
LFLAGS = -Llib -lft -ldl -lglfw -pthread

FILES = main \
		map \

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix obj/, $(addsuffix .o, $(FILES)))

NAME = so_long

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIB) $(MLX) $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(LIB) $(MLX)

$(LIB):
	make -C lib
$(MLX):
	make -C MLX42/build

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

clean:
		rm -f $(OBJS) $(BONUSOBJS)

fclean:	clean
		rm -f $(NAME)
		make fclean -C lib
		make clean -C MLX42/build

re:	fclean all

.PHONY: all clean fclean re
