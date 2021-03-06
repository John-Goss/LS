/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 12:17:07 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/16 17:29:15 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_elem	*elemnew(char *name, char *path, t_opt opt)
{
	t_elem			*elem;
	struct stat		fstat;

	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	elem->name = ft_strdup(name);
	elem->path = ft_strjoin(path, name);
	if (lstat(elem->path, &fstat) == -1)
	{
		error_path("ft_ls: ", elem->name, 1);
		return (NULL);
	}
	elem->st_mode = fstat.st_mode;
	elem->st_nlink = fstat.st_nlink;
	elem->st_uid = fstat.st_uid;
	elem->st_gid = fstat.st_gid;
	elem->st_size = fstat.st_size;
	elem->st_blocks = fstat.st_blocks;
	elem->date = (opt.u == 1 ? fstat.st_atime : fstat.st_mtime);
	elem->st_rdev = fstat.st_rdev;
	elem->next = NULL;
	return (elem);
}

int				elemget(t_elem **files, struct dirent *file, char *pa, t_opt op)
{
	t_elem	*list;

	list = *files;
	if (!file)
		return (0);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elemnew(file->d_name, pa, op);
	}
	else
		*files = elemnew(file->d_name, pa, op);
	return (1);
}

void			elemgetfiles(t_elem **files, char *name, char *path, t_opt opt)
{
	t_elem *list;

	list = *files;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elemnew(name, path, opt);
	}
	else
		*files = elemnew(name, path, opt);
}

int				is_link(char *path, t_opt opt)
{
	t_elem *new;

	if ((new = elemnew("", path, opt)) == NULL)
		return (0);
	if (!(S_ISLNK(new->st_mode)))
		return (0);
	return (1);
}
