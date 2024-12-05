/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/03 12:20:32 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_pos_update_collected(t_vars *vars, t_point p)
{
	vars->collected++;
	if (vars->collected > vars->map.collects / 2)
	{
		if (vars->collected == vars->map.collects)
			vars->exit_unlocked = true;
		vars->enemy_unlocked = true;
	}
	vars->map.tiles[p.y][p.x].t = FLOOR;
	vars->player.pos = p;
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->sp_b_collected.img, COUNTER_SIZE + 5, vars->map.height * SIZE);
	vars->frame_count = 0;
}

static void	player_pos_update_exit(t_vars *vars, t_point p)
{
	vars->won = true;
	ft_printf("Smart mouse, you won!\n");
	vars->map.tiles[p.y][p.x].t = FLOOR;
	vars->player.pos = p;
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->sp_b_won.img, COUNTER_SIZE + 5, vars->map.height * SIZE);
	vars->frame_count = 0;
}

int	player_pos_update(t_vars *vars, t_point p, t_point prevp)
{
	char	c;

	c = vars->map.tiles[p.y][p.x].t;
	if ((p.x > 0 && p.x < vars->map.width - 1 \
		&& p.y > 0 && p.y < vars->map.height - 1) && c != WALL)
	{
		vars->moves++;
		ft_printf("Moves: %d\n", vars->moves);
		if (c == COLLECT)
			player_pos_update_collected(vars, p);
		else if (c == EXIT && vars->exit_unlocked)
			player_pos_update_exit(vars, p);
		else
			vars->player.pos = p;
		if (vars->map.tiles[prevp.y][prevp.x].t != EXIT)
			vars->map.tiles[prevp.y][prevp.x].t = FLOOR;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sp_floor.img, prevp.x * SIZE, prevp.y * SIZE);
		wall_visib_update(vars, p);
		return (1);
	}
	return (0);
}
