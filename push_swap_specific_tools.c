#include "libft/stack_files/stack.h"
#include "push_swap.h"


t_stack	*go_el(t_stack *stack, int index)
{
	t_stack	*element;

	element = stack;
	while (((t_content *)element->content)->index != index && element->next != NULL)
		element = element->next;
	if (((t_content *)element->content)->index != index)
		return (NULL);
	return (element);
}

void	push_element_n_A(t_stack **stack_A, t_stack **stack_B, int index)
{
	t_stack	*top;

	top = peek(*stack_A);
	while (((t_content *)top->content)->index != index)
	{
		rotate(stack_A);
		top = peek(*stack_A);
	}
	push_A(stack_A, stack_B);
}

void	push_element_n_B(t_stack **stack_A, t_stack **stack_B, int index)
{
	t_stack	*top;

	top = peek(*stack_B);
	while (((t_content *)top->content)->index != index)
	{
		rotate(stack_B);
		top = peek(*stack_B);
	}
	push_B(stack_A, stack_B);
}

void	ordernating(t_stack **stack_A, t_stack **stack_B)
{
	int		max, min, count;
	t_stack	*actual;

	count = 0;
	min = 0;
	max = 0;
	actual = *stack_A;
	while (actual->next != NULL)
	{
		actual = go_el(*stack_A, count);
		if (((t_content *)actual->content)->number > max)
		{
			max = ((t_content *)actual->content)->number;
			
		}
		if (((t_content *)actual->content)->number < min)
		{
			min = ((t_content *)actual->content)->number;
		}
		count++;
	}
}
t_bool	is_top_ordered(t_stack *stack)
{
	t_stack	*top;

	top = peek(stack);
	while (((t_content *)stack->content)->number > \
			((t_content *)top->content)->number)
		stack = stack->next;
	if (stack == top)
		return (TRUE);
	return (FALSE);
}
void	whoami(t_stack *stack, t_stack *element)
{
	while (stack->next != NULL)
	{
		if (((t_content *)stack->content)->order != 0)
			if (((t_content *)stack->content)->number > \
				((t_content *)element->content)->number) && \
				((t_content *)stack->content)->index < )
				
	}
}
void	push_lowers_B(t_stack **stack_A, t_stack **stack_B, int numvalues, \
		int halfvalue)
{
	t_stack	*top;
	top = peek(*stack_A);
	while (numvalues > 0)
	{
		if (((t_content *)top->content)->number <= halfvalue)
		{
			if (((t_content *)top->content)->number <=)	
		}
	}
}
