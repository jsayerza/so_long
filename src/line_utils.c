/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/01 10:41:25 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	line_len(char *s)
{
	size_t	len;

	len = 0;
	while (*s && *s > 32)
	{
		len++;
		s++;
	}
	return (len);
}

int	line_allocate(t_vars *vars, t_point pos)
{
	vars->map.tiles[pos.y] = malloc((vars->map.width) * sizeof(t_tile));
	if (!vars->map.tiles[pos.y])
	{
		freer(vars);
		perror("Error: Couldn't allocate lines in map.tiles.\n");
		exit(1);
		return (0);
	}
	vars->map.tiles[pos.y][0].v = 0;
	vars->map.tiles[pos.y][0].t = 0;
	return (1);
}

int	line_chars_type_check(char *line, char *validchars)
{
	int	i;

	while (*line && *line > 32)
	{
		i = 0;
		while (validchars[i] && validchars[i] != *line)
			i++;
		if (!validchars[i])
			return (0);
		line++;
	}
	return (1);
}
