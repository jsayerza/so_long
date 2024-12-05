/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 18:45:17 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_bars(t_vars *vars)
{
	if (vars->map.width * SIZE >= COUNTER_BAR_SIZE)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sp_b_title.img, \
			0, vars->map.height * SIZE);
	if (vars->map.width * SIZE >= COUNTER_SIZE)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sp_b_moves.img, \
			COUNTER_BAR_SIZE + 20, vars->map.height * SIZE);
}

void	draw_player(t_vars *vars)
{
	if (!vars->player.img)
		vars->player.img = vars->sp_player_r.img;
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->player.img, \
		vars->player.pos.x * SIZE, vars->player.pos.y * SIZE);
}

static void	draw_map_c(t_vars *vars, t_point ini)
{
	char	c;
	bool	v;

	c = vars->map.tiles[ini.y][ini.x].t;
	v = vars->map.tiles[ini.y][ini.x].v;
	if (c == WALL && v)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sp_wall.img, ini.x * SIZE, ini.y * SIZE);
	else if (c == EXIT && vars->exit_unlocked)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sp_exit.img, ini.x * SIZE, ini.y * SIZE);
	else if (c == COLLECT)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sp_collect.img, ini.x * SIZE, ini.y * SIZE);
	else if (ini.x != vars->player.pos.x && ini.y != vars->player.pos.y)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sp_floor.img, ini.x * SIZE, ini.y * SIZE);
}

void	draw_map(t_vars *vars)
{
	t_point	ini;
	t_point	fin;

	ini.x = 0;
	ini.y = 0;
	fin.x = vars->map.width;
	fin.y = vars->map.height;
	while (ini.y < fin.y)
	{
		while (ini.x < fin.x)
		{
			draw_map_c(vars, ini);
			ini.x++;
		}
		ini.x = 0;
		ini.y++;
	}
}
