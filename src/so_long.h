/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 19:36:46 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "structures.h"
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ftpf/ft_printf.h"

# define FLOOR '0'
# define WALL '1'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'
# ifndef VALIDCHARS
#  define VALIDCHARS "01PEC"
# endif
# define WIN_W 1920
# define WIN_H 1080
# define WIN_NAME "BLIND MOUSE"
# define COUNTER_BAR_SIZE 400
# define COUNTER_SIZE 770
# ifndef SIZE
#  define SIZE 80
# endif
//# define ASSET_PATH "assets/"
# define FPS 60
# define SECONDS 5
# define ENEMY_PACE 1
# define RATIO 4
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

//map_parser.c
int		map_fill(t_vars *vars);
int		map_parse(t_map *map);

//line_utils.c
size_t	line_len(char *s);
int		line_allocate(t_vars *vars, t_point pos);
int		line_chars_type_check(char *line, char *validchars);

//map_checks.c
int		map_walls_check(t_vars *vars);
void	map_checks(t_vars *vars);

//map_utils.c
void	ft_putc(int c);
void	map_print(t_map *map);
void	map_error(char *s, t_vars *vars, bool do_free);
int		map_fill_init(t_vars *vars, t_point *p);
int		map_name_check(char *s);

//game_init.c
void	game_init(t_vars *vars, char *map_path);

//game_utils.c
void	free_tiles(t_vars *vars);
void	freer(t_vars *vars);
int		win_close(t_vars *vars);

//key_handler.c
int		key_handler(int keycode, t_vars *vars);

//sprites.c
void	sprites_load(t_vars *vars);

//sprites_free.c
void	free_sprites(t_vars *vars);
void	free_sprites_b(t_vars *vars);

//player.c
int		player_pos_update(t_vars *vars, t_point p, t_point prevp);

//wall_visible.c 
void	wall_visib_update(t_vars *vars, t_point p);

//draw.c
void	draw_map(t_vars *vars);
void	draw_bars(t_vars *vars);
void	draw_player(t_vars *vars);

//draw_bonus.c
void	draw_enemy(t_vars *vars);

//enemy_init_bonus.c
void	enemy_pos_init(t_vars *vars, t_point p);

//enemy_bonus.c
void	enemy_pos_move(t_vars *vars);

//sprites_bonus.c
void	sprites_load_bonus(t_vars *vars);

//score_bonus.c
//void	sprites_load_font_img(t_vars *vars);
void	score_update(t_vars *vars);

//sprites_free_bonus.c
void	free_sprites_bonus(t_vars *vars);
void	free_sprites_fonts(t_vars *vars);

#endif
