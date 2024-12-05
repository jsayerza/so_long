/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/11/30 12:18:20 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sprites_load_img(t_vars *vars)
{
	vars->sp_floor.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/floor.xpm", &vars->sp_floor.w, &vars->sp_floor.h);
	vars->sp_player_r.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/player_r.xpm", &vars->sp_player_r.w, &vars->sp_player_r.h);
	vars->sp_player_l.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/player_l.xpm", &vars->sp_player_l.w, &vars->sp_player_l.h);
	vars->sp_wall.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/wall.xpm", &vars->sp_wall.w, &vars->sp_wall.h);
	vars->sp_start.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/start.xpm", &vars->sp_start.w, &vars->sp_start.h);
	vars->sp_exit.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/exit.xpm", &vars->sp_exit.w, &vars->sp_exit.h);
	vars->sp_collect.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/collect.xpm", &vars->sp_collect.w, &vars->sp_collect.h);
}

static void	sprites_load_bar_img(t_vars *vars)
{
	vars->sp_b_title.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/b_title.xpm", &vars->sp_b_title.w, &vars->sp_b_title.h);
	vars->sp_b_collected.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/b_collected.xpm", &vars->sp_b_collected.w, \
		&vars->sp_b_collected.h);
	vars->sp_b_lost.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/b_lost.xpm", &vars->sp_b_lost.w, &vars->sp_b_lost.h);
	vars->sp_b_won.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/b_won.xpm", &vars->sp_b_won.w, &vars->sp_b_won.h);
	vars->sp_b_close.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/b_close.xpm", &vars->sp_b_close.w, &vars->sp_b_close.h);
	vars->sp_b_black.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/b_black.xpm", &vars->sp_b_black.w, &vars->sp_b_black.h);
}

void	sprites_load(t_vars *vars)
{
	sprites_load_img(vars);
	sprites_load_bar_img(vars);
}
