/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:05:27 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/04 15:58:59 by jle-quer         ###   ########.fr       */
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
	int				groupspace;
	int				linkspace;
	int				min;
	int				maj;
}					t_size;

void				parse_opt(t_opt *opt, char *str);
void				error_opt(char opt);
void				error_path(char *name, char *error, int ex);
void				get_param(int ac, char **av, t_opt *opt, t_list **path);

#endif
