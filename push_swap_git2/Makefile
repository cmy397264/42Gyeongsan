NAME = push_swap
CC = gcc -Werror -Wextra -Wall
SRCS = ft_check1.c ft_check2.c ft_cmd1.c ft_cmd2.c ft_indexing.c ft_sort.c ft_sort_hc.c ft_sort_init.c ft_stack.c main.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(target)
	make fclean -C $(LIBFT_DIR)

re: fclean all

all: $(target)

