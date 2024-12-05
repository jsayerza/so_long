/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/05 16:31:06 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putc(int c)
{
	if (write(1, &c, 1) == -1)
		perror("write error");
}

void	map_print(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_printf("%c", map->tiles[y][x].t);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	map_error(char *s, t_vars *vars, bool do_free)
{
	if (do_free)
		freer(vars);
	if (write(1, "Error\n", 6) == -1)
		perror("write error");
	perror(s);
	exit(1);
}

int	map_fill_init(t_vars *vars, t_point *p)
{
	vars->map.fd = open(vars->map.path, O_RDONLY);
	if (vars->map.fd < 0)
	{
		freer(vars);
		perror("Error: Couldn't open map file.\n");
		exit(1);
	}
	vars->map.tiles = malloc(vars->map.height * sizeof(t_tile *));
	if (!vars->map.tiles)
	{
		freer(vars);
		perror("Error: Couldn't allocate map.tiles.\n");
		exit(1);
	}
	p->x = 0;
	p->y = 0;
	return (1);
}

int	map_name_check(char *s)
{
	size_t	len;

	len = ft_strlen(s) - 1;
	if (s[len - 3] == '.' && \
		s[len - 2] == 'b' && s[len - 1] == 'e' && s[len] == 'r')
		return (1);
	return (0);
}
