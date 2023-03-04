#include "push_swap.h"

void	push_chunk_B(t_data *d, int size)
{
	t_stack		*min, *top;
	f_action	funct;
	int			elements;

	elements = 0;
	min = get_min(d->A, size);
	if (((t_content *)min->content)->index > d->A_elem / 2)
		funct = rotate_A;
	else
		funct = rev_rot_A;
	while(d->A != min || (elements % size) != 0)
	{
		top = peek(d->A);
		if (((t_content *)top->content)->index < \
				((t_content *)min->content)->index + size)
		{
			push_B(&d->A, &d->B);
			d->A_elem--;
			elements++;
		}
		else
			funct(&d->A);
	}
}


void	search_next(t_stack	**stack, int index)
{
	while ((*stack)->next != NULL)		
	{
		if ()	
	}	
}
void	push_chunks_A(t_data *d, int size)
{
	f_action	move;
	t_stack		*top;
	int			index, step;

	step = size;
	top = peek(d->B);
	while (d->B != NULL)
	{
		
	}
}

t_bool 	is_ordered(t_stack *stack)
{
	if (((t_content *)stack->content)->number < \
			((t_content *)stack->next->content)->number)
		return (FALSE);
	return (TRUE);
}
