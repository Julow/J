/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:10:39 by juloo             #+#    #+#             */
/*   Updated: 2015/06/19 23:58:48 by juloo            ###   ########.fr       */
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

void			key_nl(t_j *j, int key);
void			key_eof(t_j *j, int key);
void			key_int(t_j *j, int key);

void			key_up(t_j *j);
void			key_right(t_j *j);
void			key_down(t_j *j);
void			key_left(t_j *j);

void			key_ctrl_left(t_j *j);
void			key_ctrl_right(t_j *j);

void			key_delete(t_j *j);
void			key_backspace(t_j *j);

void			key_ctrl_l(t_j *j);
void			key_ctrl_e(t_j *j);
void			key_ctrl_a(t_j *j);

#endif
