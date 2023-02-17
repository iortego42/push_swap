#include "push_swap.h"

void	push_n6_B(t_data **d)
{
	t_stack *min;
	

	min = go_el((*d)->A, (*d)->min->index);
	while((*d)->A != min)
	{
		if (((t_content *)(*d)->A->content)->number < (*d)->max->number)
			push_A(&(*d)->A, &(*d)->B);
		rotate(&(*d)->A);
	}
}

t_bool 	is_ordered(t_stack *stack)
{
	if (((t_content *)stack->content)->number < \
			((t_content *)stack->next->content)->number)
		return (FALSE);
	return (TRUE);
}

void	pushordered(t_data **d)
{
	int	size, i, orate;

	size = 6;
	orate = get_rate_order((*d)->toorder, 6, );
	while (size > 0)
	{
		if (is_ordered((*d)->B))
		{
			i = 2;
			while (i-- > 0)
				push_B(&(*d)->A, &(*d)->B);
			size--;
		}
		size--;
	}
}
