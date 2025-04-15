/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:32:13 by amouflet          #+#    #+#             */
/*   Updated: 2023/01/31 15:56:21 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <mlx_int.h>
#include <so_long.h>
#include <stdlib.h>
#include <libft.h>

void	destroy_buu(t_data *data)
{
	if (data->move_buu[0]->img)
		mlx_destroy_image(data->mlx, data->move_buu[0]->img);
	if (data->move_buu[1]->img)
		mlx_destroy_image(data->mlx, data->move_buu[1]->img);
	if (data->move_buu[2]->img)
		mlx_destroy_image(data->mlx, data->move_buu[2]->img);
	if (data->move_buu[3]->img)
		mlx_destroy_image(data->mlx, data->move_buu[3]->img);
	if (data->move_buu[4]->img)
		mlx_destroy_image(data->mlx, data->move_buu[4]->img);
	if (data->move_buu[5]->img)
		mlx_destroy_image(data->mlx, data->move_buu[5]->img);
	if (data->move_buu[6]->img)
		mlx_destroy_image(data->mlx, data->move_buu[6]->img);
	if (data->move_buu[7]->img)
		mlx_destroy_image(data->mlx, data->move_buu[7]->img);
}

void	destroy_all_images(t_data *data)
{
	destroy_buu(data);
	if (data->move[0]->img)
		mlx_destroy_image(data->mlx, data->move[0]->img);
	if (data->move[1]->img)
		mlx_destroy_image(data->mlx, data->move[1]->img);
	if (data->move[2]->img)
		mlx_destroy_image(data->mlx, data->move[2]->img);
	if (data->move[3]->img)
		mlx_destroy_image(data->mlx, data->move[3]->img);
	if (data->move[4]->img)
		mlx_destroy_image(data->mlx, data->move[4]->img);
	if (data->out->img)
		mlx_destroy_image(data->mlx, data->out->img);
	if (data->wall->img)
		mlx_destroy_image(data->mlx, data->wall->img);
	if (data->collectible->img)
		mlx_destroy_image(data->mlx, data->collectible->img);
	if (data->floor->img)
		mlx_destroy_image(data->mlx, data->floor->img);
	if (data->player->img)
		mlx_destroy_image(data->mlx, data->player->img);
}

int	close_n_free_win(t_data *data)
{
	if (data->mlx->win_list)
		mlx_destroy_window(data->mlx, data->mlx->win_list);
	destroy_all_images(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->tab)
		free_tab(data->tab);
	if (data->to_print)
		free(data->to_print);
	exit (0);
	return (0);
}
