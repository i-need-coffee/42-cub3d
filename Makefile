
NAME			= cub3d

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -Iinclude -Ilibft/include -Iminilibx

SRC_DIR			= src
SRCS			= \
	$(SRC_DIR)/main.c \

OBJ_DIR			= obj
OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

MLX_DIR			= minilibx-linux
MLX				= $(MLX_DIR)/libmlx.a
MLX_FLAGS		= -lXext -lX11 -lm -lbsd

# **************************************************************************** #

all: $(NAME)

$(LIBFT):
	@echo "📚 Building Libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "🖼️  Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "🚀 Cub3D compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re