/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_specific_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:12:00 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/14 20:18:53 by iortego-         ###   ########.fr       */
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

t_bool	is_ordered(t_stack *stack)
{
	if (((t_content *)stack->content)->number
		< ((t_content *)stack->next->content)->number)
		return (FALSE);
	return (TRUE);
}

t_bool	is_pushable(t_stack *top, int ordindex, t_data *d)
{
	if (d->sec == &d->aelem)
	{
		if (((t_content *)top->content)->order < ordindex + d->chunksize)
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
