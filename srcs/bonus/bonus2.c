/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malfwa <malfwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:59:17 by malfwa            #+#    #+#             */
/*   Updated: 2025/05/23 17:08:28 by malfwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <map.h>
#include <libft.h>
#include <mlx.h>

void	display_frame(char **map, t_data *data, int i, int j)
{
	static int	test;
	char		*str;

	test = test % 400000;
	if (map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list,
			data->floor->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	if (map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list,
			data->wall->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	if (map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list,
			data->collectible->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	if (map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list,
			data->out->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	if (map[i][j] == '2')
		mlx_put_image_to_window(data->mlx, data->mlx->win_list,
			data->move_buu[test++ / NB_FRAME]->img, CASE_WIDTH * j,
			CASE_HEIGHT * i);
	str = ft_itoa(data->count_move);
	if (str == NULL)
		close_n_free_win(data);
	mlx_string_put(data->mlx, data->mlx->win_list, 15, 20, 0x00FFFFFF, str);
	free(str);
}
