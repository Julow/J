/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:33 by juloo             #+#    #+#             */
/*   Updated: 2015/06/30 17:23:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_H
# define J_H

# include "libft.h"
# include "ft_dstr.h"
# include "ft_term.h"
# include "ft_prompt.h"

/*
** ========================================================================== **
** J
*/

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
**  c+left / c+right \
**  m+left / m+right	Move cursor into line word by word
**  c+A / home			Move to the start of the line
**  c+E / end			Move to the end of the line
** -----
** History:
**  up / right			Navigate in the history
**  c+R					History search (see ft_hmatch.c)
** -
** Cut/Paste:
** // All cut are chained into the clipboard
**  c+K					Cut from the cursor to the end of line
**  c+O					Cut from the begin of line to the cursor
**  c+X					Cut the line
**  c+Y					Paste last cut
**  c+V					Paste last cut and remove it from the clipboard
** -
** Edition:
**  c+C					Clear line
**  c+H					Backspace by word
**  c+delete			Delete by word
**  delete				Delete by char
**  c+F					Search and replace
** -
** Selection:
** // Pasting or writing a char overwrite the selection
** // Deletions delete the selected text
** // Moving cursor cancel selection
**  s+left / s+right	Select text
**  c+X / c+W			Cut the selection
**  (TODO) c+D						Select current word
**  (TODO) c+s+left / c+s+right		Select by word
**  (TODO) c+F						Search and replace in the selection
**  (TODO) Escape					Cancel selection
** -
** Other:
**  tab					Auto complete
**  shift+tab			Auto complete in reverse order
**  c+space				Disable J
** ========================================================================== **
*/

/*
** TODO:
**  Selection with keyboard
**  Fullscreen mode
**  Keep last output for search
**  Save last output for later
**  Write an output in stdin
**  Pipe an output to a system command
**  Use of ft_regex
**  Config
**  Put deletion history into a tab completion
*/

# define PN(s,n)		(ft_write(FTOUT, (s), (n)))

# define HISTORY_FILE	".j_history"
# define HISTORY_MAX	256

# define BUFF_SIZE		512

# define MASTER_BUFF	512

# define PIPE_READ		0
# define PIPE_WRITE		1

# define MAX_ESCAPE_LEN	8

typedef struct	s_caps
{
	char			*ch; // Move cursor x (Maybe unsupported)
	char			*ce; // Clear from cursor to right
	char			*cm; // Move cursor x y
	char			*cl; // Clear screen
	char			*vi; // VI mode (cursor hide)
	char			*ve; // exit VI mode
	char			*ti; // TI mode (tmp screen)
	char			*te; // exit TI mode
}				t_caps;

typedef struct	s_j
{
	char			**cmd;
	int				master;
	int				slave_pid;
	t_term			term;
	t_caps			caps;
	int				flags;
	int				line_start;
	t_prompt		prompt;
	t_prompt		search_prompt;
	t_prompt		ask_prompt;
}				t_j;

# define FLAG_TI		(1 << 1)
# define FLAG_RETURN	(1 << 3)

# define J_HIDE			(1 << 1)
# define J_SHOW			(1 << 2)
# define J_REFRESH		(J_HIDE | J_SHOW)

/*
** argv
*/
t_bool			parse_argv(t_j *j, int argc, char **argv);

/*
** term
*/
t_bool			start_slave(t_j *j);
void			start_master(t_j *j);
void			scan_output(t_j *j, t_sub output);

void			j_set(t_j *j, int flags);

void			j_flush(t_j *j);
void			j_key(t_j *j, t_ulong key);

t_bool			j_search(t_j *j, t_hist *hist, t_sub *res);
t_bool			j_ask(t_j *j, char const *q, t_sub *res);

void			j_history_save(t_hist *hist);
void			j_history_load(t_hist **hist);

/*
** keys
*/
void			key_refresh(t_j *j);
void			key_ctrl_l(t_j *j);
void			key_ctrl_r(t_j *j);
void			key_ctrl_f(t_j *j);

/*
** utils
*/
t_bool			ft_openpt(int *master, int *slave);

void			ft_dstrreplace(t_dstr *str, t_sub search, t_sub replace);

t_bool			ft_hmatch(char const *str, char const *pattern);

#endif
