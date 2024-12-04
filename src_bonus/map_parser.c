/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2024/12/02 18:47:54 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*grid_chars_count(t_vars *vars, char c, t_point pos)
{
	if (c == START)
	{
		vars->map.start++;
		if (vars->map.start > 1)
			return ("Map with more than one start.");
		vars->player.pos.x = pos.x;
		vars->player.pos.y = pos.y;
	}
	else if (c == EXIT)
	{
		vars->map.exit++;
		if (vars->map.exit > 1)
			return ("Map with more than one exit.");
	}
	else if (c == COLLECT)
		vars->map.collects++;
	return (0);
}

static char	*map_fill_check_lines(t_vars *vars, t_point	pos, char *error_msg)
{
	char	*line;

	line = get_next_line(vars->map.fd);
	while (line)
	{
		if (!line_allocate(vars, pos))
			error_msg = "Error allocating memory.";
		while (pos.x < vars->map.width)
		{
			vars->map.tiles[pos.y][pos.x].t = line[pos.x];
			vars->map.tiles[pos.y][pos.x].v = false;
			if (!error_msg)
				error_msg = grid_chars_count(vars, \
					vars->map.tiles[pos.y][pos.x].t, pos);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
		free(line);
		line = get_next_line(vars->map.fd);
	}
	close(vars->map.fd);
	return (error_msg);
}

int	map_fill(t_vars *vars)
{
	t_point	pos;
	char	*error_msg;

	map_fill_init(vars, &pos);
	error_msg = 0;
	error_msg = map_fill_check_lines(vars, pos, error_msg);
	if (error_msg)
		map_error(error_msg, vars, true);
	map_checks(vars);
	return (1);
}

static char	*map_parse_lines(t_map *map, char *error_msg)
{
	char	*line;
	int		fd;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Couldn't open map file.", NULL, false);
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		if (map->height == 1)
			map->width = line_len(line);
		if (line_len(line) != map->width)
			error_msg = "Map isn't rectangular.";
		if (!line_chars_type_check(line, VALIDCHARS))
			error_msg = "Invalid chars in map.";
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (error_msg);
}

int	map_parse(t_map *map)
{
	char	*error_msg;

	map->width = 0;
	map->height = 0;
	error_msg = 0;
	error_msg = map_parse_lines(map, error_msg);
	if (error_msg)
		map_error(error_msg, NULL, false);
	if (map->height == 0)
		map_error("Map is empty.", NULL, false);
	return (1);
}
