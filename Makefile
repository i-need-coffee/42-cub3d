# **************************************************************************** #
#                                 CUB3D                                        #
# **************************************************************************** #

NAME			= cub3d

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -Iinclude -Ilibft/include -I$(MLX_DIR)

SRC_DIR			= src
SRCS			= \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parsing/parse_map.c \
	$(SRC_DIR)/utils/cleanup.c \
	$(SRC_DIR)/utils/error.c \
	$(SRC_DIR)/init/window.c \
	$(SRC_DIR)/parsing/set_map_texture.c \
	$(SRC_DIR)/parsing/utils.c \
	$(SRC_DIR)/parsing/set_map_color.c

OBJ_DIR			= obj
OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_DIRS		= $(OBJ_DIR)

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

MLX_DIR			= minilibx-linux
MLX				= $(MLX_DIR)/libmlx.a
MLX_FLAGS		= -lXext -lX11 -lm -lbsd
MLX_CFLAGS		= -O3 -std=gnu17 -I/usr/include -I..

# **************************************************************************** #

all: $(NAME)

$(LIBFT):
	@echo "📚 Building Libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "🖼️  Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR) CFLAGS="$(MLX_CFLAGS)" --no-print-directory

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "🚀 Cub3D compiled successfully!"

$(OBJ_DIRS):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@echo "🧹 Object files removed."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "🗑️  Libraries and executables removed."

re: fclean all

.PHONY: all clean fclean re
