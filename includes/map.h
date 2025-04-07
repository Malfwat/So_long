/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:24:31 by amouflet          #+#    #+#             */
/*   Updated: 2023/02/02 14:33:41 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <so_long.h>

# ifndef CHAR_SET_M
#  define CHAR_SET_M "PEC01"
# endif /*CHAR_SET_M*/

# ifndef CHAR_SET_B
#  define CHAR_SET_B "PEC012"
# endif /*CHAR_SET_B*/

typedef struct s_map
{
	char			*line;
	int				len;
	struct s_map	*final_line;
	struct s_map	*next;
}					t_map;

typedef enum e_char
{
	P,
	E,
	C	
}	t_char_in_map;

// map_lst.c

t_map	*get_map_list(const char *map_path);
void	free_map_in_lst(t_map *map, char *str);

// map_check_format.c

bool	is_good_format(char **tab, t_data *data);
bool	is_map_char(char c, char *char_set);

// map_check_gameplay.c

bool	check_gameplay(char **map);

// map_utils.c

int		tab_size(int *x, int *y, char **tab);

bool	is_good_content(char **tab, int width, int height, t_data *data);
#endif /*MAP_H*/