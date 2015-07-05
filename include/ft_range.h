/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/05 20:26:18 by juloo             #+#    #+#             */
/*   Updated: 2015/07/05 20:50:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANGE_H
# define FT_RANGE_H

typedef struct	s_range
{
	int				from;
	int				to;
}				t_range;

# define RANGE(a,b)		((t_range){(a), (b)})

static inline t_range	ft_range(int from, int to)
{
	if (from > to)
		return (RANGE(to, from));
	return (RANGE(from, to));
};

static inline t_range	ft_rangelimit(t_range r, t_range limit)
{
	if (r.from < limit.from)
		r.from = limit.from;
	else if (r.from > limit.to)
		r.from = limit.to;
	if (r.to < limit.from)
		r.to = limit.from;
	else if (r.to > limit.to)
		r.to = limit.to;
	return (r);
}

static inline t_range	ft_rangemove(t_range r, int move)
{
	return (RANGE(r.from + move, r.to + move));
}

#endif
