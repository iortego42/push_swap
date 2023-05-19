/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_specific_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:12:00 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/19 19:08:43 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*go_el(t_stack *stack, int index)
{
	t_stack	*element;

	element = stack;
	while (((t_content *)element->content)->index != index && \
			element->next != NULL)
		element = element->next;
	if (((t_content *)element->content)->index != index)
		return (NULL);
	return (element);
}

t_stack	*go_el_v(t_stack *stack, int value)
{
	t_stack	*element;

	element = stack;
	while (((t_content *)element->content)->number != value && \
			element->next != NULL)
		element = element->next;
	if (((t_content *)element->content)->number != value)
		return (NULL);
	return (element);
}

t_bool	check_number(const char *number, t_data *d)
{
	int			y;
	long long	n;

	y = 0;
	while (number[y] != 0)
	{
		if (!ft_isdigit(number[y]) && !ft_isspace(number[y]) 
			&& number[y] != '-' && number[y] != '+' 
			&& !ft_isdigit(number[y + 1]))
			return (FALSE);
		y++;
	}
	y = 0;
	while (number[y] != 0)
	{
		while (ft_isspace(number[y]))
			y++;
		n = ft_atoi(&number[y]);
		if (n == 0 && number[y] != '0' && number[y] != 0)
			return (FALSE);
		while (ft_isdigit(number[y]) || number[y] == '-' || number[y] == '+')
			y++;
		d->argc++;
	}
	return (TRUE);
}

t_bool	is_ordered(int *list, int argc)
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		if (list[index] < list[index + 1])
			return (FALSE);
		index++;
	}
	return (TRUE);
}

t_bool	is_pushable(t_stack *top, int ordindex, t_data *d)
{
	if (d->chunksize != 0)
	{
		if (ordindex - ((t_content *)top->content)->order < d->chunksize)
			return (TRUE);
		else
			return (FALSE);
	}
	else
	{
		if (((t_content *)top->content)->order == ordindex)
			return (TRUE);
		else
			return (FALSE);
	}
}
