/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:23:52 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/29 17:45:43 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	put_opt_on(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] != 'l' || str[i] != 'R' || str[i] != 'a' || str[i] != 'r'
				|| str[i] != 't' || str[i] != 'u' || str[i] != 'f'
				|| str[i] != 'g' || str[i] != 'd')
			return (-1);
	}
}

int			parse_opt(int ac, char **av)
{
	int	i;

	i = 0;
	while (av[i++][0])
	{
		if (av[i][0] != '-')
			return (-1);
		if (put_opt_on(av[i] + 1) == -1)
			return (-1);
	}
}
