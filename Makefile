# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 10:02:35 by lkrabbe           #+#    #+#              #
#    Updated: 2022/09/07 06:01:34 by lkrabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

VPATH = src src/libft_plus

CC = cc -g

CFLAGS = #-Werror -Wextra -Wall

SRC = 			convertmap.c \
				tmp_main.c \
				utiles.c\
				draw_line.c\
				input_stuff.c

F_LIBFT_PLUS =	count_stuff.c \
				is_white_space.c

MATRIX_LIB = libmatrix.a

LIBFT_LIB = libft.a

MLX_LIB = libmlx42.a

F_MLX = MLX42

F_MATRIX = src/matrix

F_LIBFT = libft/

F_MAPS = test_maps/

MLX_FLAGS = -lglfw3 -Llib -lMLX42 -framework Cocoa -framework OpenGL -framework IOKit

LIBFT_FLAGS = -Llib -lft

MATRIX_FLAGS = -Llib -lmatrix

OBJ = $(SRC:.c=.o) $(F_LIBFT_PLUS:.c=.o)

all: $(NAME)

42: $(NAME)
	./$(NAME) $(F_MAPS)42.fdf

julia: $(NAME)
	./$(NAME) $(F_MAPS)julia.fdf

pent: $(NAME)
	./$(NAME) $(F_MAPS)pentenegpos.fdf

plat: $(NAME)
	./$(NAME) $(F_MAPS)plat.fdf

%.o: %.c lib
	$(CC) -c $(CFLAGS) $< -o $@ 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MATRIX_FLAGS) $(MLX_FLAGS) -o $(NAME)

lib: #$(MATRIX_LIB) $(LIBFT_LIB) $(MLX_LIB)

$(MLX_LIB):
	$(MAKE) all -C $(F_MLX)
	mv $(F_MLX)/$(MLX_LIB) ./lib

$(MATRIX_LIB):
	$(MAKE) -C $(F_MATRIX)
	mv $(F_MATRIX)/$(MATRIX_LIB) ./lib

$(LIBFT_LIB):
	$(MAKE) -C $(F_LIBFT)
	mv $(F_LIBFT)/$(LIBFT_LIB) ./lib

#if [ ! -d "MLX42" ]; then do stuff here ;fi

clean:
	rm -f OBJ


fclean:
	$(MAKE) clean -C $(F_MLX)
	$(MAKE) clean -C $(F_MATRIX)
	$(MAKE) clean -C $(F_LIBFT)
	rm -f lib/* 

.PHONY: all re clean fclean lib