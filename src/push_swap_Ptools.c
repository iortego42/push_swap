/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_Ptools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:12:05 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/13 13:02:43 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_A(t_data	*d)
{
	t_stack	*top_b;
	
	top_b = peek(d->B);
	if (top_b  == NULL)
		return ((void)"42Madrid");
	pop(&d->B, NULL);
	d->B_elem--;
	push(&d->A, top_b);
	d->A_elem++;
	indexing_stack(d->A);
	indexing_stack(d->B);
	write(1, "pa\n", 3);
	MOVEMENTS++;
}

void	push_B(t_data	*d)
{
	t_stack *top_a;

	top_a = peek(d->A);
	if (top_a == NULL)	
		return ((void)"42Madrid");
	pop(&d->A, NULL);
	d->A_elem--;
	push(&d->B, top_a);
	d->B_elem++;
	indexing_stack(d->A);
	indexing_stack(d->B);
	write(1, "pb\n", 3);
	MOVEMENTS++;
}

void	swap_AB(t_stack **stack_A , t_stack **stack_B)
{
	swap(stack_A);
	swap(stack_B);
	indexing_stack(*stack_A);
	indexing_stack(*stack_B);
	write(1, "ss\n", 3);
}

void	rotate_AB(t_stack **stack_A, t_stack **stack_B)
{
	rotate(stack_A);
	rotate(stack_B);
	indexing_stack(*stack_A);
	indexing_stack(*stack_B);
	write(1, "rr\n", 3);
}
void	rev_rot_AB(t_stack **stack_A, t_stack **stack_B)
{
	rev_rot(stack_A);
	rev_rot(stack_B);
	indexing_stack(*stack_A);
	indexing_stack(*stack_B);
	write(1, "rrr\n", 3);
}
