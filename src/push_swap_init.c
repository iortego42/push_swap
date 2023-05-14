/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:06:28 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/14 20:08:11 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clearlist(char ***list)
{
	int	x;
	int	y;

	x = 0;
	while (list[x] != NULL)
	{
		y = 0;
		while (list[x][y] != NULL)
		{
			free(list[x][y]);
			list[x][y] = NULL;
			y++;
		}
		free(list[x]);
		list[x] = NULL;
		x++;
	}
	free(list);
}

void	init(t_data *d)
{
	d->a = NULL;
	d->b = NULL;
	d->argc = 0;
	d->ordlist = NULL;
	d->toorder = NULL;
	d->sp = NULL;
	d->sec = NULL;
	d->aelem = 0;
	d->belem = 0;
}
