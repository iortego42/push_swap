/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:39 by iortego-          #+#    #+#             */
/*   Updated: 2023/04/21 18:40:03 by iortego-         ###   ########.fr       */
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

void	push_chunk_B(t_data *d, int chunksize)
{
	t_stack		*min, *top;
	f_action	funct;
	int			elements;

	min = get_min(d->A, d->A_elem);
	funct = move_selector(d->A_elem, min, d, TRUE);
	top = NULL;
	while(top != min || (elements % chunksize) != 0)
	{
		top = peek(d->A);
		if(is_pushable(top, ((t_content *)min->content)->order, chunksize))
		{
			push_B(d);
			elements++;
		}
		else
			funct(&d->A);
	}
}
void	push_chunks(t_data *d, int chunksize, t_bool isA)
{
	t_stack		*min, *top, **stack, *next;
	f_action	move;
	int			index, *elem;

	if (isA == TRUE)
		stack = &d->A;
	else
		stack = &d->B;
	if (isA == TRUE)
		elem = &d->A_elem;
	else
		elem = &d->B_elem;
	min = get_min(*stack, *elem);
	while (*elem)
	{
		next = go_el(*stack, search_next(d, chunksize, isA));
		move = move_selector(*elem, next, d, isA);	
		top = peek(*stack);
		while (TRUE !=
		is_pushable(top, ((t_content *)next->content)->order, 1))
		{
			move(stack);
			top = peek(*stack);
		}
		push_A(d);
	}
}

void	push_chunks_A(t_data *d, int chunksize)
{
	f_action	move;
	t_stack		*top, *next;
	int			index, t;

	while (d->B_elem)
	{
		next = go_el(d->B, search_next(d, chunksize, FALSE));
		move = move_selector(d->B_elem, next, d, FALSE);
		top = peek(d->B);
		while (TRUE != 
		is_pushable(top, ((t_content *)next->content)->order, 1))
		{
			move(&d->B);
			top = peek(d->B);
		}
		push_A(d);
	}
}

t_err_code algorithm(t_data *d)
{
	int
	return (OK);
}
