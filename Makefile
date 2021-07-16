LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

NAME = libftprintf.a

SRCS_PATH = srcs

SRCS = $(SRCS_PATH)/ft_printf.c \
		$(SRCS_PATH)/set_flags.c \
		$(SRCS_PATH)/print_char.c \
		$(SRCS_PATH)/print_string.c \
		$(SRCS_PATH)/print_integer.c \
		$(SRCS_PATH)/print_unsigned.c \
		$(SRCS_PATH)/print_pointer.c \
		$(SRCS_PATH)/utils.c \

OBJS_PATH = objs

TESTS_PATH = tests/

OBJS = $(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)/%.o, $(SRCS))

WHERE = .

CC = clang

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	mv $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS)  -I. -I/$(LIBFT_PATH) -c $< -o $@

bonus: all

test01: $(NAME)
	$(CC) $(TESTS_PATH)test.c $(NAME) && ./a.out

clean:
	@make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME) libft.a

re: fclean all
