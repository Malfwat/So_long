/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:57:24 by amouflet          #+#    #+#             */
/*   Updated: 2025/05/23 17:05:06 by malfwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <display.h>
#include <libft.h>

int	check_malloc(t_data *data)
{
	if (!data->move[0]->img
		|| !data->move[1]->img
		|| !data->move[2]->img
		|| !data->move[3]->img
		|| !data->move[4]->img
		|| !data->move_buu[0]->img
		|| !data->move_buu[1]->img
		|| !data->move_buu[2]->img
		|| !data->move_buu[3]->img
		|| !data->move_buu[4]->img
		|| !data->move_buu[5]->img
		|| !data->move_buu[6]->img
		|| !data->move_buu[7]->img
		|| !data->floor->img
		|| !data->out->img
		|| !data->collectible->img
		|| !data->wall->img
		|| !data->player->img)
		return (close_n_free_win(data));
	return (0);
}

void	init_move(t_data *data)
{
	int	x;
	int	y;

	data->move[0]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/move/0.xpm", &x, &y);
	data->move[1]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/move/1.xpm", &x, &y);
	data->move[2]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/move/2.xpm", &x, &y);
	data->move[3]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/move/3.xpm", &x, &y);
	data->move[4]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/move/4.xpm", &x, &y);
}

void	init_move_buu(t_data *data)
{
	int	x;
	int	y;

	data->move_buu[0]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/buu_move/buu.xpm", &x, &y);
	data->move_buu[1]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/buu_move/0.xpm", &x, &y);
	data->move_buu[2]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/buu_move/1.xpm", &x, &y);
	data->move_buu[3]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/buu_move/2.xpm", &x, &y);
	data->move_buu[4]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/buu_move/3.xpm", &x, &y);
	data->move_buu[5]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/buu_move/4.xpm", &x, &y);
	data->move_buu[6]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/buu_move/5.xpm", &x, &y);
	data->move_buu[7]->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/buu_move/6.xpm", &x, &y);
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
	init_move_buu(data);
	data->floor->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/floor.xpm", &tmp, &tmp);
	data->out->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/exit.xpm", &tmp, &tmp);
	data->collectible->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/collectible.xpm", &tmp, &tmp);
	data->wall->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/wall.xpm", &tmp, &tmp);
	data->player->img = mlx_xpm_file_to_image
		(data->mlx, "dbz/stand.xpm", &tmp, &tmp);
	return (check_malloc(data));
}
