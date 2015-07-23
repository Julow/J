/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getkey.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 00:18:47 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 20:20:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETKEY_H
# define FT_GETKEY_H

# include "libft.h"

typedef struct	s_key
{
	int				c;
	int				flags;
}				t_key;

# define GETKEY_MAX_WAIT	{0, 100}

# define KEY(c,f)			((t_key){(c), (f)})

# define GETKEY_SPECIAL		0xF0000

# define KEY_CTRL			(1 << 2)
# define KEY_ALT			(1 << 1)
# define KEY_SHIFT			(1 << 0)

# define KEY_BACKSPACE		0x7F
# define KEY_ESC			'\033'
# define KEY_UP				(GETKEY_SPECIAL + 1)
# define KEY_RIGHT			(GETKEY_SPECIAL + 2)
# define KEY_DOWN			(GETKEY_SPECIAL + 3)
# define KEY_LEFT			(GETKEY_SPECIAL + 4)
# define KEY_DELETE			(GETKEY_SPECIAL + 5)
# define KEY_HOME			(GETKEY_SPECIAL + 7)
# define KEY_END			(GETKEY_SPECIAL + 8)
# define KEY_PAGEUP			(GETKEY_SPECIAL + 9)
# define KEY_PAGEDOWN		(GETKEY_SPECIAL + 10)

t_key			ft_getkey(void);

static inline t_bool	ft_keyequ(t_key k1, t_key k2)
{
	return (k1.c == k2.c && k1.flags == k2.flags);
}

#endif
