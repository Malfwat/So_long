/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:40:45 by amouflet          #+#    #+#             */
/*   Updated: 2025/05/23 16:57:48 by malfwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx_int.h>
#include <mlx.h>
#include <hook.h>
#include <libft.h>
#include <stdio.h>

void	set_hook(t_data *data)
{
	mlx_hook(data->mlx->win_list, X_CROSS, 0, close_n_free_win, data);
	mlx_loop_hook(data->mlx, print_game, data);
	mlx_key_hook(data->mlx->win_list, manage_hook, data);
}

int	manage_hook(int keycode, t_data *data)
{
	if (keycode == 81100864)
		keycode = ESC;
	if (keycode == ESC)
		close_n_free_win(data);
	if (keycode == 'd' || keycode == RIGHT)
		move_player(data, (int []){1, 0});
	if (keycode == 'a' || keycode == LEFT)
		move_player(data, (int []){-1, 0});
	if (keycode == 'w' || keycode == UP)
		move_player(data, (int []){0, -1});
	if (keycode == 's' || keycode == DOWN)
		move_player(data, (int []){0, 1});
	if (data->c == 0 && data->player->xy[0] == data->exit[0]
		&& data->player->xy[1] == data->exit[1])
	{
		ft_putendl_fd("You Win!", 1);
		close_n_free_win(data);
	}
	return (0);
}
