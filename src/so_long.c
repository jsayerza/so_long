/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/03 12:21:07 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_vars *vars)
{
	if (vars->frame_count > vars->display_frames)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sp_b_black.img, COUNTER_SIZE + 5, vars->map.height * SIZE);
		vars->frame_count = 0;
		if (vars->won)
			mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->sp_b_won.img, COUNTER_SIZE + 5, vars->map.height * SIZE);
		else if (vars->lost)
			mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->sp_b_lost.img, COUNTER_SIZE + 5, vars->map.height * SIZE);
	}
	draw_map(vars);
	draw_bars(vars);
	if (!vars->won && !vars->lost)
	{
		draw_player(vars);
	}
	vars->frame_count++;
	return (0);
}

static void	game(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		map_error("Failed to initialize MLX.", vars, true);
		return ;
	}
	vars->win = mlx_new_window(vars->mlx, \
		vars->map.width * SIZE, vars->map.height * SIZE + 80, WIN_NAME);
	if (!vars->win)
	{
		free(vars->mlx);
		map_error("Failed to create window.", vars, true);
		return ;
	}
	vars->img = mlx_new_image(vars->mlx, \
		vars->map.width * SIZE, vars->map.height * SIZE);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_x_pixel, \
		&vars->line_len, &vars->endian);
	sprites_load(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_handler, vars);
	mlx_hook(vars->win, 17, 1L << 0, win_close, vars);
	mlx_loop_hook(vars->mlx, render, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac <= 1)
		map_error("Couldn't open map. Too few params.", NULL, false);
	else if (ac > 2
	)
		map_error("Too many params.", NULL, false);
	else if (!map_name_check(av[1]))
		map_error("Bad file name.", NULL, false);
	game_init(&vars, av[1]);
	map_parse(&vars.map);
	map_fill(&vars);
	map_print(&vars.map);
	game(&vars);
	return (0);
}
