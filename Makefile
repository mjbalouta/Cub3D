CC          	= cc
NAME        	= cub3d
INCLUDES_PATH	= includes
INCLUDES		= -I$(INCLUDES_PATH)
CFLAGS      	= -Wall -Wextra -Werror -I$(LIBFT_DIR) $(INCLUDES) -g
SRCS			= $(addprefix srcs/, \
				main.c \
)
OBJS       		= $(SRCS:.c=.o)
LIBFT_DIR   	= ./libft
LIBFT       	= $(LIBFT_DIR)/complete_libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	
%.o: %.c cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo "Cub3D compiled."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@echo "Removing objects..."
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing executable..."
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re