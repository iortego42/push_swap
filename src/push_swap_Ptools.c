/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_Ptools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:11:32 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/14 20:43:36 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data	*d)
{
	t_stack	*top_b;

	top_b = peek(d->b);
	if (top_b == NULL)
		return ((void)"42Madrid");
	pop(&d->b, NULL);
	d->belem--;
	push(&d->a, top_b);
	d->aelem++;
	indexing_stack(d->a);
	indexing_stack(d->b);
	write(1, "pa\n", 3);
}

void	push_b(t_data	*d)
{
	t_stack	*top_a;

	top_a = peek(d->a);
	if (top_a == NULL)
		return ((void)"42Madrid");
	pop(&d->a, NULL);
	d->aelem--;
	push(&d->b, top_a);
	d->belem++;
	indexing_stack(d->a);
	indexing_stack(d->b);
	write(1, "pb\n", 3);
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	indexing_stack(*stack_b);
	write(1, "sb\n", 3);
}
