/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:23:52 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/04 14:01:11 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	unvalid_opt(char *str, char *opt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (opt[j])
		{
			if (opt[j] == str[i])
				break ;
			j++;
		}
		if (j == ft_strlen(opt))
			return (i + 1);
		i++;
	}
	return (0);
}

static int	put_opt_on(t_strct *opt, char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'l')
			opt->opt_l = 1;
		else if (str[i] == 'R')
			opt->opt_R = 1;
		else if (str[i] == 'a')
			opt->opt_a = 1;
		else if (str[i] == 'r')
			opt->opt_r = 1;
		else if (str[i] == 't')
			opt->opt_t = 1;
		else if (str[i] == 'u')
			opt->opt_u = 1;
		else if (str[i] == 'f')
			opt->opt_f = 1;
		else if (str[i] == 'g')
			opt->opt_g = 1;
		else if (str[i] == 'd')
			opt->opt_d = 1;
		else if (str[i] == '-' && str[i - 1] == '-')
		{
			if (opt->opt_min == 1)
				return (-1);
			opt->opt_min = 1;
		}
		else
			return (-1);
		i++;
	}
	return (0);
}

int			parse_opt(t_strct *opt, char **av)
{
	int	i;

	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		if (opt->opt_min == 1)
			return (error(2, av[i]));
		if (put_opt_on(opt, av[i]) == -1)
			return (error(1, av[i] + (unvalid_opt(av[i] + 1, "lRartufgd"))));
		i++;
	}
	return (i);
}
