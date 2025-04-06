/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:21:11 by amouflet          #+#    #+#             */
/*   Updated: 2023/01/31 19:17:19 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <map.h>
#include <libft.h>
#include <mlx.h>

bool	is_good_content(char **tab, int width, int height, t_data *data)
{
	static int	char_in_tab[3];

	while (--height >= 0)
	{
		width = -1;
		while (tab[height][++width])
		{	
			if (is_map_char(tab[height][width], CHAR_SET_B) == false)
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

int	print_move1(t_data *data)
{
	int	test[2];
	int	i;

	i = 0;
	get_to_print(data->tab, data);
	get_player_pos(data->to_print, test, 'P');
	while (i < 5)
	{
		draw(data->to_print, data, data->xy);
		mlx_put_image_to_window \
		(data->mlx, data->mlx->win_list, data->move[i]->img, \
		CASE_WIDTH * (test[0]), CASE_HEIGHT * test[1]);
		usleep(8000);
		i++;
	}
	return (0);
}

int	print_move2(t_data *data)
{
	int	test[2];
	int	i;

	get_to_print(data->tab, data);
	get_player_pos(data->to_print, test, 'P');
	i = 5;
	while (--i > 0)
	{
		draw(data->to_print, data, data->xy);
		mlx_put_image_to_window \
		(data->mlx, data->mlx->win_list, data->move[i]->img, \
		CASE_WIDTH * (test[0]), CASE_HEIGHT * test[1]);
		usleep(8000);
	}
	return (0);
}

static void	make_change(t_data *data, int *dir)
{
	int	x;
	int	y;

	if (data->player->xy[0] == data->exit[0] && data->player->xy[1] == data->exit[1])
		data->tab[data->player->xy[1]][data->player->xy[0]] = 'E';
	else
		data->tab[data->player->xy[1]][data->player->xy[0]] = '0';
	y = data->player->xy[1] + dir[1];
	x = data->player->xy[0] + dir[0];
	if (data->tab[y][x] == 'C')
		data->c -= 1;
	data->tab[data->player->xy[1] + dir[1]][data->player->xy[0] + dir[0]] = 'P';
	data->player->xy[1] += dir[1];
	data->player->xy[0] += dir[0];
}

void	move_player(t_data *data, int *dir)
{
	char	*str;

	if (!data->tab[data->player->xy[1] + dir[1]] \
	|| data->tab[data->player->xy[1] + dir[1]] \
	[data->player->xy[0] + dir[0]] == '1')
		return ;
	data->count_move += 1;
	print_move1(data);
	if (data->tab[data->player->xy[1] + dir[1]] \
	[data->player->xy[0] + dir[0]] == '2')
	{
		ft_putendl_fd("You lose!", 1);
		close_n_free_win(data);
	}
	make_change(data, dir);
	print_move2(data);
	print_game(data);
	str = ft_itoa(data->count_move);
	if (str == NULL)
		close_n_free_win(data);
	mlx_string_put(data->mlx, data->mlx->win_list, 15, 20, 0x00FFFFFF, str);
	free(str);
}
