#include "push_swap.h"

void	push_n6_B(t_data **d)
{
	t_stack		*min;
	f_action	funct;
	int			elements;

	elements = 0;
	min = go_el((*d)->A, (*d)->min->index);
	if ((*d)->min->index > (*d)->A_elem / 2)
		funct = rotate;
	else
		funct = rev_rot;
	while((*d)->A != min || (elements % 6) != 0)
	{
		if (((t_content *)(*d)->A->content)->number < (*d)->max->number)
		{
			push_B(&(*d)->A, &(*d)->B);
			(*d)->A_elem--;
			elements++;
		}
		else
			funct(&(*d)->A);
	}
}

void	ordering_A(t_data *d)
{
	
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
	;
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
