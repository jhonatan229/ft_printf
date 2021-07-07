NAME = libftprintf.a

LIB = libft.a

LIB_PATH = ./libft/

FILES = ft_printf.c set_flags.c print_char.c print_string.c print_integer.c print_unsigned.c print_pointer.c utils.c print_type_n.c

OBJ = ft_printf.o set_flags.o print_char.o print_string.o print_integer.o print_unsigned.o print_pointer.o utils.o print_type_n.o

CC = clang

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ) $(LIB_PATH)
	make -C $(LIB_PATH) $(LIB)
	cp $(LIB_PATH)$(LIB) .
	mv $(LIB) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

bonus:
	$(CC) testbonus.c $(NAME) && ./a.out

test01:
	$(CC) test02.c $(NAME) && ./a.out

test02:
	$(CC) test.c $(NAME) && ./a.out

clean:
	make clean -C $(LIB_PATH)
	rm $(OBJ)

fclean: clean
	rm $(NAME)