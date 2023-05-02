#include "push_swap.h"


void	rotate_A(t_stack **stack_A)
{
	rotate(stack_A);
	indexing_stack(*stack_A);	
	write(1, "ra\n", 3);
}

void	rotate_B(t_stack **stack_B)
{
	rotate(stack_B);
	indexing_stack(*stack_B);
	write(1, "rb\n", 3);
}

void	rev_rot_A(t_stack **stack_A)
{
	rev_rot(stack_A);
	indexing_stack(*stack_A);
	write(1, "rra\n", 3);
}

void	rev_rot_B(t_stack **stack_B)
{
	rev_rot(stack_B);
	indexing_stack(*stack_B);
	write(1, "rrb\n", 3);
}

void	swap_A(t_stack **stack_A)
{
	swap(stack_A);
	indexing_stack(*stack_A);
	write(1, "sa\n", 3);
}

void	swap_B(t_stack **stack_B)
{
	swap(stack_B);
	indexing_stack(*stack_B);
	write(1, "sb\n", 3);
}

