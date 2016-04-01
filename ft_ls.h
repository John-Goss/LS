/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:05:27 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/01 18:56:49 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>

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

int					parse_opt(t_strct *opt, char **av);
int					error(int code, char *str);

#endif
