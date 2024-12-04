/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_free_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 10:25:55 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprites_fonts(t_vars *vars)
{
	if (vars->sp_score_font.zero)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.zero);
	if (vars->sp_score_font.one)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.one);
	if (vars->sp_score_font.two)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.two);
	if (vars->sp_score_font.three)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.three);
	if (vars->sp_score_font.four)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.four);
	if (vars->sp_score_font.five)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.five);
	if (vars->sp_score_font.six)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.six);
	if (vars->sp_score_font.seven)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.seven);
	if (vars->sp_score_font.eight)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.eight);
	if (vars->sp_score_font.nine)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.nine);
	if (vars->sp_score_font.black)
		mlx_destroy_image(vars->mlx, vars->sp_score_font.black);
}

void	free_sprites_bonus(t_vars *vars)
{
	if (vars->sp_b_moves.img)
		mlx_destroy_image(vars->mlx, vars->sp_b_moves.img);
	if (vars->sp_enemy.img)
		mlx_destroy_image(vars->mlx, vars->sp_enemy.img);
	free_sprites_fonts(vars);
}
