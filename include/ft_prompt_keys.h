/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_keys.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:10:39 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 20:18:43 by juloo            ###   ########.fr       */
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
	t_key			key;
	void			(*f)();
}				t_binding;

/*
** ========================================================================== **
*/

void			key_nl(t_prompt *p);
void			key_eof(t_prompt *p);
void			key_int(t_prompt *p);

void			key_up(t_prompt *p);
void			key_right(t_prompt *p);
void			key_down(t_prompt *p);
void			key_left(t_prompt *p);

void			key_tab(t_prompt *p);
void			key_shift_tab(t_prompt *p);
void			key_restore_tab(t_prompt *p, t_key key);

void			key_ctrl_left(t_prompt *p);
void			key_ctrl_right(t_prompt *p);

void			key_shift_right(t_prompt *p);
void			key_shift_left(t_prompt *p);
void			key_ctrl_shift_right(t_prompt *p);
void			key_ctrl_shift_left(t_prompt *p);

void			key_delete(t_prompt *p);
void			key_backspace(t_prompt *p);
void			key_delete_selection(t_prompt *p);

void			key_ctrl_delete(t_prompt *p);
void			key_ctrl_backspace(t_prompt *p);

void			key_ctrl_e(t_prompt *p);
void			key_ctrl_a(t_prompt *p);

void			key_ctrl_k(t_prompt *p);
void			key_ctrl_o(t_prompt *p);
void			key_ctrl_x(t_prompt *p);
void			key_ctrl_w(t_prompt *p);

void			key_ctrl_v(t_prompt *p);
void			key_ctrl_y(t_prompt *p);

void			key_ctrl_g(t_prompt *p);

#endif
