/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:26:20 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/04 15:46:15 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_opt(t_strct *opt, t_path *path)
{
	opt->opt_l = 0;
	opt->opt_R = 0;
	opt->opt_a = 0;
	opt->opt_r = 0;
	opt->opt_t = 0;
	opt->opt_u = 0;
	opt->opt_f = 0;
	opt->opt_g = 0;
	opt->opt_d = 0;
	opt->opt_min = 0;
	path->opt = opt;
	path->dpath = NULL;
	path->next = NULL;
	path->dir = NULL;
}

int			main(int ac, char **av)
{
	t_strct	opt;
	t_path	path;
	int		i;

	(void)ac;
	init_opt(&opt, &path);
	i = parse_opt(&opt, av);
	read_path(&path, av, i);
	return (0);
}
