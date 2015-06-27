/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_searchmode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 22:02:24 by juloo             #+#    #+#             */
/*   Updated: 2015/06/27 23:45:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_prompt.h"
#include "ft_prompt_keys.h"
#include <unistd.h>

typedef struct	s_search
{
	t_hist			*begin;
	t_hist			*curr;
}				t_search;

static void			search_update(t_j *j, t_search *s)
{
	t_hist				*tmp;
	int					y;

	y = j->term.height;
	tmp = s->curr;
	PS(j->caps.cl);
	PS(tgoto(j->caps.cm, 0, --y));
	PS("History search > ");
	PN(j->search_prompt.line.str, j->search_prompt.line.length);
	PS(tgoto(j->caps.cm, 0, --y));
	PS("  ^");
	if (tmp->next != NULL)
		PS(" ...");
	while (y > 0 && tmp != NULL)
	{
		PS(tgoto(j->caps.cm, 0, --y));
		PS("  ");
		PN(tmp->str, tmp->length);
		tmp = tmp->prev;
	}
	FL;
}

static void			search_key(t_j *j, t_search *s, t_ulong key)
{
	if (key == KEY_DOWN)
		s->curr = (s->curr->next == NULL) ? s->curr : s->curr->next;
	else if (key == KEY_UP)
		s->curr = (s->curr->prev == NULL) ? s->curr : s->curr->prev;
	else if (key == KEY_PAGEDOWN)
		s->curr = s->begin;
	else
	{
		ft_promptkey(&(j->search_prompt), key);
		s->curr = s->begin;
		while (s->curr->prev != NULL
			&& !ft_hidenp(j->search_prompt.line.str, s->curr->str))
			s->curr = s->curr->prev;
	}
}

t_bool				j_search(t_j *j, t_hist *hist, t_sub *res)
{
	t_search			s;
	t_ulong				key;

	s = (t_search){hist, hist};
	*res = SUB(NULL, 0);
	if (hist == NULL)
		return (false);
	PS(j->caps.ti), PS(j->caps.vi);
	while (true)
	{
		search_update(j, &s);
		key = 0;
		if (read(0, &key, sizeof(t_ulong)) <= 0 || key == KEY_CTRL_D
			|| key == KEY_CTRL_C || key == KEY_ESC)
			break ;
		if (key == '\r')
		{
			*res = ft_dstrsub(&(j->search_prompt.line), 0, -1);
			break ;
		}
		search_key(j, &s, key);
	}
	PS(j->caps.ve), PS(j->caps.te);
	return ((res->str == NULL) ? false : true);
}
