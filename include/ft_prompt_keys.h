/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_keys.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:10:39 by juloo             #+#    #+#             */
/*   Updated: 2015/06/27 00:36:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_KEYS_H
# define FT_PROMPT_KEYS_H

# include "ft_prompt.h"

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

# define KEY_CTRL_A		1
# define KEY_CTRL_E		5
# define KEY_CTRL_C		3
# define KEY_CTRL_D		4
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

# define KEY_UP			4283163
# define KEY_LEFT		4479771
# define KEY_RIGHT		4414235
# define KEY_DOWN		4348699

# define KEY_ESC		27
# define KEY_BACK		127
# define KEY_DELETE		2117294875
# define KEY_RETURN		10
# define KEY_END		4607771
# define KEY_HOME		4738843
# define KEY_PAGEUP		2117425947
# define KEY_PAGEDOWN	2117491483

void			key_nl(t_prompt *p, int key);
void			key_eof(t_prompt *p, int key);
void			key_int(t_prompt *p, int key);

void			key_up(t_prompt *p);
void			key_right(t_prompt *p);
void			key_down(t_prompt *p);
void			key_left(t_prompt *p);

void			key_tab(t_prompt *p);
void			key_shift_tab(t_prompt *p);
void			key_restore_tab(t_prompt *p, t_ulong key);

void			key_ctrl_left(t_prompt *p);
void			key_ctrl_right(t_prompt *p);

void			key_delete(t_prompt *p);
void			key_backspace(t_prompt *p);

void			key_ctrl_delete(t_prompt *p);
void			key_ctrl_backspace(t_prompt *p);

void			key_ctrl_e(t_prompt *p);
void			key_ctrl_a(t_prompt *p);

void			key_ctrl_x(t_prompt *p);
void			key_ctrl_k(t_prompt *p);

void			key_ctrl_v(t_prompt *p);
void			key_ctrl_y(t_prompt *p);

#endif
