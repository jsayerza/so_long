/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 10:25:30 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_init_bonus(t_vars *vars)
{
	vars->display_frames = FPS * SECONDS;
	vars->enemy_frame_count = 0;
	vars->enemy_move = FPS * ENEMY_PACE;
	vars->enemy_unlocked = false;
	vars->moves = 0;
}

static void	game_init_mlx(t_vars *vars)
{
	vars->mlx = 0;
	vars->win = 0;
	vars->img = 0;
	vars->addr = 0;
	vars->bits_x_pixel = 0;
	vars->line_len = 0;
	vars->endian = 0;
	vars->frame_count = 0;
	game_init_bonus(vars);
}

void	game_init(t_vars *vars, char *map_path)
{
	vars->map.path = map_path;
	vars->map.fd = 1;
	vars->map.width = 0;
	vars->map.height = 0;
	vars->map.start = 0;
	vars->map.exit = 0;
	vars->map.exit_reachable = false;
	vars->map.collects = 0;
	vars->map.collects_reachables = 0;
	vars->map.wall_closed = false;
	vars->map.tiles = NULL;
	vars->collected = 0;
	vars->exit_unlocked = false;
	vars->won = false;
	vars->lost = false;
	vars->player.pos.x = 0;
	vars->player.pos.y = 0;
	vars->player.start_pos.x = 0;
	vars->player.start_pos.y = 0;
	vars->player.img = 0;
	game_init_mlx(vars);
	game_init_bonus(vars);
}
