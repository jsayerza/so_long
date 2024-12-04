/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_visible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 19:47:42 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	wall_visib_update_y_down(t_vars *vars, t_point p)
{
	vars->map.tiles[p.y - 1][p.x].v = true;
	if ((int)p.x - 1 >= 0)
		vars->map.tiles[p.y - 1][p.x - 1].v = true;
	if (p.x + 1 < vars->map.width)
		vars->map.tiles[p.y - 1][p.x + 1].v = true;
}

static void	wall_visib_update_y_up(t_vars *vars, t_point p)
{
	vars->map.tiles[p.y + 1][p.x].v = true;
	if ((int)p.x - 1 >= 0)
		vars->map.tiles[p.y + 1][p.x - 1].v = true;
	if (p.x + 1 < vars->map.width)
		vars->map.tiles[p.y + 1][p.x + 1].v = true;
}

static void	wall_visib_update_x_down(t_vars *vars, t_point p)
{
	vars->map.tiles[p.y][p.x - 1].v = true;
	if ((int)p.y - 1 >= 0)
		vars->map.tiles[p.y - 1][p.x - 1].v = true;
	if (p.y + 1 < vars->map.height)
		vars->map.tiles[p.y + 1][p.x - 1].v = true;
}

static void	wall_visib_update_x_up(t_vars *vars, t_point p)
{
	vars->map.tiles[p.y][p.x + 1].v = true;
	if ((int)p.y - 1 >= 0)
		vars->map.tiles[p.y - 1][p.x + 1].v = true;
	if (p.y + 1 < vars->map.height)
		vars->map.tiles[p.y + 1][p.x + 1].v = true;
}

void	wall_visib_update(t_vars *vars, t_point p)
{
	if ((int)p.y - 1 >= 0)
		wall_visib_update_y_down(vars, p);
	if (p.y + 1 < vars->map.height)
		wall_visib_update_y_up(vars, p);
	if ((int)p.x - 1 >= 0)
		wall_visib_update_x_down(vars, p);
	if (p.x + 1 < vars->map.width)
		wall_visib_update_x_up(vars, p);
}
