CC=cc
CFLAGS=-Wall -Wextra -Werror
BOLD    = \033[1m
BLACK   = \033[30;1m
RED     = \033[31;1m
GREEN   = \033[32;1m
YELLOW  = \033[33;1m
BLUE    = \033[34;1m
MAGENTA = \033[35;1m
CYAN    = \033[36;1m
WHITE   = \033[37;1m
RESET   = \033[0m
SRC_DIR=src/
OBJ_DIR=obj/
LIB_DIR=libft/
INC_DIR=includes/
MLX42=MLX42/
GLFW_DIR=/Users/$(USER)/.brew/opt/glfw/lib/
BREW_FILE = /Users/$(USER)/.brewconfig.zsh
LIBFT=$(LIB_DIR)libft.a
MLX=$(MLX42)libmlx42.a
GLFW=$(MLX_DIR)libglfw3.a
LIB_GLFW=-lglfw
INC_LIB=-I$(LIB_DIR)
INC_SRC=-I$(INC_DIR)
INC_MLX=-I$(MLX42)include/MLX42
SRC_NAME=convertmap.c \
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
				my_hextoi.c\
				to_many_fuction.c\
				matrix_getter.c \
				matrix_setter.c \
				matrix_utils.c \
				matrix_setup.c \
				matrix_solver.c\
				draw_order.c
OBJ_NAME=$(SRC_NAME:.c=.o)
OBJ=$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC=$(addprefix $(SRC_DIR),$(SRC_NAME))
NAME=fdf
all: $(NAME)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Compiling: $(RESET) $<"
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INC_LIB) $(INC_MLX)
$(NAME): $(MLX42) $(BREW_FILE) $(GLFW_DIR) $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(INC_GLFW) $(LIB_GLFW) -L $(GLFW_DIR) -L $(LIB_DIR) -lft -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	@echo "$(GREEN)Done$(RESET)"
$(LIBFT):
	make -C $(LIB_DIR)
$(MLX):
	make -C $(MLX42)
$(MLX42):
	@echo "$(MAGENTA) ----- CLONING MLX42 ----- $(RESET)"
	git clone https://github.com/codam-coding-college/MLX42.git
$(GLFW_DIR) :
	@echo "$(MAGENTA) ----- INSTALLING GLFW ----- $(RESET)"
	brew install glfw
$(BREW_FILE):
	@echo "$(MAGENTA) ----- INSTALLING BREW ----- $(RESET)"
	@curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	@source ~/.zshrc
clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIB_DIR)
	make fclean -C $(MLX42)
re: fclean all