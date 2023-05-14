/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_Ptools2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:11:52 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/14 20:13:17 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	indexing_stack(*stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	indexing_stack(*stack_b);
	write(1, "rb\n", 3);
}

void	rev_rot_a(t_stack **stack_a)
{
	rev_rot(stack_a);
	indexing_stack(*stack_a);
	write(1, "rra\n", 4);
}

void	rev_rot_b(t_stack **stack_b)
{
	rev_rot(stack_b);
	indexing_stack(*stack_b);
	write(1, "rrb\n", 4);
}

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	indexing_stack(*stack_a);
	write(1, "sa\n", 3);
}
