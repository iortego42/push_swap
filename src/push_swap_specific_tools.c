/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_specific_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:12:00 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/13 13:03:40 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_stack *go_el_v(t_stack *stack, int value)
{
	t_stack *element;

	element = stack;
	while (((t_content *)element->content)->number != value && \
			element->next != NULL)
		element = element->next;
	if (((t_content *)element->content)->number != value)
		return (NULL);
	return (element);
}

t_bool 	is_ordered(t_stack *stack)
{
	if (((t_content *)stack->content)->number < 
			((t_content *)stack->next->content)->number)
		return (FALSE);
	return (TRUE);
}

int	search_next(t_data *d, t_stack *stack)
{
	t_stack	*top;
	int		elem, ordindex;

	if (d->A == stack)
		elem = d->A_elem;
	else if (d->B == stack) 
		elem = d->B_elem;
	top = peek(stack);
	if (top == NULL)
		return (((t_content *)get_min(stack, elem)->content)->index);
	ordindex = ((t_content *)top->content)->order + 1;
	while (stack != NULL && ((t_content *)stack->content)->order != ordindex)
		stack = stack->next;
	if (stack == NULL)
		return (-1);
	return (((t_content *)stack->content)->index);
}

t_bool	is_pushable(t_stack *top, int ordindex, int chunksize, 
		t_data *d, int *elem)
{
	if (elem == &d->A_elem)
	{
		if (((t_content *)top->content)->order < ordindex + chunksize)
			return TRUE;
		else
			return FALSE;
	}
	else
	{
		if (((t_content *)top->content)->order == ordindex)
			return TRUE;
		else
			return FALSE;

	}
}
