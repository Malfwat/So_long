/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:15:04 by amouflet          #+#    #+#             */
/*   Updated: 2023/01/31 16:54:36 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <map.h>
#include <libft.h>
#include <mlx.h>

void	move_player(t_data *data, int *dir)
{
	char	*str;

	if (!data->tab[data->player->xy[1] + dir[1]] \
	|| data->tab[data->player->xy[1] + dir[1]] \
	[data->player->xy[0] + dir[0]] == '1')
		return ;
	data->count_move += 1;
	str = ft_itoa(data->count_move);
	if (str == NULL)
		close_n_free_win(data);
	ft_putstr_fd("Number of move: ", 1);
	ft_putendl_fd(str, 1);
	free(str);
	data->tab[data->player->xy[1]][data->player->xy[0]] = (char []){'0', 'E'} \
	[data->player->xy[0] == data->exit[0] \
	&& data->player->xy[1] == data->exit[1]];
	if (data->tab[data->player->xy[1] + dir[1]] \
	[data->player->xy[0] + dir[0]] == 'C')
		data->c -= 1;
	data->tab[data->player->xy[1] + dir[1]][data->player->xy[0] + dir[0]] = 'P';
	data->player->xy[1] += dir[1];
	data->player->xy[0] += dir[0];
	print_game(data);
}

bool	is_good_content(char **tab, int width, int height, t_data *data)
{
	static int	char_in_tab[3];

	while (--height >= 0)
	{
		width = -1;
		while (tab[height][++width])
		{	
			if (is_map_char(tab[height][width], CHAR_SET_M) == false)
				return (false);
			if (tab[height][width] == 'P')
				char_in_tab[P] += 1;
			if (tab[height][width] == 'E')
				char_in_tab[E] += 1;
			if (tab[height][width] == 'C')
			{
				char_in_tab[C] += 1;
				data->c += 1;
			}
		}
	}
	if (char_in_tab[P] != 1 || char_in_tab[E] != 1 || char_in_tab[C] == 0)
		return (false);
	return (true);
}

void	display_frame(char **map, t_data *data, int i, int j)
{
	static int	test;

	test = test % 40000;
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
		data->move_buu[0]->img, CASE_WIDTH * j, CASE_HEIGHT * i);
	test++;
}