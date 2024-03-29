/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_processing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:12:18 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/19 18:40:33 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_min(t_stack *stack, int stacksize)
{
	t_stack	*min;
	int		steps;

	min = stack;
	steps = stacksize;
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL && steps > 0)
	{
		if (((t_content *)stack->content)->order
			> ((t_content *)min->content)->order)
			min = stack;
		stack = stack->next;
		steps--;
	}
	while (stack->prev != NULL && steps > 0)
	{
		if (min == NULL || ((t_content *)stack->content)->order
			> ((t_content *)min->content)->order)
			min = stack;
		stack = stack->prev;
		steps--;
	}
	return (min);
}

t_stack	*get_max(t_stack *stack, int stacksize)
{
	t_stack	*max;
	int		steps;

	max = stack;
	steps = stacksize;
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL && steps > 0)
	{
		if (((t_content *)stack->content)->order
			< ((t_content *)max->content)->order)
			max = stack;
		stack = stack->next;
		steps--;
	}
	while (stack->prev != NULL && steps > 0)
	{
		if (max == NULL || ((t_content *)stack->content)->order
			< ((t_content *)max->content)->order)
			max = stack;
		stack = stack->prev;
		steps--;
	}
	return (max);
}

void	indexing_stack(t_stack *stack)
{
	int	index;

	index = 0;
	if (stack == NULL)
		return ((void)"42Madrid");
	while (stack != NULL)
	{
		if (((t_content *)stack->content)->index != index)
			((t_content *)stack->content)->index = index;
		stack = stack->next;
		index++;
	}
}

t_content	*create_content(int number, int ordind, int index)
{
	t_content	*new_content;

	new_content = malloc(sizeof(t_content));
	if (new_content != NULL)
	{
		new_content->number = number;
		new_content->index = index;
		new_content->order = ordind;
	}
	return (new_content);
}

t_err_code	charge_stack_a(t_data *d)
{
	int			ordind;
	t_content	*new_elem_content;
	t_stack		*element;

	while (d->aelem < d->argc)
	{
		ordind = 0;
		while (d->ordlist[ordind] != d->toorder[d->aelem])
			ordind++;
		new_elem_content
			= create_content(d->toorder[d->aelem], ordind, d->aelem);
		if (new_elem_content == NULL)
		{
			if (d->a != NULL)
				delete_stack(&d->a, delete_content);
			return (EC_CONTENT);
		}
		element = new_stack_element(new_elem_content);
		if (element == NULL)
			return (EC_MALLOC);
		push(&d->a, element);
		d->aelem++;
	}
	return (OK);
}
