# Variables
NAME = libso_long.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -O3 -g #-fsanitize=address
#CFLAGS = -O3 -g #-fsanitize=address
INCLUDES = -Iincludes -Imlx
INCLUDES_DIR = ./includes

# Link X11 and MLX
MLX_FLAGS = -Lmlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz

# Paths
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

HEADER = $(INCLUDES_DIR)/so_long.h

SRCS =	src/so_long.c src/game_utils.c \
	src/map_parser.c src/map_utils.c src/map_checks.c src/line_utils.c \
	src/game_init.c \
	src/player.c src/wall_visible.c src/sprites.c src/sprites_free.c \
	src/key_handler.c src/draw.c \

BONUS_SRCS = src_bonus/so_long.c src_bonus/game_utils.c \
	src_bonus/map_parser.c src_bonus/map_utils.c src_bonus/map_checks.c src_bonus/line_utils.c \
	src_bonus/game_init.c \
	src_bonus/player.c src_bonus/wall_visible.c src_bonus/sprites.c src_bonus/sprites_free.c \
	src_bonus/key_handler.c src_bonus/draw.c \
	src_bonus/draw_enemy_bonus.c src_bonus/enemy_bonus.c src_bonus/enemy_init_bonus.c \
	src_bonus/score_bonus.c \
	src_bonus/sprites_bonus.c src_bonus/sprites_free_bonus.c \

GNL_SRC = gnl/get_next_line.c gnl/get_next_line_utils.c
FTPF_SRC = ftpf/ft_printf.c ftpf/ft_printf_utils.c

# Object files
OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)
FTPF_OBJ = $(FTPF_SRC:.c=.o)

EXE = so_long

PARAMS = "./maps/map0.ber"

# Regla por defecto: compila el archivo estático y el ejecutable
all: $(NAME) $(EXE) $(MLX_LIB)

# Regla para construir el archivo estático
$(NAME): $(OBJ) $(GNL_OBJ) $(FTPF_OBJ)
	@ar rcs $(NAME) $(OBJ) $(GNL_OBJ) $(FTPF_OBJ)

# Regla para construir el ejecutable
$(EXE): $(OBJ) $(GNL_OBJ) $(FTPF_OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(GNL_OBJ) $(FTPF_OBJ) $(INCLUDES) $(MLX_FLAGS) #-fsanitize=address

$(MLX_LIB):
	@make -C $(MLX_DIR)

# Regla para compilar con las funciones bonus e incluirlas en el archivo estático
bonus: $(OBJ) $(BONUS_OBJ) $(GNL_OBJ) $(FTPF_OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ) $(GNL_OBJ) $(FTPF_OBJ)

# Regla para limpiar archivos objeto y el archivo estático
clean:
	@rm -f $(OBJ) $(BONUS_OBJ) $(GNL_OBJ) $(FTPF_OBJ)
	
# Regla para limpiar todos los archivos generados por la compilación
fclean: clean
	@rm -f $(NAME) $(EXE)

re: fclean all

# Regla para compilar con información de depuración y ejecutar el programa
lldb: fclean $(EXE)
	lldb ./$(EXE) $(PARAMS)
	
# Regla para construir el archivo objeto
%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Separate rule for GNL files
gnl/%.o: gnl/%.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Regla para ejecutar el programa
run:
	@if [ -f "$(EXE)" ]; then \
		clear; \
		#echo "$(EXE) trobat!"; \
		./$(EXE) $(PARAMS); \
	else \
		echo "$(EXE) no trobat. Run 'make' abans"; \
	fi


# Phony targets
.PHONY: all clean fclean run lldb re bonus


#valgrind -s --leak-check=full ./so_long

