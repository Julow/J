/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getkey.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 00:18:47 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 00:20:00 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETKEY_H
# define FT_GETKEY_H

# include "libft.h"

typedef struct	s_key
{
	int				c;
	t_bool			ctrl:1;
	t_bool			shift:1;
	t_bool			alt:1;
}				t_key;

# define GETKEY_MAX_WAIT	{0, 100}

# define KEY(c,t,s,a)		((t_key){(c), (t), (s), (a)})

# define GETKEY_SPECIAL		0xF0000

# define GETKEY_CTRL		(1 << 2)
# define GETKEY_ALT			(1 << 1)
# define GETKEY_SHIFT		(1 << 0)

# define GETKEY_BACKSPACE	0x7F
# define GETKEY_ESC			'\033'
# define GETKEY_UP			(GETKEY_SPECIAL + 1)
# define GETKEY_RIGHT		(GETKEY_SPECIAL + 2)
# define GETKEY_BOTTOM		(GETKEY_SPECIAL + 3)
# define GETKEY_LEFT		(GETKEY_SPECIAL + 4)
# define GETKEY_DELETE		(GETKEY_SPECIAL + 5)
# define GETKEY_HOME		(GETKEY_SPECIAL + 7)
# define GETKEY_END			(GETKEY_SPECIAL + 8)
# define GETKEY_PAGEUP		(GETKEY_SPECIAL + 9)
# define GETKEY_PAGEDOWN	(GETKEY_SPECIAL + 10)

t_key			ft_getkey(void);

#endif
