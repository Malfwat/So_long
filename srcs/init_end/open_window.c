/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:29:37 by amouflet          #+#    #+#             */
/*   Updated: 2023/01/31 15:54:32 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <display.h>
#include <so_long.h>
#include <libft.h>

int	main(int ac, char **av)
{
	t_data	data[1];
	int		pos[2];

	if (ac != 2)
		return (2);
	ft_bzero(data, sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (close_n_free_win(data));
	if (get_map(av[1], data, data->xy) == -1)
		return (close_n_free_win(data));
	init_data(data);
	data->mlx->win_list = mlx_new_window(data->mlx, CASE_WIDTH * data->w_width, \
									  CASE_HEIGHT * data->w_height, "So_long");
	get_player_pos(data->tab, data->player->xy, 'P');
	get_to_print(data->tab, data);
	draw(data->to_print, data, data->xy);
	get_player_pos(data->to_print, pos, 'P');
	mlx_put_image_to_window(data->mlx, data->mlx->win_list, data->player->img, \
						 CASE_WIDTH * pos[0], CASE_HEIGHT * pos[1]);
	set_hook(data);
	mlx_loop(data->mlx);
}
