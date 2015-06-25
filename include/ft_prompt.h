/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 21:54:15 by juloo             #+#    #+#             */
/*   Updated: 2015/06/25 22:44:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H

# include "libft.h"
# include "ft_dstr.h"

/*
** ========================================================================== **
** Bindings
** -----
** c = ctrl
** s = shift
** m = alt / option
** -----
** Cursor:
**  left / right		Move cursor into line
**  c+left / c+right	Move cursor into line word by word
**  c+A / home			Move to the start of the line
**  c+E / end			Move to the end of the line
**  up / right			Navigate in the history
** -
** Delete:
**  c+C					Clear line (if line is not empty)
**  delete				Delete
**  c+H					Backspace by word
**  c+delete			Delete by word
**  c+K					Delete from the cursor to the end of line
**  c+X					Delete current word
** -
** Paste:
**  c+Y					Paste last delete
**  c+V					Paste last delete but keep it in the history
** -
** (TODO) Selection:
**  (TODO) s+right / s+left		Select
**  (TODO) s+c+right / s+c+left	Select by word
** -
** Other:
**  tab					Auto complete
**  shift+tab			Auto complete in reverse order
**  m+!					Active debug print
**  c+space				Disable J
** ========================================================================== **
*/

typedef struct	s_hist
{
	struct s_hist	*prev;
	struct s_hist	*next;
	char			*str;
	int				length;
}				t_hist;

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

t_val			prompt_word_motion(t_prompt *p);
t_val			prompt_word(t_prompt *p);

void			prompt_history(t_prompt *p, t_dstr str);
void			prompt_deletion(t_prompt *p, t_sub str);

t_bool			prompt_glob(t_prompt *p);

void			prompt_completion(t_prompt *p, int order);

/*
** utils
*/
void			ft_freeall(void *data, int count, int size, void (*f)());

#endif
