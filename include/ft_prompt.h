/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 21:54:15 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 20:38:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H

# include "libft.h"
# include "ft_dstr.h"
# include "ft_hist.h"
# include "ft_range.h"

# define PROMPT_MARGIN	8

typedef struct	s_prompt_events
{
	void			(*on_return)();
	void			*data;
}				t_prompt_events;

typedef struct	s_prompt
{
/*
** integration
*/
	t_prompt_events	events;
/*
** line
*/
	t_dstr			line;
	int				cursor;
	int				selection;
/*
** history
*/
	t_hist			*history;
	t_hist			*hist_curr;
	t_hist			*clipboard;
/*
** tab completion
*/
	t_dstr			*tab_res;
	int				tab_count;
	int				tab_curr;
}				t_prompt;

void			ft_promptinit(t_prompt *p, t_prompt_events events);
void			ft_promptkey(t_prompt *p, t_ulong key);

/*
** ft_promptput
** ----
** Put the line to FTOUT
** ----
** Return the position of the cursor
*/
int				ft_promptput(t_prompt *p, int max_width);

/*
** internal
*/
void			prompt_flush(t_prompt *p);

t_range			prompt_word(t_prompt *p);

t_bool			prompt_glob(t_prompt *p);

void			prompt_completion(t_prompt *p, int order);

/*
** utils
*/
void			ft_freeall(void *data, int count, int size, void (*f)());

#endif
