# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 14:26:01 by mmughedd          #+#    #+#              #
#    Updated: 2024/01/18 10:36:09 by mmughedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

UTILS = utils.c hooks.c fract.c pxl.c

SRC_PATH = src/

UTILS_PATH = utils/

MLX_PATH = minilibx-linux/

MLX_NAME = libmlx_Linux.a

MLX	= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

SRCS = $(addprefix $(SRC_PATH), $(SRC)) $(addprefix $(UTILS_PATH), $(UTILS))

INCS = -I./includes/ -I/usr/include -Imlx #-I ./minilibx-linux/

OBJS = $(SRCS:.c=.o)

NAME = fractol

CC = cc

FLAGS = -g -pg#-Wextra -Werror -Wall

MLX_FLAGS = -Lminilibx-linux/ -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

all: $(NAME)

makemlx:
	make -sC $(MLX_PATH)

makelibft:
	make -sC $(LIBFT_PATH)

$(NAME): makemlx makelibft $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INCS) $(MLX_FLAGS)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re makemlx makelibft
