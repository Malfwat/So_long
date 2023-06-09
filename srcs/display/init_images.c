/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:57:24 by amouflet          #+#    #+#             */
/*   Updated: 2023/01/31 16:54:14 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <display.h>
#include <libft.h>

int	check_malloc(t_data *data)
{
	if (!data->move[0]->img \
	|| !data->move[1]->img \
	|| !data->move[2]->img \
	|| !data->move[3]->img \
	|| !data->move[4]->img \
	|| !data->floor->img \
	|| !data->out->img \
	|| !data->collectible->img \
	|| !data->wall->img \
	|| !data->player->img)
		return (close_n_free_win(data));
	return (0);
}

void	init_move(t_data *data)
{
	int	x;
	int	y;

	data->move[0]->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/move/0.xpm", &x, &y);
	data->move[1]->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/move/1.xpm", &x, &y);
	data->move[2]->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/move/2.xpm", &x, &y);
	data->move[3]->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/move/3.xpm", &x, &y);
	data->move[4]->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/move/4.xpm", &x, &y);
}

int	init_data(t_data *data)
{
	int	tmp;

	data->w_height = W_HEIGHT;
	data->w_width = W_WIDTH;
	if (data->xy[0] < data->w_width)
		data->w_width = data->xy[0];
	if (data->xy[1] < data->w_height)
		data->w_height = data->xy[1];
	data->to_print = ft_calloc(sizeof(char *), data->w_height + 1);
	if (!data->to_print)
		close_n_free_win(data);
	init_move(data);
	data->floor->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/floor.xpm", &tmp, &tmp);
	data->out->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/exit.xpm", &tmp, &tmp);
	data->collectible->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/collectible.xpm", &tmp, &tmp);
	data->wall->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/wall.xpm", &tmp, &tmp);
	data->player->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/stand.xpm", &tmp, &tmp);
	data->enemy->img = mlx_xpm_file_to_image \
	(data->mlx, "dbz/buu.xpm", &tmp, &tmp);
	return (check_malloc(data));
}
