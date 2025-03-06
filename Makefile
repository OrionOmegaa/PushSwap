.SILENT:

FLAGS_DEBUG= -fsanitize=address -g3 -O1 -fno-omit-frame-pointer -fno-optimize-sibling-calls
CFLAGS=-Wall -Wextra -Werror
FILES= push_swap.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c \
      push_swap_utils4.c push_swap_radix.c push_swap_simple.c push_swap_utils5.c \
      push_swap_utils6.c push_swap_utils7.c \

LIBFT=./libft/libft.a
OBJS=$(FILES:.c=.o)
OBJS_BONUS=$(FILES_BONUS:.c=.o)
NAME=push_swap

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)
	@echo "$(GREEN)All Done Succesfully !$(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(YELLOW)Making Push_Swap ...$(RESET)"
	gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)Push_Swap Done Succesfully !$(RESET)"
%.o: %.c
	gcc $(CFLAGS) -I includes -c $< -o $@

debug: $(OBJS) $(LIBFT)
	gcc $(CFLAGS) $(FLAGS_DEBUG) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	@echo "$(YELLOW)Cleaning object file in progress ...$(RESET)"
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C ./libft
	@echo "$(GREEN)CLEAN Done Succesfully !$(RESET)"

fclean: clean
	@echo "$(YELLOW)Full Clean in progress ...$(RESET)"
	rm -f $(NAME)
	make fclean -C ./libft
	@echo "$(GREEN)FCLEAN Done Succesfully !$(RESET)"

re: fclean all
	@echo "$(GREEN)RE Done Succesfully !$(RESET)"

$(LIBFT):
	make -C ./libft

.PHONY: all debug fclean re
