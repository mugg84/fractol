# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 14:26:01 by mmughedd          #+#    #+#              #
#    Updated: 2024/01/08 13:29:59 by mmughedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

UTILS = utils.c

SRC_PATH = src/

UTILS_PATH = utils/

MLX_PATH = minilibx-linux/

MLX_NAME = libmlx_Linux.a

MLX	= $(MLX_PATH)$(MLX_NAME)

SRCS = $(addprefix $(SRC_PATH), $(SRC)) $(addprefix $(UTILS_PATH), $(UTILS))

INCS = -I./includes/ -I/usr/include -Imlx #-I ./minilibx-linux/

OBJS = $(SRCS:.c=.o)

NAME = fractol

CC = cc

#FLAGS = -Wextra -Werror -lm -L$(MLX_PATH) -lmlx -lXext -lX11
FLAGS = #-Wextra -Werror -Wall

MLX_FLAGS = -Lminilibx-linux/ -lmlx -L/usr/lib/X11 -lXext -lX11

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

all: $(NAME)

makemlx:
	make -sC $(MLX_PATH)

$(NAME): makemlx $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX) $(INCS) $(MLX_FLAGS)


clean:
	$(RM) $(OBJS)
	cd $(MLX_DIR) && make clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re makemlx makelibft