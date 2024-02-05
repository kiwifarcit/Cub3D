# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 13:59:47 by ktaplin           #+#    #+#              #
#    Updated: 2023/10/17 14:35:34 by ktaplin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FILES = main \
		get_next_line \
		get_next_line_utils \
		parsing \
		cardinal \
		error \
		ft_atoi \
		ft_rgb_c \
		ft_rgb_f \
		map \
		check_map \
		check_map_borders \
		utils \
		map_utils \
		raycasting

MLX = MLX42/build/libmlx42.a -L "/Users/$$USER/.brew/opt/glfw/lib/" -lglfw -lm

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))

GFLAG = -Wall -Wextra -Werror -fsanitize=address -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(GFLAG) $(OBJ) -o $(NAME) $(MLX)

.c.o:
	gcc $(GFLAG) -c -o $@ $< -I include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

r: re
	./$(NAME) maps/map1.cub

re: fclean all