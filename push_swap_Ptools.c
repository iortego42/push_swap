#include "libft/stack_files/stack.h"
#include "push_swap.h"

void	push_A(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*top_b;
	
	top_b = peek(*stack_B);
	push(stack_A, top_b);
	pop(*stack_B, delete_content);
}

void	push_B(t_stack **stack_A, t_stack **stack_B)
{
	t_stack *top_a;

	top_a = peek(*stack_A);
	push(stack_B, top_a);
	pop(*stack_A, delete_content);
}

void	swap_AB(t_stack **stack_A , t_stack **stack_B)
{
	swap(stack_A);
	swap(stack_B);
}
void	rotate_AB(t_stack **stack_A, t_stack **stack_B)
{
	rotate(stack_A);
	rotate(stack_B);
}
void	rev_rot_AB(t_stack **stack_A, t_stack **stack_B)
{
	rev_rot(stack_A);
	rev_rot(stack_B);
}
