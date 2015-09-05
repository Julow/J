/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 22:24:19 by juloo             #+#    #+#             */
/*   Updated: 2015/09/05 20:01:18 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_vector.h"
#include <dirent.h>

static t_bool	get_path(t_prompt *p, t_dstr *dst, t_sub *file)
{
	t_range			word;
	char			*tmp;
	int				i;

	word = RANGE(p->cursor - 1, p->cursor);
	while (word.from >= 0 && IS(p->line.str[word.from], ~IS_SPACE))
		word.from--;
	word.from++;
	if ((word.to - word.from) <= 0 || word.from < 0)
		return (false);
	if (p->line.str[word.from] == '~' && p->line.str[word.from + 1] == '/'
		&& (tmp = ft_getenv("HOME", NULL)) != NULL)
	{
		ft_dstradd(dst, tmp, -1);
		word.from++;
	}
	i = word.to - 1;
	while (i >= word.from && p->line.str[i] != '/')
		--i;
	i++;
	if (i > word.from)
		ft_dstradd(dst, p->line.str + word.from, i - word.from);
	*file = SUB(p->line.str + i, word.to - i);
	return (true);
}

static void		ft_glob(t_dstr path, t_sub file, t_vector *dst)
{
	DIR				*dir;
	struct dirent	*ent;
	t_dstr			*str;

	if ((dir = opendir((path.length <= 0) ? "." : path.str)) == NULL)
		return ;
	while ((ent = readdir(dir)) != NULL)
		if (ft_strnequ(ent->d_name, file.str, file.length)
			&& !ft_strequ(ent->d_name, "..") && !ft_strequ(ent->d_name, "."))
		{
			str = ft_vpush_back(dst, &DSTR0(), 1);
			if (path.length > 0) // TODO: Fix this
				ft_dstradd(str, path.str, path.length);
			ft_dstradd(str, ent->d_name, -1);
			if (ent->d_type == DT_DIR)
				ft_dstradd_char(str, '/');
		}
	closedir(dir);
}

t_bool			prompt_glob(t_prompt *p)
{
	t_dstr			path;
	t_sub			file;
	t_vector		res;

	path = DSTR0();
	if (!get_path(p, &path, &file))
		return (false);
	res = VECTOR(t_dstr);
	ft_glob(path, file, &res);
	if (res.length <= 0)
	{
		ft_vclear(&res);
		return (false);
	}
	if (file.length > 0) // TODO: Fix this
		ft_dstradd(&path, file.str, file.length);
	ft_vpush_back(&res, &path, 1);
	p->tab_res = (t_dstr*)res.data;
	p->tab_count = res.length;
	p->tab_curr = res.length - 1;
	return (true);
}
