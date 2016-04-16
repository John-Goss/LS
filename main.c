/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:26:20 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/16 17:04:39 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_valid_opt(char c, char *str)
{
	int	i;

	if (str == NULL || c == '\0')
		return (0);
	i = -1;
	while (str[++i])
		if (c == str[i])
			return (1);
	return (0);
}

static int	is_opt(t_opt *opt, char *str)
{
	if (str && str[0] == '-' && str[1] && !opt->end_opt)
		return (1);
	return (0);
}

static void	parse_opt(t_opt *opt, char *str)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (is_valid_opt(str[i], "1lRGafrtu") || (str[1] == '-' && !str[2]))
		{
			opt->l = (str[i] == 'l' ? 1 : opt->l);
			opt->upper_r = (str[i] == 'R' ? 1 : opt->upper_r);
			opt->a = (str[i] == 'a' ? 1 : opt->a);
			opt->r = (str[i] == 'r' ? 1 : opt->r);
			opt->t = (str[i] == 't' ? 1 : opt->t);
			opt->u = (str[i] == 'u' ? 1 : opt->u);
			opt->f = (str[i] == 'f' ? 1 : opt->f);
			opt->a = (str[i] == 'f' ? 1 : opt->a);
			opt->g = (str[i] == 'G' ? 1 : opt->g);
			opt->l = (str[i] == '1' ? 0 : opt->l);
			opt->end_opt = (str[1] == '-' ? 1 : 0);
		}
		else
			error_opt(str[i]);
	}
}

void		get_param(int ac, char **av, t_opt *opt, t_list **path)
{
	int		i;
	int		type;

	i = -1;
	type = 1;
	while (++i < ac)
	{
		if (is_opt(opt, av[i + 1]) == 0)
			type = 0;
		if (type == 1)
			parse_opt(opt, av[i + 1]);
		else if (type == 0)
			ft_lstpushback(path, av[i + 1], ft_strlen(av[i + 1]) + 1);
	}
}

int			main(int ac, char **av)
{
	t_opt	opt;
	t_list	*path;

	opt = (t_opt){0, 0, 0, 0, 0, 0, 0, 0, 0};
	path = NULL;
	if (ac > 1)
		get_param(ac - 1, av, &opt, &path);
	if (path == NULL)
		path = ft_lstnew(".", ft_strlen("."));
	read_path(opt, path, path->next != NULL ? 1 : 0);
	return (0);
}
