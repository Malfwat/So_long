/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:55:34 by amouflet          #+#    #+#             */
/*   Updated: 2025/05/23 17:20:43 by malfwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <display.h>
#include <linux/input.h>
#include <libft.h>

void	get_to_print(char **tab, t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = (int []){0, data->player->xy[1] - data->w_height / 2}
	[data->player->xy[1] > data->w_height / 2];
	x = (int []){0, data->player->xy[0] - data->w_width / 2}
	[(data->player->xy[0] > data->w_width / 2)];
	if (x + data->w_width > data->xy[0])
		x = data->xy[0] - data->w_width;
	if (y + data->w_height > data->xy[1])
		y = data->xy[1] - data->w_height;
	while (i < data->w_height)
		data->to_print[i++] = &tab[y++][x];
}

void	draw(char **map, t_data *data, int *xy)
{
	int		i;
	int		j;

	i = 0;
	while (i < xy[1] && i < data->w_height && map[i])
	{
		j = 0;
		while (j < xy[0] && j < data->w_width && map[i][j])
			display_frame(map, data, i, j++);
		i++;
	}
}

int	print_game(t_data *data)
{
	int					test[2];

	get_to_print(data->tab, data);
	get_player_pos(data->to_print, test, 'P');
	draw(data->to_print, data, data->xy);
	mlx_put_image_to_window(data->mlx, data->mlx->win_list, data->player->img,
		CASE_WIDTH * (test[0]), CASE_HEIGHT * test[1]);
	return (0);
}
