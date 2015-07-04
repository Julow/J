/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 14:38:28 by juloo             #+#    #+#             */
/*   Updated: 2015/07/04 21:23:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HIST_H
# define FT_HIST_H

# include "libft.h"

typedef struct	s_hist
{
	struct s_hist	*prev;
	struct s_hist	*next;
	char			*str;
	int				length;
}				t_hist;

void			ft_histsave(t_hist *hist, t_sub file);
void			ft_histdelete(t_hist *hist);
void			ft_histtrunc(t_hist **hist, int max);
void			ft_histload(t_hist **hist, t_sub file);
void			ft_histadd(t_hist **hist, t_sub add);

/*
** utils
*/
int				ft_open(t_sub file, int flags);

#endif
