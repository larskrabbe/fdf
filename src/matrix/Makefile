NAME = libmatrix.a

CFLAGS = -Werror -Wextra -Wall

CC = cc

SRC = 	matrix_getter.c \
		matrix_setter.c \
		matrix_utils.c \
		matrix_setup.c \
		matrix_solver.c

OBJ = $(SRC:.c=.o)

MAIN = 	matrix_main.c 


all: $(NAME)

$(NAME): $(OBJ)
	ar -rs $(NAME) $(OBJ)
	make clean

main : 
	$(CC) $(CFLAGS) $(SRC) -L../../lib -lft $(MAIN) -o a.matrix
	./a.matrix
clean:
	rm -f *.o

fclean:clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all re clean fclean 