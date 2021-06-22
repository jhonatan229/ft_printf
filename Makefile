NAME = ft_printf.a

LIB = libft.a

LIB_PATH = ./libft/

FILES = ft_printf.c

OBJ = ft_printf.o

CC = clang

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIB_PATH)
	make -C $(LIB_PATH) $(LIB)
	cp $(LIB_PATH)$(LIB) .
	mv $(LIB) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

test:
	$(CC) $(CFLAGS) test.c $(FILES) $(LIB_PATH)ft_putchar_fd.c  $(LIB_PATH)ft_putstr_fd.c $(LIB_PATH)ft_putnbr_fd.c && ./a.out

test02:
	$(CC) $(CFLAGS) test.c -o test && ./test

clean:
	rm $(OBJ) a.out

fclean: clean
	rm $(NAME)