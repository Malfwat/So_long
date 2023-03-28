/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:48:46 by amouflet          #+#    #+#             */
/*   Updated: 2023/02/02 14:32:58 by amouflet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# ifndef ESC
#  define ESC 65307
# endif /*ESC*/

# ifndef X_CROSS
#  define X_CROSS 17
# endif /*X_CROSS*/

void	move_player(t_data *data, int *dir);

#endif /*HOOK_H*/