/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:14:55 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/16 17:39:42 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_color(t_opt opt, mode_t mode)
{
	if (!isatty(STDOUT_FILENO) || !opt.g)
		return ;
	S_ISBLK(mode) ? ft_putstr(C_RED) : NULL;
	S_ISCHR(mode) ? ft_putstr(C_BLUE) : NULL;
	S_ISDIR(mode) ? ft_putstr(C_CYAN) : NULL;
	S_ISFIFO(mode) ? ft_putstr(C_BROWN) : NULL;
	S_ISREG(mode) ? ft_putstr(C_NONE) : NULL;
	S_ISLNK(mode) ? ft_putstr(C_GREEN) : NULL;
	S_ISSOCK(mode) ? ft_putstr(C_MAGENTA) : NULL;
}

static int	lst_chr_blk(t_elem *cur)
{
	t_elem	*tmp;

	tmp = cur;
	while (tmp)
	{
		if (S_ISCHR(tmp->st_mode) || S_ISBLK(tmp->st_mode))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		ls_basic(t_opt opt, t_elem *files)
{
	t_elem	*cur;

	cur = files;
	while (cur)
	{
		if (S_ISLNK(cur->st_mode) && opt.a)
			;
		else if (!(opt.a == 0 && cur->name[0] == '.'))
		{
			ft_color(opt, cur->st_mode);
			ft_putendl(cur->name);
			if (isatty(STDOUT_FILENO))
				ft_putstr(C_NONE);
		}
		cur = cur->next;
	}
}

void		ls_all_info(t_opt opt, t_elem *cur, t_size size)
{
	print_user_access(cur);
	print_int(size, cur->st_nlink, size.linkspace, 0);
	if (getpwuid(cur->st_uid))
		print_str(getpwuid(cur->st_uid)->pw_name, size.userspace);
	else
		print_str(ft_itoa(cur->st_uid), size.userspace);
	if (getgrgid(cur->st_gid))
		print_str(getgrgid(cur->st_gid)->gr_name, size.groupspace);
	else
		print_str(ft_itoa(cur->st_gid), size.groupspace);
	if (S_ISCHR(cur->st_mode) || S_ISBLK(cur->st_mode))
		print_majmin(cur, size);
	else
		lst_chr_blk(cur) == 1 ? print_int(size, cur->st_size, size.size, 1)
			: print_int(size, cur->st_size, size.size, 0);
	display_date(cur->date);
	ft_color(opt, cur->st_mode);
	S_ISLNK(cur->st_mode) ? display_link(cur) : ft_putendl(cur->name);
	if (isatty(STDOUT_FILENO))
		ft_putstr(C_NONE);
}

void		ls_long(t_opt opt, t_elem *files, int is_dir)
{
	t_elem	*cur;
	t_size	size;

	cur = files;
	size = get_size(opt, files);
	if (is_dir)
	{
		if (!opt.a && cur->name[0] == '.' && !cur->name[1] &&
				cur->next->name[0] == '.' && cur->next->name[1] == '.'
				&& !cur->next->next)
			return ;
		ft_putstr("total ");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	while (cur)
	{
		if (!(opt.a == 0 && cur->name[0] == '.'))
			ls_all_info(opt, cur, size);
		cur = cur->next;
	}
}
