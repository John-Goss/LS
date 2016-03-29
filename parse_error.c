/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:20:06 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/29 17:33:01 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	error(int code)
{
	if (code == 1)
		ft_printf("ERROR : NO ARGUMENTS.\n");
	else if (code == 2)
		ft_printf("ERROR : ILLEGAL OPTION | USE -[lRartufgd]\n");
	return (0);
}
