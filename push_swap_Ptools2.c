#include "libft/stack_files/stack.h"
#include "push_swap.h"

void	rotate_A(t_stack **stack_A)
{
	rotate(stack_A);
	write(1, "ra", 2);
}

void	rotate_B(t_stack **stack_B)
{
	rotate(stack_B);
	write(1, "rb", 2);
}

void	rev_rot_A(t_stack **stack_A)
{
	rotate(stack_A);
	write(1, "rra", 2);
}

void	rev_rot_B(t_stack **stack_B)
{
	rotate(stack_B);
	write(1, "rrb", 2);
}

void	swap_A(t_stack **stack_A)
{
	swap(stack_A);
	write(1, "sa", 2);
}

void	swap_B(t_stack **stack_B)
{
	swap(stack_B);
	write(1, "sb", 2);
}

