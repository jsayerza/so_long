/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/03 11:28:40 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	generate_random_x(t_vars *vars, size_t seed, size_t pos_rand)
{
	while (1)
	{
		pos_rand = (pos_rand % (vars->map.width - 1)) + 1;
		if ((pos_rand > 0) && (pos_rand < vars->map.width - 1) && \
			(((pos_rand - seed <= RATIO) && (pos_rand >= seed)) || \
			((seed - pos_rand <= RATIO) && (pos_rand <= seed))))
			break ;
	}
	return (pos_rand);
}

static size_t	generate_random_y(t_vars *vars, size_t seed, size_t pos_rand)
{
	while (1)
	{
		pos_rand = (pos_rand % (vars->map.height - 1)) + 1;
		if ((pos_rand > 0) && (pos_rand < vars->map.height - 1) && \
			(((pos_rand - seed <= RATIO) && (pos_rand >= seed)) || \
			((seed - pos_rand <= RATIO) && (pos_rand <= seed))))
			break ;
	}
	return (pos_rand);
}

static size_t	generate_random(t_vars *vars, size_t seed, char xy)
{
	double	random;
	size_t	pos_rand;

	random = sin(seed) * 10000 + vars->frame_count;
	pos_rand = (size_t)fabs(random);
	if (xy == 'x')
		pos_rand = generate_random_x(vars, seed, pos_rand);
	else
		pos_rand = generate_random_y(vars, seed, pos_rand);
	return (pos_rand);
}

static void	enemy_pos_init_set(t_vars *vars, t_point p, size_t x, size_t y)
{
	if ((vars->map.tiles[y][x].t != WALL) && (p.x != x || p.y != y))
	{
		vars->enemy.pos.x = x;
		vars->enemy.pos.y = y;
	}
}

void	enemy_pos_init(t_vars *vars, t_point p)
{
	size_t	x;
	size_t	y;
	size_t	x_seed;
	size_t	y_seed;

	x = 0;
	y = 0;
	x_seed = p.x;
	y_seed = p.y;
	vars->enemy.pos.x = 0;
	vars->enemy.pos.y = 0;
	while (vars->enemy.pos.x == 0 || vars->enemy.pos.y == 0)
	{
		x = generate_random(vars, x_seed, 'x');
		y = generate_random(vars, y_seed, 'y');
		enemy_pos_init_set(vars, p, x, y);
		x_seed++;
		if (x_seed > vars->map.width)
			x_seed = 1;
		y_seed++;
		if (y_seed > vars->map.height)
			y_seed = 1;
	}
}
