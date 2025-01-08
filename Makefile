
FLAGS_DEBUG= -fsanitize=address -g3 -O1 -fno-omit-frame-pointer -fno-optimize-sibling-calls
CFLAGS=-Wall -Wextra -Werror
FILES= push_swap.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c \
      push_swap_utils4.c push_swap_radix.c push_swap_simple.c push_swap_utils5.c \
      push_swap_utils6.c push_swap_utils7.c \

LIBFT=./libft/libft.a
OBJS=$(FILES:.c=.o)
OBJS_BONUS=$(FILES_BONUS:.c=.o)
NAME=push_swap


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	gcc $(CFLAGS) -I includes -c $< -o $@

debug: $(OBJS) $(LIBFT)
	gcc $(CFLAGS) $(FLAGS_DEBUG) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

$(LIBFT):
	make -C ./libft

.PHONY: all debug fclean re
