/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/11/30 12:57:30 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemy(t_vars *vars)
{
	if (vars->enemy_frame_count > vars->enemy_move)
	{
		enemy_pos_move(vars);
		vars->enemy_frame_count = 0;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->sp_enemy.img, \
		vars->enemy.pos.x * SIZE, vars->enemy.pos.y * SIZE);
}
