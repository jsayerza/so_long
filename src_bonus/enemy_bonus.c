/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 18:54:08 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_pos_update(t_vars *vars, t_point p, t_point prevp)
{
	char	c;

	c = vars->map.tiles[p.y][p.x].t;
	if ((p.x > 0 && p.x < vars->map.width - 1
			&& p.y > 0 && p.y < vars->map.height - 1)
		&& c != WALL)
	{
		if (p.x == vars->player.pos.x && p.y == vars->player.pos.y)
		{
			vars->lost = true;
			vars->enemy.pos = p;
			mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->sp_b_lost.img, 775, vars->map.height * SIZE);
			ft_printf("Hunted by the cat :-(\n");
		}
		else
			vars->enemy.pos = p;
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sp_floor.img, prevp.x * SIZE, prevp.y * SIZE);
		return (1);
	}
	return (0);
}

static char	*enemy_pos_dir_chk_y(char *dir, int x_dir, int y_dir)
{
	if (y_dir < 0)
	{
		if (x_dir < 0)
			dir = "ULRD";
		else
			dir = "URLD";
	}
	else
	{
		if (x_dir < 0)
			dir = "DLRU";
		else
			dir = "DRLU";
	}
	return (dir);
}

static char	*enemy_pos_dir_chk_x(char *dir, int x_dir, int y_dir)
{
	if (x_dir < 0)
	{
		if (y_dir < 0)
			dir = "LUDR";
		else
			dir = "LDUR";
	}
	else
	{
		if (y_dir < 0)
			dir = "RUDL";
		else
			dir = "RDUL";
	}
	return (dir);
}

static char	*enemy_pos_dir(t_vars *vars, char *dir)
{
	int		x_dir;
	int		y_dir;

	x_dir = vars->player.pos.x - vars->enemy.pos.x;
	y_dir = vars->player.pos.y - vars->enemy.pos.y;
	if ((abs(x_dir) - abs(y_dir)) < 0)
		dir = enemy_pos_dir_chk_y(dir, x_dir, y_dir);
	else
		dir = enemy_pos_dir_chk_x(dir, x_dir, y_dir);
	return (dir);
}

void	enemy_pos_move(t_vars *vars)
{
	char	*dir;
	bool	moved;	

	dir = NULL;
	dir = enemy_pos_dir(vars, dir);
	moved = false;
	while (*dir && !moved)
	{
		if (*dir == 'U')
			moved = enemy_pos_update(vars, \
				(t_point){vars->enemy.pos.x, vars->enemy.pos.y - 1}, \
				vars->enemy.pos);
		else if (*dir == 'D')
			moved = enemy_pos_update(vars, \
				(t_point){vars->enemy.pos.x, vars->enemy.pos.y + 1}, \
				vars->enemy.pos);
		else if (*dir == 'L')
			moved = enemy_pos_update(vars, \
				(t_point){vars->enemy.pos.x - 1, vars->enemy.pos.y}, \
				vars->enemy.pos);
		else
			moved = enemy_pos_update(vars, (t_point){vars->enemy.pos.x + 1, \
				vars->enemy.pos.y}, vars->enemy.pos);
		dir++;
	}
}
