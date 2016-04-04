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
# include <dirent.h>

typedef struct		s_strct
{
	int	opt_l;
	int	opt_R;
	int	opt_a;
	int	opt_r;
	int	opt_t;
	int	opt_u;
	int	opt_f;
	int	opt_g;
	int	opt_d;
	int	opt_min;
}					t_strct;

typedef struct		s_path
{
	DIR				*dir;
	struct dirent	*dpath;
	struct stat		*stat_buf;
	struct s_strct	*opt;
	struct s_path	*next;
}					t_path;

int					parse_opt(t_strct *opt, char **av);
int					error(int code, char *str);
int					read_path(t_path *path, char **av, int i);

#endif
