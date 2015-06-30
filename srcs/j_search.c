/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 22:02:24 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 11:10:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j.h"
#include "ft_prompt.h"
#include "ft_prompt_keys.h"
#include <unistd.h>

static t_hist		*search_next(t_j *j, t_hist *hist, t_hist *def)
{
	while (hist != NULL && !ft_hmatch(hist->str, j->search_prompt.line.str))
		hist = hist->next;
	if (hist == NULL)
		return (def);
	return (hist);
}

static t_hist		*search_prev(t_j *j, t_hist *hist, t_hist *def)
{
	while (hist != NULL && !ft_hmatch(hist->str, j->search_prompt.line.str))
		hist = hist->prev;
	if (hist == NULL)
		return (def);
	return (hist);
}

static t_hist		*search_key(t_j *j, t_ulong key, t_hist *hist)
{
	if (key != KEY_PAGEDOWN)
		ft_promptkey(&(j->search_prompt), key);
	return (search_prev(j, hist, NULL));
}

static void			search_refresh(t_j *j, t_hist *hist)
{
	j_set(j, J_HIDE);
	PC('\'');
	PS(j->search_prompt.line.str);
	PS("' > ");
	if (hist == NULL)
		PS("(no result)");
	else
		PN(hist->str, hist->length);
	PS(tgoto(j->caps.ch, 0, j->line_start + j->search_prompt.cursor + 1));
	FL;
}

t_bool				j_search(t_j *j, t_hist *hist, t_sub *res)
{
	t_hist				*begin;
	t_ulong				key;

	begin = hist;
	hist = search_prev(j, hist, hist);
	while (true)
	{
		search_refresh(j, hist);
		key = 0;
		if (read(0, &key, sizeof(t_ulong)) <= 0 || key == KEY_CTRL_D
			|| key == KEY_CTRL_C || key == KEY_ESC)
			break ;
		else if (key == '\r')
			return ((*res = (hist != NULL) ? SUB(hist->str, hist->length)
				: SUBC("")), true);
		else if (key == KEY_DOWN)
			hist = (hist == NULL) ? NULL : search_next(j, hist->next, hist);
		else if (key == KEY_UP)
			hist = (hist == NULL) ? NULL : search_prev(j, hist->prev, hist);
		else
			hist = search_key(j, key, begin);
	}
	return (false);
}
