/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_order_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:30:39 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/15 20:08:56 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_min_top(t_data *d)
{
	rotate_a(&d->a);
	swap_a(&d->a);
	rev_rot_a(&d->a);
}

void	case_min_mid(t_data *d)
{
	t_stack	*min;

	min = get_min(d->a, d->aelem);
	if (((t_content *)min->prev->content)->number
		< ((t_content *)min->next->content)->number)
		rotate_a(&d->a);
	else
		swap_a(&d->a);
}

void	case_min_bot(t_data *d)
{
	t_stack	*min;
	t_stack	*top;

	min = get_min(d->a, d->aelem);
	top = peek(d->a);
	if (((t_content *)top->content)->number
		> ((t_content *)top->prev->content)->number)
		swap_a(&d->a);
	rev_rot_a(&d->a);
}

void	order_3(t_data *d)
{
	t_stack	*min;
	t_stack	*top;

	top = peek(d->a);
	min = get_min(d->a, d->aelem);
	if (((t_content *)min->content)->index == 0)
		case_min_bot(d);
	else if (((t_content *)min->content)->index == 1)
		case_min_mid(d);
	else
		case_min_top(d);
}

void	order_5(t_data *d)
{
	t_stack		*min;
	t_action	move;

	d->chunksize = 0;
	d->sec = &d->aelem;
	d->sp = &d->a;
	while (d->aelem > 3)
	{
		min = get_min(d->a, d->aelem);
		move = move_selector(min, d);
		push_chunk(push_b, move, d, min);
	}
	min = get_min(d->a, d->aelem);
	if (min == peek(d->a) && ((t_content *)min->prev->content)->order
		== ((t_content *)min->content)->order - 1)
		;
	else
		order_3(d);
	while (d->belem > 0)
		push_a(d);
}
