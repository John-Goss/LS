/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:05:27 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/15 14:57:37 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <errno.h>

# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"

# define BUFF_SIZE 256

typedef struct		s_opt
{
	int				l;
	int				upper_r;
	int				a;
	int				r;
	int				t;
	int				u;
	int				f;
	int				g;
	int				end_opt;
}					t_opt;

typedef struct		s_elem
{
	char			*name;
	char			*path;
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	quad_t			st_blocks;
	dev_t			st_rdev;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_size
{
	int				total;
	int				size;
	int				userspace;
	int				groupspace;
	int				linkspace;
	int				min;
	int				maj;
}					t_size;

void				error_opt(char opt);
void				error_path(char *name, char *error, int ex);
void				get_param(int ac, char **av, t_opt *opt, t_list **path);
void				read_path(t_opt opt, t_list *path, int multidir);
void				ls_file(t_opt opt, t_list *path);
void				ls_dir(t_opt opt, t_list *path, int multidir);
void				ls_dir_open(t_opt opt, t_elem *dir_list, int multidir);
void				display_file(t_opt opt, t_elem *file, int type);
void				elemgetfiles(t_elem **files, char *name,
					char *path, t_opt opt);
int					elemget(t_elem **files, struct dirent *file,
					char *pa, t_opt op);
int					cmp_alpha(t_elem *elem1, t_elem *elem2);
int					cmp_time(t_elem *elem1, t_elem *elem2);
void				ls_basic(t_opt opt, t_elem *files);
void				ls_all_info(t_opt opt, t_elem *cur, t_size size);
void				ls_long(t_opt opt, t_elem *files, int type);
void				print_user_access(t_elem *elem);
void				print_int(t_size size, int nlink, int spacemax, int type);
void				print_str(char *str, int spacemax);
void				print_majmin(t_elem *file, t_size size);
void				display_date(time_t date);
t_size				get_size(t_opt opt, t_elem *files);
t_elem				*sort_elem(t_elem *list, t_opt opt);
void				recursion(t_opt opt, t_elem *files);
void				display_link(t_elem *cur);

#endif
