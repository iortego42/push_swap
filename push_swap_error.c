#include "libft/stack_files/stack.h"
#include "push_swap.h"

void	delete_content(void *content)
{

	free(content);
	content = NULL;
}

void	delete_stack(t_stack **stack)
{
	while ()
	{
		pop(stack, *delete_content);
	}
}
