/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:20:06 by jle-quer          #+#    #+#             */
/*   Updated: 2016/04/01 18:39:08 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	error(int code, char *str)
{
	if (code == 1)
	{
		ft_printf("ft_ls: illegal option -- %s\n", str);
		ft_printf("usage: ft_ls [-adfglrRtu] [file ...]\n");
	}
	else if (code == 2)
		ft_printf("ft_ls: %s: No such file or directory\n", str);
	exit (-1);
}
