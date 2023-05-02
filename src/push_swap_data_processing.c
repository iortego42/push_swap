/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_processing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:12:18 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:01 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_min(t_stack	*stack, int	totalsize)
{
	t_stack	*min;
	int	steps;

	min = stack;
	steps = totalsize;

	while (stack->next != NULL && steps > 0)
	{
		if (((t_content *)stack->content)->index < 
				((t_content *)min->content)->index)
			min = stack;
		stack = stack->next;
		steps--;
	}
	if (steps == totalsize && stack->next == NULL)
		while (stack->prev != NULL && steps > 0)
		{
			if (min == NULL || ((t_content *)stack->content)->index <
					((t_content *)min->content)->index)
				min = stack;
			stack = stack->prev;
			steps--;
		}
	return (min);
}

void	get_mmm(t_data *d, int size)
{
	int	i;

	i = 0;
	if (d->min == NULL)
	{
		d->min = (t_content *)go_el_v(d->A, d->ordlist[0])->content;
		d->max = (t_content *)go_el_v(d->A, d->ordlist[size])->content;
	}
	else
	{
		while (d->ordlist[i] != d->min->number)
			i++;
		d->min = (t_content *)go_el_v(d->A, d->ordlist[i])->content;
		d->max = (t_content *)go_el_v(d->A, d->ordlist[i + size])->content;
	}
}

void	indexing_stack(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack->next != NULL)
	{
		if (((t_content *)stack->content)->index != index)
			((t_content *)stack->content)->index = index;
		stack = stack->next;
		index++;
	}
}

t_content	*create_content(int number, int ordind ,int index)
{
	t_content *new_content;

	new_content = malloc(sizeof(t_content));
	if (new_content != NULL)
	{
		new_content->number = number;
		new_content->index = index;
		new_content->order = ordind;
	}
	return (new_content);
}

t_err_code charge_stack_A(t_data *d)
{
	int			ordind;
	t_content	*new_elem_content;
	t_stack		*element;

	d->A = NULL;
	d->A_elem = 0;
	while (d->A_elem < d->argc)
	{
		ordind = 0;
		while (d->ordlist[ordind] != d->toorder[d->A_elem])
			ordind++;
		new_elem_content = create_content(d->toorder[d->A_elem], ordind, d->A_elem);
		if (new_elem_content == NULL)
		{
			if (d->A != NULL)
				delete_stack(&d->A, delete_content);	
			return (CONTENT);
		}
		element = new_stack_element(new_elem_content);
		if (element == NULL)
			return (ELEMENT);
		push(&d->A, element);
		d->A_elem++;
	}
	return (OK);
}