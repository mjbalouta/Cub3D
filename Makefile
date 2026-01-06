CC          	= cc
NAME        	= cub3d
INCLUDES_PATH	= includes
INCLUDES		= -I$(INCLUDES_PATH)
CFLAGS      	= -Wall -Wextra -Werror -I$(LIBFT_DIR) $(INCLUDES) -I$(MLX_DIR) -g
MLX_FLAGS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
SRCS			= $(addprefix srcs/, \
				main.c \
        		init/init_game.c\
				init/init_mlx.c\
				init/load_textures.c\
				parsing/validate_args.c \
				parsing/validate_file.c \
				parsing/parse_textures_info.c \
				parsing/parse_colors_info.c \
				parsing/utils.c \
				parsing/parse_map.c \
				clean/exit_functions.c \
				clean/free_mem.c \
				raycasting/start_ray.c\
)
OBJS       		= $(SRCS:.c=.o)
LIBFT_DIR   	= ./libft
MLX_DIR			= ./minilibx-linux
LIBFT       	= $(LIBFT_DIR)/complete_libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	
%.o: %.c cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo "Cub3D compiled."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

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