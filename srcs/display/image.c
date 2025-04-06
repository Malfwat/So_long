/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:55:34 by amouflet          #+#    #+#             */
/*   Updated: 2023/01/31 16:53:10 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <display.h>
#include <libft.h>

void	get_to_print(char **tab, t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = (int []){0, data->player->xy[1] - data->w_height / 2} \
	[data->player->xy[1] > data->w_height / 2];
	x = (int []){0, data->player->xy[0] - data->w_width / 2} \
	[(data->player->xy[0] > data->w_width / 2)];
	if (x + data->w_width > data->xy[0])
		x = data->xy[0] - data->w_width;
	if (y + data->w_height > data->xy[1])
		y = data->xy[1] - data->w_height;
	while (i < data->w_height)
		data->to_print[i++] = &tab[y++][x];
}

void	display_frame(char **map, t_data *data, int i, int j)
{
	static int	test;

	test = test % 35000;
	if (map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list, \
		data->floor->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	if (map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list, \
		data->wall->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	if (map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list, \
		data->collectible->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	if (map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list, \
		data->out->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	if (map[i][j] == '2')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list, \
		data->move_buu[test / 5000]->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	test++;
}

void	draw(char **map, t_data *data, int *xy)
{
	int	i;
	int	j;

	i = -1;
	while (++i < xy[1] && i < data->w_height && map[i])
	{
		j = -1;
		while (++j < xy[0] && j < data->w_width && map[i][j])
			display_frame(map, data, i, j);
	}
}

int	print_game(t_data *data)
{
	int	test[2];

	get_to_print(data->tab, data);
	get_player_pos(data->to_print, test, 'P');
	draw(data->to_print, data, data->xy);
	mlx_put_image_to_window(data->mlx, data->mlx->win_list, data->player->img, \
	CASE_WIDTH * (test[0]), CASE_HEIGHT * test[1]);
	return (0);
}
