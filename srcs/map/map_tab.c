/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:53:30 by amouflet          #+#    #+#             */
/*   Updated: 2023/01/31 19:47:57 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <map.h>

bool	is_ber(const char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(&str[len - 4], ".ber", 4))
		return (false);
	return (true);
}

int	lst_size(t_map *map)
{
	int	size;

	size = 0;
	while (map)
	{
		size++;
		map = map->next;
	}
	return (size);
}

static	char	**put_in_array(t_map *map_lst)
{
	char	**tab;
	int		i;
	t_map	*tmp;

	if (!map_lst)
		return (NULL);
	tab = malloc(sizeof(char *) * (lst_size(map_lst) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (map_lst)
	{
		tmp = map_lst;
		map_lst = map_lst->next;
		tab[i] = tmp->line;
		free(tmp);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	get_map(const char *map_path, t_data *data, int *xy)
{
	char	**tab;
	t_map	*map_lst;

	if (is_ber(map_path) == false)
		return (ft_putendl_fd("Isn't a .ber file!", 2), -1);
	map_lst = get_map_list(map_path);
	if (!map_lst)
		return (free_map_in_lst(map_lst, NULL), \
		ft_putendl_fd("The map is empty!", 2), -1);
	tab = put_in_array(map_lst);
	if (!tab)
		return (free_map_in_lst(map_lst, NULL), -1);
	if (is_good_format(tab, data) == false)
		return (free_tab(tab), ft_putendl_fd \
		("The map is not ok!", 2), -1);
	if (check_gameplay(tab) == false)
		return (free_tab(tab), ft_putendl_fd \
		("The map is not solvable!", 2), -1);
	data->tab = tab;
	tab_size(&xy[0], &xy[1], tab);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
