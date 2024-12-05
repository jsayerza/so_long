/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/11/30 21:19:05 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprites(t_vars *vars)
{
	if (vars->sp_floor.img)
		mlx_destroy_image(vars->mlx, vars->sp_floor.img);
	if (vars->sp_player_r.img)
		mlx_destroy_image(vars->mlx, vars->sp_player_r.img);
	if (vars->sp_player_l.img)
		mlx_destroy_image(vars->mlx, vars->sp_player_l.img);
	if (vars->sp_wall.img)
		mlx_destroy_image(vars->mlx, vars->sp_wall.img);
	if (vars->sp_start.img)
		mlx_destroy_image(vars->mlx, vars->sp_start.img);
	if (vars->sp_exit.img)
		mlx_destroy_image(vars->mlx, vars->sp_exit.img);
	if (vars->sp_collect.img)
		mlx_destroy_image(vars->mlx, vars->sp_collect.img);
}

void	free_sprites_b(t_vars *vars)
{
	if (vars->sp_b_title.img)
		mlx_destroy_image(vars->mlx, vars->sp_b_title.img);
	if (vars->sp_b_collected.img)
		mlx_destroy_image(vars->mlx, vars->sp_b_collected.img);
	if (vars->sp_b_lost.img)
		mlx_destroy_image(vars->mlx, vars->sp_b_lost.img);
	if (vars->sp_b_won.img)
		mlx_destroy_image(vars->mlx, vars->sp_b_won.img);
	if (vars->sp_b_close.img)
		mlx_destroy_image(vars->mlx, vars->sp_b_close.img);
	if (vars->sp_b_black.img)
		mlx_destroy_image(vars->mlx, vars->sp_b_black.img);
}
