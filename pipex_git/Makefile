NAME = pipex
CC = cc -Werror -Wextra -Wall -g
SRCS = ft_fork.c ft_cmd_path.c ft_path.c ft_setting_info.c ft_pipe.c ft_pipex_split.c ft_free.c main.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = bonus/ft_cmd_path_bonus.c bonus/ft_path_bonus.c bonus/ft_pipe_bonus.c\
		bonus/ft_setting_info_bonus.c bonus/ft_fork_bonus.c bonus/main_bonus.c\
		bonus/ft_pipex_split_bonus.c bonus/ft_free_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $^ -o $@
	touch $(NAME)

%.o: %.c
	$(CC) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

bonus : $(OBJS_BONUS) $(LIBFT)
	$(CC) $^ -o $(NAME)
	touch $(NAME)

re: fclean all

all: $(NAME)

