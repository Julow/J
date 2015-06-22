/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:10:39 by juloo             #+#    #+#             */
/*   Updated: 2015/06/22 23:09:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "j.h"

/*
** ========================================================================== **
** Key bindings
*/

typedef struct	s_binding
{
	t_ulong			key;
	void			(*f)();
}				t_binding;

/*
** ========================================================================== **
*/

# define KEY_CTRL_L		12
# define KEY_CTRL_R		18
# define KEY_CTRL_H		8
# define KEY_CTRL_K		11
# define KEY_CTRL_X		24
# define KEY_CTRL_V		22
# define KEY_CTRL_Y		25
# define KEY_CTRL_SPACE	0
# define KEY_SHIFT_TAB	5921563

# define KEY_ALL		((t_ulong)-1)

# define KEY_END		4607771
# define KEY_HOME		4738843
# define KEY_PAGEUP		2117425947
# define KEY_PAGEDOWN	2117491483

void			key_nl(t_j *j, int key);
void			key_eof(t_j *j, int key);
void			key_int(t_j *j, int key);

void			key_up(t_j *j);
void			key_right(t_j *j);
void			key_down(t_j *j);
void			key_left(t_j *j);

void			key_tab(t_j *j);
void			key_shift_tab(t_j *j);
void			key_restore_tab(t_j *j, t_ulong key);

void			key_ctrl_left(t_j *j);
void			key_ctrl_right(t_j *j);

void			key_delete(t_j *j);
void			key_backspace(t_j *j);

void			key_ctrl_delete(t_j *j);
void			key_ctrl_backspace(t_j *j);

void			key_ctrl_l(t_j *j);
void			key_ctrl_e(t_j *j);
void			key_ctrl_a(t_j *j);

void			key_ctrl_x(t_j *j);
void			key_ctrl_k(t_j *j);

void			key_ctrl_v(t_j *j);
void			key_ctrl_y(t_j *j);

void			key_debug(t_j *j);

#endif
