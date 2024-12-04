/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 18:32:07 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tiles(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->map.height)
	{
		free(vars->map.tiles[i]);
		vars->map.tiles[i] = NULL;
		i++;
	}
	free(vars->map.tiles);
	vars->map.tiles = NULL;
}

void	freer(t_vars *vars)
{
	free_tiles(vars);
}

int	win_close(t_vars *vars)
{
	free_sprites(vars);
	free_sprites_b(vars);
	free_sprites_bonus(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	freer(vars);
	exit(0);
	return (0);
}
