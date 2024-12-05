/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 19:36:36 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_font
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	void	*black;
}	t_font;

typedef struct s_point
{
	size_t	x;
	size_t	y;
}	t_point;

typedef struct s_sprite
{
	int		w;
	int		h;
	void	*img;
}	t_sprite;

typedef struct s_player
{
	t_point		pos;
	t_point		start_pos;
	void		*img;
}	t_player;

typedef struct s_tile
{
	char	t;
	bool	v;
}	t_tile;

typedef struct s_map
{
	char	*path;
	int		fd;
	size_t	width;
	size_t	height;
	t_tile	**tiles;
	int		start;
	int		exit;
	bool	exit_reachable;
	int		collects;
	int		collects_reachables;
	bool	wall_closed;
}	t_map;

typedef struct s_vars
{
	t_player	player;
	t_player	enemy;
	t_map		map;
	t_sprite	sp_floor;
	t_sprite	sp_player_r;
	t_sprite	sp_player_l;
	t_sprite	sp_wall;
	t_sprite	sp_start;
	t_sprite	sp_exit;
	t_sprite	sp_collect;
	t_sprite	sp_b_title;
	t_sprite	sp_b_moves;
	t_sprite	sp_b_collected;
	t_sprite	sp_b_lost;
	t_sprite	sp_b_won;
	t_sprite	sp_b_close;
	t_sprite	sp_b_black;
	t_sprite	sp_enemy;
	t_font		sp_score_font;
	int			moves;
	int			collected;
	bool		exit_unlocked;
	bool		enemy_unlocked;
	bool		won;
	bool		lost;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_x_pixel;
	int			line_len;
	int			endian;
	int			frame_count;
	int			display_frames;
	int			enemy_frame_count;
	int			enemy_move;
}	t_vars;

#endif
