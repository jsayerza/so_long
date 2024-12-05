/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/11/30 12:21:12 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sprites_load_font_img(t_vars *vars)
{
	int	size;

	vars->sp_score_font.zero = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/0.xpm", &size, &size);
	vars->sp_score_font.one = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/1.xpm", &size, &size);
	vars->sp_score_font.two = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/2.xpm", &size, &size);
	vars->sp_score_font.three = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/3.xpm", &size, &size);
	vars->sp_score_font.four = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/4.xpm", &size, &size);
	vars->sp_score_font.five = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/5.xpm", &size, &size);
	vars->sp_score_font.six = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/6.xpm", &size, &size);
	vars->sp_score_font.seven = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/7.xpm", &size, &size);
	vars->sp_score_font.eight = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/8.xpm", &size, &size);
	vars->sp_score_font.nine = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/9.xpm", &size, &size);
	vars->sp_score_font.black = mlx_xpm_file_to_image(vars->mlx, \
		"assets/fonts/black.xpm", &size, &size);
}

static void	sprites_load_img_bonus(t_vars *vars)
{
	vars->sp_b_moves.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/b_moves.xpm", &vars->sp_b_moves.w, &vars->sp_b_moves.h);
	vars->sp_enemy.img = mlx_xpm_file_to_image(vars->mlx, \
		"assets/enemy.xpm", &vars->sp_enemy.w, &vars->sp_enemy.h);
}

void	sprites_load_bonus(t_vars *vars)
{
	sprites_load_img_bonus(vars);
	sprites_load_font_img(vars);
}
