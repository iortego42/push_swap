#include "libft/stack_files/stack.h"
#include "push_swap.h"

t_content	*create_content(int number, int index)
{
	t_content *new_content;

	new_content = malloc(sizeof(t_content));
	if (new_content != NULL)
	{
		new_content->number = number;
		new_content->index = index;
		new_content->order = 0;
	}
	return (new_content);
}

t_stack	*charge_stack_A(int	*numberlist, int argc)
{
	int	index;
	t_stack *stack;
	t_content *new_element_content;
	
	stack = NULL;
	index = 0;
	while (index < argc)
	{
		new_element_content = create_content(numberlist[index], index);
		if (new_element_content == NULL)
		{
			if (stack != NULL)
				delete_stack(&stack, delete_content);	
			return (NULL);
		}
		if (stack == NULL)
			stack = new_stack_element(new_element_content);
		else
			stack->next = new_stack_element(new_element_content);
	}
	return (stack);
}

void	analizeInput(int *numberlist)
{
	
}
