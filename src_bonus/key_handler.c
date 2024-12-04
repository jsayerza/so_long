/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/11/30 21:19:05 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		win_close(vars);
	else if (vars->won || vars->lost)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sp_b_close.img, COUNTER_SIZE + 5, vars->map.height * SIZE);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		player_pos_update(vars, (t_point){vars->player.pos.x + 1, \
			vars->player.pos.y}, vars->player.pos);
		vars->player.img = vars->sp_player_r.img;
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		player_pos_update(vars, (t_point){vars->player.pos.x - 1, \
			vars->player.pos.y}, vars->player.pos);
		vars->player.img = vars->sp_player_l.img;
	}
	else if (keycode == KEY_UP || keycode == KEY_W)
		player_pos_update(vars, (t_point){vars->player.pos.x, \
			vars->player.pos.y - 1}, vars->player.pos);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		player_pos_update(vars, (t_point){vars->player.pos.x, \
			vars->player.pos.y + 1}, vars->player.pos);
	return (0);
}
