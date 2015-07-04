/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 21:54:15 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 15:44:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H

# include "libft.h"
# include "ft_dstr.h"
# include "ft_hist.h"

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
	t_hist			*deletions;
/*
** tab completion
*/
	t_dstr			*tab_res;
	int				tab_count;
	int				tab_curr;
}				t_prompt;

typedef struct	s_val
{
	int				from;
	int				to;
}				t_val;

# define VAL(f,t)		((t_val){(f), (t)})

void			ft_promptinit(t_prompt *p, t_prompt_events events);
void			ft_promptkey(t_prompt *p, t_ulong key);

/*
** internal
*/
void			prompt_flush(t_prompt *p);

t_val			prompt_word(t_prompt *p);

void			prompt_deletion(t_prompt *p, t_sub str);

t_bool			prompt_glob(t_prompt *p);

void			prompt_completion(t_prompt *p, int order);

/*
** utils
*/
void			ft_freeall(void *data, int count, int size, void (*f)());

#endif
