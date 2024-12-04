/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/02 18:47:45 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_walls_check_x(t_vars *vars, size_t x, size_t y)
{
	while (x < vars->map.width)
	{
		if ((x == 0) || (x == vars->map.width - 1))
		{
			y = 0;
			while (y < vars->map.height)
			{
				if (vars->map.tiles[y][x].t != WALL)
					return (0);
				y++;
			}
		}
		x++;
	}
	return (1);
}

int	map_walls_check(t_vars *vars)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < vars->map.height)
	{
		if ((y == 0) || (y == vars->map.height - 1))
		{
			x = 0;
			while (x < vars->map.width)
			{
				if (vars->map.tiles[y][x].t != WALL)
					return (0);
				x++;
			}
		}
		y++;
	}
	x = 0;
	if (!map_walls_check_x(vars, x, y))
		return (0);
	return (1);
}

void	map_paths_check(t_point p, t_vars *vars)
{
	size_t	w;
	size_t	h;
	char	c;
	bool	v;

	w = vars->map.width;
	h = vars->map.height;
	c = vars->map.tiles[p.y][p.x].t;
	v = vars->map.tiles[p.y][p.x].v;
	if (c == WALL || v == 1 || p.y < 1 || p.y > h || p.x < 1 || p.x > w)
		return ;
	vars->map.tiles[p.y][p.x].v = true;
	if (c == EXIT)
		vars->map.exit_reachable = true;
	if (c == COLLECT)
		vars->map.collects_reachables++;
	map_paths_check((t_point){p.x, p.y - 1}, vars);
	map_paths_check((t_point){p.x + 1, p.y}, vars);
	map_paths_check((t_point){p.x, p.y + 1}, vars);
	map_paths_check((t_point){p.x - 1, p.y}, vars);
	return ;
}

void	map_chars_check(t_vars *vars)
{
	if (!vars->map.exit_reachable)
		map_error("Exit unrechable in map.", vars, true);
	if (vars->map.collects == 0)
		map_error("There are no collectibles in map.", vars, true);
	if (vars->map.collects_reachables != vars->map.collects)
		map_error("Unreachable collectibles on the map.", vars, true);
}

void	map_checks(t_vars *vars)
{
	if (vars->map.start != 1)
		map_error("Incorrect number of start points in map.", vars, true);
	if (vars->map.exit != 1)
		map_error("Incorrect number of exits in map.", vars, true);
	if (!map_walls_check(vars))
		map_error("Map isn't inclosed in walls.", vars, true);
	map_paths_check((t_point)vars->player.pos, vars);
	map_chars_check(vars);
}
