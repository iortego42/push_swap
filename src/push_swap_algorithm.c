/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:39 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/06 16:58:45 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

f_action move_selector(int *stacksize, t_stack *element, t_data *d)
{
	f_action	move;

	if (stacksize == &d->A_elem)
	{
		if (((t_content *)element->content)->index > *stacksize / 2)
			move = rotate_A;
		else
			move = rev_rot_A;
	}
	else
	{
		if (((t_content *)element->content)->index > *stacksize / 2)
			move = rotate_B;
		else
			move = rev_rot_B;
	}
	return (move);
}

t_err_code push_chunk(t_data *d, int chunksize, t_stack **stack, t_stack *next)
{	
	t_stack		*top;
	int 		*elem;
	f_action	move;

	if (&d->A == stack)
		elem = &d->A_elem;
	else
		elem = &d->B_elem;
	move = move_selector(elem, next, d);	
	top = peek(*stack);
	while (chunksize-- && *stack != NULL)
	{	
		if (is_pushable(top, ((t_content *)next->content)->order, chunksize))
		{
			if (&d->A == stack)
				push_B(d);
			else if (&d->B == stack)
				push_A(d);
		}
		else
		{
			move(stack);
			top = peek(*stack);
			if (top == NULL)
				return (EMPTY);
		}
	}
	return (OK);
}

t_err_code	push_chunks(t_data *d, int chunksize, t_stack **stack)
{
	t_stack		*next;
	int			*elem, nextind;
	t_err_code	status;

	if (&d->A == stack)
		elem = &d->A_elem;
	else
		elem = &d->B_elem;
	status = OK;
	while (status == OK && *elem)
	{
		// nextind = search_next(d, *stack);
		if (stack == &d->A)
			next = get_min(*stack, *elem);
		else
			next = get_max(*stack, *elem);
		if (next == NULL)
			return (NO_ELEM);
		nextind = ((t_content *)next->content)->index;
		if (nextind == -1)
			return (NO_ELEM);
		next = go_el(*stack, nextind);
		if (next == NULL)
			return (STACK_LINK);
		status = push_chunk(d, chunksize, stack, next);
	}
	return (OK);
}

t_err_code algorithm(t_data *d)
{
	int	chunksize;
	t_err_code	status;

	if (d->argc > 100)
		chunksize = 10;
	else
		chunksize = 6;
	status = push_chunks(d, chunksize, &d->A);
	if (status != OK)
		return (status);
	status = push_chunks(d, chunksize, &d->B);
	if (status != OK)
		return (status);
	
	return (OK);
}
