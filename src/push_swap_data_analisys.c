/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_analisys.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:47:30 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/15 20:19:50 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_bool	check_numbers(char	**argv, t_data *d)
{
	int	x;

	x = 1;
	while (argv[x] != NULL)
	{
		if (FALSE == check_number(argv[x], d))
			return (FALSE);
		x++;
	}
	return (TRUE);
}

char	***args_split(char **argv, int argc)
{
	char	***list;
	int		index;

	index = 0;
	list = (char ***) malloc(sizeof(char **) * argc);
	if (list == NULL)
		return (NULL);
	list[argc - 1] = NULL;
	while (argc > 1 + index)
	{
		list[index] = ft_split(argv[index + 1], ' ');
		if (list[index] == NULL || *list[index] == NULL)
			return (clearlist(list), NULL);
		index++;
	}
	return (list);
}

t_bool	get_toorder(char	***list, t_data	*d)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	x = 0;
	d->toorder = (int *)malloc(sizeof(int) * d->argc);
	if (d->toorder == NULL)
		return (FALSE);
	while (list[x + 1] != NULL)
		x++;
	while (x >= 0)
	{
		y = 0;
		while (list[x][y + 1] != NULL)
			y++;
		while (y >= 0)
		{
			d->toorder[index] = ft_atoi(list[x][y]);
			index++;
			y--;
		}
		x--;
	}
	return (clearlist(list), TRUE);
}

t_bool	get_ordered_list(t_data *d)
{
	int	index;
	int	auxc;

	ft_memcpy(d->ordlist, d->toorder, sizeof(int) * d->argc);
	index = 1;
	while (d->argc > index)
	{
		auxc = index;
		if (d->ordlist[index] == d->ordlist[index - 1])
			return (FALSE);
		while (auxc > 0 && d->ordlist[auxc] > d->ordlist[auxc - 1])
		{
			ft_switch_int_values(&d->ordlist[auxc], &d->ordlist[auxc - 1]);
			auxc--;
		}
		if (auxc > 0 && d->ordlist[auxc] == d->ordlist[auxc - 1])
			return (FALSE);
		index++;
	}
	return (TRUE);
}

t_err_code	analize_input(char **argv, int argc, t_data *d)
{
	char	***list;

	if (check_numbers(argv, d) != TRUE)
		return (INPUT);
	list = args_split(argv, argc);
	if (list == NULL)
		return (MALLOC);
	if (get_toorder(list, d) != TRUE)
		return (MALLOC);
	if (d->argc < 2)
		return (INPUT);
	d->ordlist = (int *) malloc(d->argc * sizeof(int));
	if (d->ordlist == NULL)
		return (MALLOC);
	if (get_ordered_list(d) != TRUE)
		return (ORDER);
	if (is_ordered(d->toorder, d->argc) == TRUE)
		return (INPUT);
	return (OK);
}
