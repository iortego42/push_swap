/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:39 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/13 16:48:56 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

f_action move_selector(int *stacksize, t_stack *element, t_data *d)
{
	f_action	move;

	if (stacksize == &d->A_elem)
	{
		if (((t_content *)element->content)->index > *stacksize / 2)
			move = rev_rot_A;
		else
			move = rotate_A;
	}
	else
	{
		if (((t_content *)element->content)->index > *stacksize / 2)
			move = rev_rot_B;
		else
			move = rotate_B;
	}
	return (move);
}

t_err_code push_chunk(t_data *d, int chunksize, t_stack **stack, t_stack *next)
{	
	t_stack		*top;
	int 		*elem, step;
	f_action	move;

	if (&d->A == stack)
		elem = &d->A_elem;
	else
		elem = &d->B_elem;
	move = move_selector(elem, next, d);	
	top = peek(*stack);
	step = chunksize;
	while ((step > 0 || (step == 0  && 0 == chunksize)) && *stack != NULL)
	{	
		if (TRUE == is_pushable(top, ((t_content *)next->content)->order,
		chunksize, d, elem))
		{
			if (&d->A == stack)
				push_B(d);
			else if (&d->B == stack)
				push_A(d);
			step--;
		}
		else
			move(stack);
		top = peek(*stack);
		if (top == NULL && *elem != 0)
			return (EMPTY);
	}
	return (OK);
}

t_err_code	push_chunks(t_data *d, int chunksize, t_stack **stack)
{
	t_stack		*next;
	int			*elem;
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
			return (STACK_LINK);
		status = push_chunk(d, chunksize, stack, next);
	}
	return (status);
}

t_err_code algorithm(t_data *d)
{
	int	chunksize;
	t_err_code	status;

	if (d->argc <= 100)
		chunksize = d->argc / 4;
	else
		chunksize = d->argc / 12;
	status = push_chunks(d, chunksize, &d->A);
	if (status != OK)
		return (status);
	status = push_chunks(d, 0, &d->B);
	if (status != OK)
		return (status);
	
	return (OK);
}
