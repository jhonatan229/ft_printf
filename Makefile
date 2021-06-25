NAME = ft_printf.a

LIB = libft.a

LIB_PATH = ./libft/

FILES = ft_printf.c set_flags.c print_char.c print_string.c print_integer.c

OBJ = ft_printf.o set_flags.o print_char.o print_string.o print_integer.o

CC = clang

CFLAGS = -Wall -Wextra -Werror -fsanitize=leak

all: $(NAME)

$(NAME): $(OBJ) $(LIB_PATH)
	make -C $(LIB_PATH) $(LIB)
	cp $(LIB_PATH)$(LIB) .
	mv $(LIB) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

test:
	$(CC) $(CFLAGS) test.c $(FILES) $(LIB_PATH)*.c && ./a.out

test02:
	$(CC) $(CFLAGS) test.c $(NAME) && ./a.out

clean:
	rm $(OBJ) a.out

fclean: clean
	rm $(NAME)