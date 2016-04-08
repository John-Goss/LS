/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:57:35 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/04 15:59:02 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_file(t_opt opt, t_elem *file, int type)
{
	t_elem	*ptr;

	ptr = file;
	ptr = sort_elem(ptr, opt);
	(opt.l == 1 || opt.g == 1) ?
				ls_long(opt, ptr, type) : ls_simple(opt, ptr);
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
	t_list	*file;
	t_list	*directory;
	t_list	*ptr;

	file = NULL;
	directory = NULL;
	ptr = path;
	while (ptr)
	{
		if ((dir = opendir(ptr->content)) == NULL)
			errno != ENOTDIR ? error_path("ft_ls: ", ptr->content, 0) :
				ft_lstpushback(&file, ptr->content, ptr->content_size);
		else
		{
			ft_lstpushback(&directory, ptr->content, ptr->content_size);
			if (closedir(dir) == -1)
				error_path("ft_ls: ", ptr->content, 0);
		}
		ptr = ptr->next;
	}
	file ? ls_file(opt, file) : NULL;
	file && directory ? ft_putchar('\n') : NULL;
	directory ? ls_dir(opt, directory, multidir) : NULL;
}
