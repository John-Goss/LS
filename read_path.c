/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:57:35 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/16 17:32:52 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_file(t_opt opt, t_elem *file, int type)
{
	t_elem	*ptr;

	ptr = file;
	ptr = sort_elem(ptr, opt);
	(opt.l == 1) ? ls_long(opt, ptr, type) : ls_basic(opt, ptr);
	opt.upper_r == 1 ? recursion(opt, ptr) : NULL;
}

void	ls_dir_open(t_opt opt, t_elem *dir_list, int multidir)
{
	DIR		*dir;
	t_elem	*file;
	int		first;

	first = 0;
	file = NULL;
	while (dir_list)
	{
		dir = opendir(dir_list->name);
		while (elemget(&file, readdir(dir),
						ft_strjoin(dir_list->path, "/"), opt) != 0)
			;
		closedir(dir);
		if (file)
		{
			first == 1 ? ft_putchar('\n') : NULL;
			multidir ? ft_putendl(ft_strjoin(dir_list->name, ":")) : NULL;
			first = 1;
			display_file(opt, file, 1);
		}
		file = NULL;
		dir_list = dir_list->next;
	}
}

void	ls_dir(t_opt opt, t_list *path, int multidir)
{
	t_list	*ptr;
	t_elem	*dir_list;

	ptr = path;
	dir_list = NULL;
	while (ptr)
	{
		elemgetfiles(&dir_list, ptr->content, "", opt);
		ptr = ptr->next;
	}
	dir_list = sort_elem(dir_list, opt);
	ls_dir_open(opt, dir_list, multidir);
}

void	ls_file(t_opt opt, t_list *path)
{
	t_list	*ptr;
	t_elem	*file;

	ptr = path;
	file = NULL;
	opt.a = 1;
	while (ptr)
	{
		elemgetfiles(&file, ptr->content, "", opt);
		ptr = ptr->next;
	}
	if (file)
		display_file(opt, file, 0);
}

void	read_path(t_opt opt, t_list *path, int multidir)
{
	DIR		*dir;
	t_list	*tab[3];

	tab[0] = NULL;
	tab[1] = NULL;
	tab[2] = path;
	while (tab[2])
	{
		if (is_link(tab[2]->content, opt))
			ft_lstpushback(&tab[0], tab[2]->content, tab[2]->content_size);
		else if ((dir = opendir(tab[2]->content)) == NULL)
			errno != ENOTDIR ? error_path("ft_ls: ", tab[2]->content, 0) :
				ft_lstpushback(&tab[0], tab[2]->content, tab[2]->content_size);
		else
		{
			ft_lstpushback(&tab[1], tab[2]->content, tab[2]->content_size);
			if (closedir(dir) == -1)
				error_path("ft_ls: ", tab[2]->content, 0);
		}
		tab[2] = tab[2]->next;
	}
	tab[0] ? ls_file(opt, tab[0]) : NULL;
	tab[0] && tab[1] ? ft_putchar('\n') : NULL;
	tab[1] ? ls_dir(opt, tab[1], multidir) : NULL;
}
