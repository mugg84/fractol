# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmughedd <mmughedd@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 09:21:09 by mmughedd              #+#    #+#              #
#    Updated: 2024/01/27 09:56:13 by mmughedd             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

SRC_PATH = src/

UTILS = utils.c hooks.c fract.c

UTILS_PATH = utils/

MLX_PATH = minilibx-linux/

MLX_NAME = libmlx_Linux.a

MLX = $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

SRCS = $(addprefix $(SRC_PATH), $(SRC)) $(addprefix $(UTILS_PATH), $(UTILS))

INCS = -I./include -I/usr/include -Imlx

OBJS = $(SRCS:.c=.o)

NAME = fractol

CC = cc

FLAGS = -g -Wextra -Werror -Wall

MLX_FLAGS = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

RM = rm -fr

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

all: $(NAME)

makelibft:
	make -sC $(LIBFT_PATH)

makemlx:
	make -sC $(MLX_PATH)

$(NAME): makelibft makemlx $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INCS) $(MLX_FLAGS)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

bonus: all

.PHONY: all clean fclean re makelibft makemlx bonus