CC          	= cc
NAME        	= cub3D
INCLUDES_PATH	= includes
INCLUDES		= -I$(INCLUDES_PATH)
MLX_DIR 		= ./minilibx-linux
MLX_LIB 		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
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
				parsing/utils2.c \
				parsing/create_map.c \
				parsing/parse_map.c \
				clean/exit_functions.c \
				clean/free_mem.c \
				clean/free_utils.c \
				raycasting/start_ray.c\
				raycasting/draw_walls.c\
				raycasting/calculate_texture.c\
				raycasting/start_algorithm.c\
				game/set_player.c\
				game/movements.c\
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

$(NAME): $(LIBFT) $(OBJS) $(MLX_LIB)
	@echo "Cub3D compiled."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "Removing objects..."
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing executable..."
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re