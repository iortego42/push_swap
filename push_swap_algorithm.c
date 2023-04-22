/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:39 by iortego-          #+#    #+#             */
/*   Updated: 2023/04/22 17:29:40 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

f_action
move_selector(int totalsize, t_stack *element, t_data *d, t_bool isA)
{
	f_action	move;
	t_stack		*top;

	if (isA)
	{
		top = peek(d->A);
		if (((t_content *)element->content)->index > totalsize / 2)
			move = rotate_A;
		else
			move = rev_rot_A;
	}
	else
	{
		top = peek(d->B);
		if (((t_content *)element->content)->index > totalsize / 2)
			move = rotate_B;
		else
			move = rev_rot_B;
	}
	return (move);
}

t_err_code	push_chunks(t_data *d, int chunksize, t_bool isA)
{
	t_stack		*min, *top, **stack, *next;
	f_action	move;
	int			index, *elem;

	stack = &d->A;
	elem = &d->A_elem;
	if (isA != TRUE)
	{
		stack = &d->B;
		elem = &d->B_elem;
	}
	while (*elem)
	{
		next = go_el(*stack, search_next(d, isA));
		if (next == NULL)
			return (NO_ELEM);
		move = move_selector(*elem, next, d, isA);	
		top = peek(*stack);
		while (!is_pushable(top, ((t_content *)next->content)->order, 1))
		{
			move(stack);
			top = peek(*stack);
			if (top == NULL)
				return (EMPTY);
		}
		push_A(d);
	}
	return (OK);
}

t_err_code algorithm(t_data *d)
{
	int	chunksize;
	t_err_code	status;

	if (d->argc > 100)
		chunksize = 20;
	else
		chunksize = 15;
	status = push_chunks(d, chunksize, TRUE);
	if (status != OK)
		return (status);
	status = push_chunks(d, chunksize, FALSE);
	if (status != OK)
		return (status);
	
	return (OK);
}
