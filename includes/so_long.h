/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:14:17 by amouflet          #+#    #+#             */
/*   Updated: 2023/11/14 12:06:26 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef CASE_WIDTH
#  define CASE_WIDTH 40
# endif /*CASE_WIDTH*/

# ifndef CASE_HEIGHT
#  define CASE_HEIGHT 40
# endif /*CASE_HEIGHT*/

# ifndef W_HEIGHT
#  define W_HEIGHT 25
# endif /*W_HEIGHT*/

# ifndef W_WIDTH
#  define W_WIDTH 48
# endif /*W_WIDTH*/

# include <stdbool.h>
# include <mlx_int.h>

# ifndef NB_FRAME
#  define NB_FRAME 50000
# endif /* NB_FRAME */

# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		xy[2];
}				t_image;

typedef struct s_data
{
	t_xvar	*mlx;
	t_image	floor[1];
	t_image	out[1];
	t_image	collectible[1];
	t_image	move[6][1];
	t_image	move_buu[9][1];
	t_image	wall[1];
	t_image	player[1];
	int		w_height;
	int		w_width;
	int		count_move;
	int		c;
	int		exit[2];
	char	**tab;
	char	**to_print;
	int		xy[2];
}	t_data;

void	get_player_pos(char **map, int *pos, char c);
int		init_data(t_data *data);
void	free_tab(char **tab);
int		get_map(const char *map_path, t_data *data, int *xy);
void	draw(char **map, t_data *data, int *xy);
int		close_n_free_win(t_data *data);
int		manage_hook(int keycode, t_data *data);
void	get_to_print(char **tab, t_data *data);
void	set_hook(t_data *data);
int		print_game(t_data *data);
void	display_frame(char **map, t_data *data, int i, int j);

#endif /*SO_LONG_H*/
