# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 10:02:35 by lkrabbe           #+#    #+#              #
#    Updated: 2022/08/27 18:16:58 by lkrabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

VPATH = src src/libft_plus

CC = cc -g

CFLAGS = -Werror -Wextra -Wall

SRC = 			convertmap.c \
				tmp_main.c \
				utiles.c

F_LIBFT_PLUS =	count_stuff.c 

MATRIX_LIB = libmatrix.a

LIBFT_LIB = libft.a

MLX_LIB = libmlx.dylib

F_MLX = mlx

F_MATRIX = src/matrix

F_LIBFT = libft/

MLX_FLAGS = $(MLX_LIB) -framework OpenGL -framework AppKit

LIB_FT_FLAGS = -Llib -lft

MATRIX_FLAGS = -Llib -lmatrix

OBJ = $(SRC:.c=.o) $(F_LIBFT_PLUS:.c=.o)

all: $(NAME)
	./$(NAME)
	
%.o: %.c lib
	$(CC) -c $(CFLAGS) $< -o $@ 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_FT_FLAGS) $(MATRIX_FLAGS) # $(MLX_FLAGS)

lib: $(MATRIX_LIB) $(MATRIX_LIB) $(LIBFT_LIB)

$(MLX_LIB):
	$(MAKE) all -C $(F_MLX)
	mv $(F_MLX)/$(MLX_LIB) .

$(MATRIX_LIB):
	$(MAKE) -C $(F_MATRIX)
	mv $(F_MATRIX)/$(MATRIX_LIB) ./lib

$(LIBFT_LIB):
	$(MAKE) -C $(F_LIBFT)
	mv $(F_LIBFT)/$(LIBFT_LIB) ./lib

clean:
	rm -f OBJ

fclean:
	$(MAKE) clean -C $(F_MLX)
	$(MAKE) clean -C $(F_MATRIX)
	$(MAKE) clean -C $(F_LIBFT)
	rm -f lib/* 

.PHONY: all re clean fclean lib