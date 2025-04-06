/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:11:27 by amouflet          #+#    #+#             */
/*   Updated: 2023/01/31 19:33:36 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <map.h>

static bool	check_lines_ext(char **tab, int y)
{
	int	x;

	x = 0;
	while (tab[y][x])
	{
		if (tab[y][x] != '1')
			return (false);
		x++;
	}
	x = 0;
	while (tab[0][x])
	{
		if (tab[0][x] != '1')
			return (false);
		x++;
	}
	return (true);
}

static bool	check_colomns_ext(char **tab, int x)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		if (tab[y][x] != '1')
			return (false);
		y++;
	}
	y = 0;
	while (tab[y])
	{
		if (tab[y][0] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	is_map_char(char c, char *char_set)
{
	int	i;

	i = 0;
	while (char_set[i])
		if (c == char_set[i++])
			return (true);
	return (false);
}

bool	is_good_format(char **tab, t_data *data)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (tab[height][width])
		width++;
	while (tab[height])
		height++;
	if (check_colomns_ext(tab, width - 1) == false)
		return (false);
	if (check_lines_ext(tab, height - 1) == false)
		return (false);
	if (is_good_content(tab, width, height, data) == false)
		return (false);
	get_player_pos(tab, data->exit, 'E');
	return (true);
}
