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

void	push_chunk_A(t_data *d, int size)
{
	f_action	move;
	t_stack		*top;
	int			index, step;

	top = peek(d->B);
	step = size;
	index = ((t_content *)top->content)->index;
	if (((t_content *)top->content)->index < \
			((t_content *)d->B->content)->index)
	{
		move = rev_rot;
		index = ((t_content *)d->B)->index
	}
	else
		move = rotate;
	while (index < size - 1)
	{
		if (((t_content *)top->content)->index != index)
		move(&d->B);
	}
	
}

void	ordering_to_A(t_data *d)
{
	int	index;
	t_stack *actual;

	index = 0;
	while (index < d->argc)	
	{
		while (d->ordlist[index] != ((t_content *)actual->content)->number)
		{
				
		}	
	}
}

t_bool 	is_ordered(t_stack *stack)
{
	if (((t_content *)stack->content)->number < \
			((t_content *)stack->next->content)->number)
		return (FALSE);
	return (TRUE);
}
