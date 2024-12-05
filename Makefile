NAME = so_long
NAME_LIB = libso_long.a
NAME_BONUS = so_long_bonus

SRCS =	src/so_long.c src/game_utils.c \
	src/map_parser.c src/map_utils.c src/map_checks.c src/line_utils.c \
	src/game_init.c \
	src/player.c src/wall_visible.c \
	src/sprites.c src/sprites_free.c \
	src/key_handler.c src/draw.c

SRCS_BONUS = src_bonus/so_long.c src_bonus/game_utils.c \
	src_bonus/map_parser.c src_bonus/map_utils.c src_bonus/map_checks.c src_bonus/line_utils.c \
	src_bonus/game_init.c \
	src_bonus/player.c src_bonus/wall_visible.c \
	src_bonus/sprites.c src_bonus/sprites_free.c \
	src_bonus/key_handler.c src_bonus/draw.c \
	src_bonus/draw_enemy_bonus.c src_bonus/enemy_bonus.c src_bonus/enemy_init_bonus.c \
	src_bonus/score_bonus.c \
	src_bonus/sprites_bonus.c src_bonus/sprites_free_bonus.c

SRC_GNL =	gnl/get_next_line.c gnl/get_next_line_utils.c
SRC_FTPF =	ftpf/ft_printf.c ftpf/ft_printf_utils.c

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz

CC = cc
CFLAGS = -Wall -Werror -Wextra -O3 -g -fsanitize=address
INCLUDES = -Isrc -Isrc_bonus -Iftpf -Ignl -Imlx
RM	= rm -f

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)
OBJ_GNL = $(SRC_GNL:.c=.o)
OBJ_FTPF = $(SRC_FTPF:.c=.o)

HEADERS =	src/so_long.h src/structures.h
HEADERS_BONUS = src_bonus/so_long.h src_bonus/structures.h
HEADERS_UTILS =	gnl/get_next_line.h ftpf/ft_printf.h

PARAMS = "./maps/map0.ber"

%.o: %.c Makefile $(HEADERS) $(HEADERS_BONUS) $(HEADERS_UTILS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(OBJ_GNL) $(OBJ_FTPF)
	@if [ ! -f "$(MLX_LIB)" ]; then \
		echo "Building MLX library..."; \
		make -C $(MLX_DIR); \
	else \
		echo "MLX library found."; \
	fi
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_GNL) $(OBJ_FTPF) $(INCLUDES) $(MLX_FLAGS)

$(NAME_BONUS): $(OBJ_BONUS) $(OBJ_GNL) $(OBJ_FTPF)
	@if [ ! -f "$(MLX_LIB)" ]; then \
		echo "Building MLX library..."; \
		make -C $(MLX_DIR); \
	else \
		echo "MLX library found."; \
	fi
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(OBJ_GNL) $(OBJ_FTPF) $(INCLUDES) $(MLX_FLAGS)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	make clean -C gnl
	make clean -C ftpf
	make clean -C mlx
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(NAME_LIB)

re: fclean all

lldb: $(NAME)
	lldb ./$(NAME) $(PARAMS)

lldbbonus: $(NAME_BONUS)
	lldb ./$(NAME_BONUS) $(PARAMS)

run:
	@if [ -f "$(NAME)" ]; then \
		clear; \
		./$(NAME) $(PARAMS); \
	else \
		echo "$(NAME) not found. Run 'make' first."; \
	fi

runbonus:
	@if [ -f "$(NAME_BONUS)" ]; then \
		clear; \
		./$(NAME_BONUS) $(PARAMS); \
	else \
		echo "$(NAME_BONUS) not found. Run 'make bonus' first."; \
	fi

# Phony targets
.PHONY: $(NAME) $(NAME_BONUS) all clean fclean re run lldb bonus runbonus lldbbonus

