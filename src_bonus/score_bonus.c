/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 18:48:38 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	score_put(t_vars *vars, int digit, int i)
{
	void	*font;

	font = NULL;
	if (digit == 0)
		font = vars->sp_score_font.zero;
	if (digit == 1)
		font = vars->sp_score_font.one;
	if (digit == 2)
		font = vars->sp_score_font.two;
	if (digit == 3)
		font = vars->sp_score_font.three;
	if (digit == 4)
		font = vars->sp_score_font.four;
	if (digit == 5)
		font = vars->sp_score_font.five;
	if (digit == 6)
		font = vars->sp_score_font.six;
	if (digit == 7)
		font = vars->sp_score_font.seven;
	if (digit == 8)
		font = vars->sp_score_font.eight;
	if (digit == 9)
		font = vars->sp_score_font.nine;
	mlx_put_image_to_window(vars->mlx, vars->win, font, \
		730 - 40 * i, vars->map.height * SIZE);
}

void	score_update(t_vars *vars)
{
	int	i;
	int	score;
	int	digit;

	i = 0;
	score = vars->moves;
	while (i < 3)
	{
		digit = score % 10;
		score /= 10;
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sp_score_font.black, \
			730 - 40 * i, vars->map.height * SIZE);
		score_put(vars, digit, i);
		i++;
	}
}
