/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:35:57 by amouflet          #+#    #+#             */
/*   Updated: 2023/01/31 19:39:49 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <get_next_line.h>
#include <map.h>

void	free_map_in_lst(t_map *map, char *str)
{
	t_map	*tmp;

	while (map)
	{
		tmp = map;
		map = map->next;
		free(tmp->line);
		free(tmp);
	}
	if (str)
		free(str);
}

static t_map	*new_line(char *str)
{
	t_map	*line;

	line = malloc(sizeof(*line));
	if (!line)
		return (NULL);
	line->len = ft_strlen(str);
	if (str[line->len - 1] == '\n')
	{
		str[line->len - 1] = 0;
		line->len--;
	}
	line->line = str;
	line->final_line = NULL;
	line->next = NULL;
	return (line);
}

static int	add_line_in_map(t_map **map, char *line)
{
	t_map	*new;

	new = new_line(line);
	if (new == NULL)
		return (free_map_in_lst(*map, line), 1);
	if ((*map))
	{
		(*map)->final_line->next = new;
		(*map)->final_line = (*map)->final_line->next;
		if ((*map)->len != new->len)
			return (free_map_in_lst(*map, NULL), \
			ft_putendl_fd("The map isn't rectangle!", 2), 1);
	}
	else
	{
		new->final_line = new;
		*map = new;
	}
	return (0);
}

void	finish_file(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}

t_map	*get_map_list(const char *map_path)
{
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (perror(map_path), NULL);
	line = get_next_line(fd);
	map = NULL;
	while (line)
	{
		if (add_line_in_map(&map, line))
			return (finish_file(fd), NULL);
		line = get_next_line(fd);
	}
	return (map);
}
