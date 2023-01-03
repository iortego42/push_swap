#include "libft/stack_files/stack.h"
#include "push_swap.h"

void	delete_content(void *content)
{
	free(content);
	content = NULL;
}

