/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 21:33:32 by juloo             #+#    #+#             */
/*   Updated: 2015/07/23 20:13:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getkey.h"
#include <unistd.h>
#include <sys/select.h>

struct
{
	int		end;
	int		c;
} const			g_seq_ends[] = {
	{'A', GETKEY_UP},
	{'B', GETKEY_DOWN},
	{'C', GETKEY_RIGHT},
	{'D', GETKEY_LEFT},
	{'H', GETKEY_HOME},
	{'F', GETKEY_END},
	{3, GETKEY_DELETE},
	{5, GETKEY_PAGEUP},
	{6, GETKEY_PAGEDOWN},
	{'\0', 0}
};

static char		next_char(void)
{
	fd_set			fdr;
	char			c;

	FD_ZERO(&fdr);
	FD_SET(0, &fdr);
	if (select(1, &fdr, NULL, NULL, &(struct timeval)GETKEY_MAX_WAIT) < 0)
		return (EOF);
	if (FD_ISSET(0, &fdr))
	{
		if (read(0, &c, 1) <= 0)
			return (EOF);
		return (c);
	}
	return ('\0');
}

static t_key	parse_utf8(char c)
{
	return (KEY(c, 0));
	// TODO utf-8
}

/*
** '\033', start, (n1, (';', n2)?)?, end
** start (char): '[', 'O'
** n1 (digit, def: 1)
** n2 (digit, def: 0): 2 (shift), 3 (alt), 5 (ctrl) (111 + 1)
** end (char)
** if end == '~': n1 is used
*/
static t_key	parse_seq_end(int n2, char end)
{
	int				i;
	t_key			key;

	key = KEY('\0', n2 - 1);
	i = -1;
	while (g_seq_ends[++i].end != '\0')
	{
		if (g_seq_ends[i].end == end)
		{
			key.c = g_seq_ends[i].c;
			return (key);
		}
	}
	ft_printf("\r\nDEBUG: Invalid end: %c\r\n", end);
	return (key);
}

static t_key	parse_seq(void)
{
	int				n1;
	int				n2;
	char			c;

	n1 = 1;
	n2 = 1;
	c = next_char();
	if (IS(c, IS_DIGIT))
	{
		n1 = c - '0';
		c = next_char();
	}
	if (c == ';' && IS((c = next_char()), IS_DIGIT))
	{
		n2 = c - '0';
		c = next_char();
	}
	return (parse_seq_end(n2, (c == '~') ? n1 : c));
}

t_key			ft_getkey(void)
{
	char			c;

	if (read(0, &c, 1) <= 0)
		c = EOF;
	else if (c < 0 || c > 127)
		return (parse_utf8(c));
	else if (c == '\033')
	{
		c = next_char();
		if (c == '[' || c == 'O')
			return (parse_seq());
		if (c == '\0')
			c = '\033';
	}
	else if (c >= 1 && c <= 26)
		return (KEY('a' + c - 1, GETKEY_CTRL));
	else if (IS(c, IS_UPPER))
		return (KEY(c, GETKEY_SHIFT));
	return (KEY(c, 0));
}
