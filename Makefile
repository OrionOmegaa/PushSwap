.SILENT:

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
INCDIR = includes

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

SRC = $/push_swap.c $/push_swap_utils1.c $/push_swap_utils2.c $/push_swap_utils3.c \
      $/push_swap_utils4.c $/push_swap_radix.c $/push_swap_simple.c $/push_swap_utils5.c\
      $/push_swap_utils6.c $/ft_atoi.c $/ft_split.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "$(GREEN)All Done Succesfully !$(RESET)"

$(NAME): $(OBJ)
	@echo "$(YELLOW)Making Push_Swap ...$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Push_Swap Done Succesfully !$(RESET)"

%.o: %.c $(INCDIR)/ft.h
	@$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object file in progress ...$(RESET)"
	@rm -f $(OBJ) $(BOBJ)
	@echo "$(GREEN)CLEAN Done Succesfully !$(RESET)"

fclean: clean
	@echo "$(YELLOW)Full Clean in progress ...$(RESET)"
	@rm -f $(NAME) $(BOBJ)
	@echo "$(GREEN)FCLEAN Done Succesfully !$(RESET)"

re: fclean all
	@echo "$(GREEN)RE Done Succesfully !$(RESET)"

.PHONY: all clean fclean re
