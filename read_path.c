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

static t_path	*add_list_path(t_path *path, t_strct *opt)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->dpath = NULL;
	new->opt = opt;
	new->next = path->next;
	path->next = new;
	new->dir = NULL;
	return (new);
}

int				read_path(t_path *path, char **av, int i)
{
	t_path	*new;

	new = add_list_path(path, path->opt);
	while (av[i])
	{
		new->dir = opendir(av[i]);
		if (new->dir == NULL)
			return (error(2, av[i]));
		while ((new->dpath = readdir(new->dir)) != NULL)
		{
			ft_printf("Argv : %d --- %s\n", i, new->dpath->d_name);
			if (strcmp(new->dpath->d_name, av[i]) == 0)
				(void)closedir(new->dir);
		}
		new->next = add_list_path(path, path->opt);
		new = new->next;
		i++;
	}
	return (0);
}
