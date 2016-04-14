/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:20:12 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/14 15:28:11 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_user_access(t_elem *elem)
{
	(S_ISFIFO(elem->st_mode) ? ft_putchar('p') : (0));
	(S_ISCHR(elem->st_mode) ? ft_putchar('c') : (0));
	(S_ISDIR(elem->st_mode) ? ft_putchar('d') : (0));
	(S_ISBLK(elem->st_mode) ? ft_putchar('b') : (0));
	(S_ISREG(elem->st_mode) ? ft_putchar('-') : (0));
	(S_ISLNK(elem->st_mode) ? ft_putchar('l') : (0));
	(S_ISSOCK(elem->st_mode) ? ft_putchar('s') : (0));
	ft_putchar((elem->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((elem->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((elem->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}

void	print_int(t_size size, int nlink, int spacemax, int type)
{
	int		n;

	n = type == 1 ? size.maj + size.min + 2
	: spacemax - ft_strlen(ft_itoa(nlink));
	while (n-- > 0)
		ft_putchar(' ');
	ft_putnbr(nlink);
	ft_putchar(' ');
}

void	print_str(char *str, int spacemax)
{
	int		n;

	n = spacemax - ft_strlen(str);
	ft_putstr(str);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}

void	print_majmin(t_elem *file, t_size size)
{
	int		min;
	int		maj;

	min = (int)ft_strlen(ft_itoa(minor(file->st_rdev)));
	maj = (int)ft_strlen(ft_itoa(major(file->st_rdev)) + 1);
	while (maj < size.maj--)
		ft_putchar(' ');
	ft_putnbr(major(file->st_rdev));
	ft_putstr(", ");
	while (min < size.min--)
		ft_putchar(' ');
	ft_putnbr(minor(file->st_rdev));
	ft_putchar(' ');
}
