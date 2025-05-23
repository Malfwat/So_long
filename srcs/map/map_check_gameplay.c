/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_gameplay.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admoufle <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:04:35 by admoufle          #+#    #+#             */
/*   Updated: 2025/05/23 17:21:05 by malfwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <map.h>
#include <stdio.h>
#include <libft.h>

static void	error_dup(char **new, int height)
{
	int	i;

	i = 0;
	while (new && i < height)
		free(new[i]);
	if (new)
		free(new);
}

static char	**dup_tab(char **map)
{
	int		height;
	char	**new;

	height = 0;
	while (map[height])
		height++;
	new = malloc(sizeof(char *) * (height + 1));
	if (!new)
		return (NULL);
	new[height] = NULL;
	height = 0;
	while (map[height])
	{
		new[height] = ft_strdup(map[height]);
		if (!new[height])
			return (error_dup(new, height), NULL);
		height += 1;
	}
	return (new);
}

static void	flood_fill(char **dup_map, short x, short y)
{
	dup_map[y][x] = '1';
	if (dup_map[y][x + 1] != '1' && dup_map[y][x + 1] != '\0')
		flood_fill(dup_map, x + 1, y);
	if (x - 1 >= 0 && dup_map[y][x - 1] != '1')
		flood_fill(dup_map, x - 1, y);
	if (dup_map[y + 1] && dup_map[y + 1][x] != '1')
		flood_fill(dup_map, x, y + 1);
	if (y - 1 >= 0 && dup_map[y - 1][x] != '1')
		flood_fill(dup_map, x, y - 1);
}

void	get_player_pos(char **map, int *pos, char c)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				break ;
			x += 1;
		}
		if (map[y][x] == c)
			break ;
		y += 1;
	}
	pos[0] = x;
	pos[1] = y;
}

bool	check_gameplay(char **map)
{
	char	**map_dup;
	int		pos[2];
	int		i;
	int		j;
	bool	exit_value;

	map_dup = dup_tab(map);
	get_player_pos(map, (int *)pos, 'P');
	flood_fill(map_dup, pos[0], pos[1]);
	i = 0;
	exit_value = true;
	while (map_dup[i])
	{
		j = 0;
		while (map_dup[i][j] && exit_value)
		{
			if (map_dup[i][j] != '1' && map_dup[i][j] != '0')
				exit_value = false;
			j++;
		}
		free(map_dup[i]);
		i++;
	}
	free(map_dup);
	return (exit_value);
}
