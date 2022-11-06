# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 10:02:35 by lkrabbe           #+#    #+#              #
#    Updated: 2022/11/06 17:52:44 by lkrabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

CC = cc

CFLAGS = -Werror -Wextra -Wall

HEADER = $(INC_DIR)fdf.h

SRC = 			convertmap.c \
				tmp_main.c \
				utiles.c\
				draw_line.c\
				input_stuff.c\
				mlx_stuff.c\
				matrix_stuff.c\
				hooks.c\
				free_maps.c\
				count_stuff.c\
				is_white_space.c\
				my_abs.c\
				my_hextoi.c

MATRIX_LIB = libmatrix.a

LIBFT_LIB = libft.a

MLX_LIB = libmlx42.a

MLX_DIR = MLX42

INC_DIR=includes

SRC_DIR=src

OBJ_DIR = obj

MATRIX_DIR = src/matrix

LIBFT_DIR = libft

MAPS_DIR = test_maps

GLFW_DIR=/Users/$(USER)/.brew/opt/glfw/lib

BREW_FILE = /Users/$(USER)/.brewconfig.zsh

GLFW3_FLAGS = -lglfw3

MLX_FLAGS =  -L$(LIB_DIR) -lMLX42 -framework Cocoa -framework OpenGL -framework IOKit

LIBFT_FLAGS = -L$(LIB_DIR) -lft

MATRIX_FLAGS = -L$(LIB_DIR) -lmatrix

OBJ = $(addprefix obj/,$(notdir $(SRC:.c=.o)))

OBJ = $(SRC:.c=.o) $(src:.c=.o)

all: $(NAME)

obj/%.o: %.c | $(OBJ_DIR)
	@${CC} ${CFLAGS} -c $< -o $@ 

 $(OBJ_DIR):
	@mkdir  $(OBJ_DIR)

echo:
	echo test

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MATRIX_FLAGS) $(MLX_FLAGS) -o $(NAME)

lib: $(MATRIX_LIB) $(LIBFT_LIB) $(MLX_LIB)


$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(MLX_DIR):$(LIB_DIR)
	@echo " ----- CLONING MLX42 ----- "
	git clone https://github.com/codam-coding-college/MLX42.git

$(GLFW_DIR) : $(BREW_FILE)
	@echo " ----- INSTALLING GLFW ----- "
	brew install glfw

$(BREW_FILE):
	@echo " ----- INSTALLING BREW ----- "
	@curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	@source ~/.zshrc

$(MLX_LIB): $(MLX_DIR)
	$(MAKE) all -C $(MLX_DIR)
	mv $(MLX_DIR)$(MLX_LIB) ./lib

$(MATRIX_LIB):
	$(MAKE) -C $(MATRIX_DIR)
	mv $(MATRIX_DIR)$(MATRIX_LIB) ./lib

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT_LIB) ./lib

#if [ ! -d "MLX42" ]; then do stuff here ;fi

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIB_DIR)
	$(MAKE) fclean -C $(MLX42)

.PHONY: all re clean fclean lib

#________-----___-___--
# BOLD    = \033[1m
# BLACK   = \033[30;1m
# RED     = \033[31;1m
# GREEN   = \033[32;1m
# YELLOW  = \033[33;1m
# BLUE    = \033[34;1m
# MAGENTA = \033[35;1m
# CYAN    = \033[36;1m
# WHITE   = \033[37;1m
# RESET   = \033[0m

# LIBFT=$(LIB_DIR)libft.a
# MLX=$(MLX42)libmlx42.a
#GLFW=$(MLX_DIR)libglfw3.a
# INC_LIB=-I$(LIB_DIR)
# INC_SRC=-I$(INC_DIR)
# INC_MLX=-I$(MLX42)include/MLX42
# OBJ=$(addprefix $(OBJ_DIR),$(OBJ_NAME))
# SRC=$(addprefix $(SRC_DIR),$(SRC_NAME))
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
#     @mkdir -p $(OBJ_DIR)
#     @echo "$(BLUE)Compiling: $(RESET) $<"
#     @$(CC) $(CFLAGS) -o $@ -c $^ $(INC_LIB) $(INC_MLX)
# $(NAME): $(MLX42) $(BREW_FILE) $(GLFW_DIR) $(LIBFT) $(MLX) $(OBJ)
#     @$(CC) $(CFLAGS) $(OBJ) $(MLX) $(INC_GLFW) $(LIB_GLFW) -L $(GLFW_DIR) -L $(LIB_DIR) -lft -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
#     @echo "$(GREEN)Done$(RESET)"
# re: fclean all $(MLX)