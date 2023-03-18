#include "push_swap.h"

t_bool	is_pushable(t_data *d, int ordindex, int size, t_bool isA)
{
	t_stack	*top;
	
	if (isA)
		top = peek(d->A);
	else
		top = peek(d->B);
	if (((t_content *)top->content)->order < ordindex + size)
		return TRUE;
	else
		return FALSE;
}

f_action	move_selector(int totalsize, t_stack *element, t_data *d)
{
	f_action	move;
	t_stack		*top;
	t_bool		isA;

	if (totalsize == d->A_elem)
		isA = TRUE;
	else
		isA = FALSE;
	if (isA)
	{
		top = peek(d->A);
		if (((t_content *)element->content)->index > totalsize / 2)
			move = rotate_A;
		else
			move = rev_rot_A;
	}
	else
	{
		top = peek(d->B);
		if (((t_content *)element->content)->index > totalsize / 2)
			move = rotate_B;
		else
			move = rev_rot_B;
	}
	return (move);
}

void	push_chunk_B(t_data *d, int size)
{
	t_stack		*min, *top;
	f_action	funct;
	int			elements;

	min = get_min(d->A, size);
	funct = move_selector(d->A_elem, min, d);
	elements = is_pushable(d, ((t_content *)min->content)->order, size, TRUE);	
	while(top != min || (elements % size) != 0)
	{
		top = peek(d->A);
		if(is_pushable(d, ((t_content *)min->content)->order, size, TRUE))
		{
			push_B(d);
			elements++;
		}
		else
			funct(&d->A);
	}
}

void	move_n_A(t_data	*d, int	index)
{
	f_action	fun;
	t_stack		*next;

	fun = rev_rot_A;
	next = go_el(d->A, index);
	if (next == NULL)
		return ((void)"42madrid");
	fun = move_selector(d->A_elem, next, d);
	next = peek(d->A);
	while(((t_content *)next->content)->order != index)
	{
		fun(&d->A);
		next = peek(d->A);
	}
}

int	search_next(t_data *d, int chunksize)
{
	t_stack	*top, *stack;
	int		pos, next_v, ordindex;

	stack = d->B;
	top = peek(d->A);
	if (top == NULL)
		return (-1);
	ordindex = ((t_content *)top->content)->order + 1;
	while (((t_content *)stack->content)->order != ordindex)
		stack = stack->next;
	if (((t_content *)stack->content)->index <= d->B_elem - chunksize)
		return (-1);
	return (((t_content *)stack->content)->index);
}



void	push_chunks_A(t_data *d, int chunksize)
{
	f_action	move;
	t_stack		*top, *next;
	int			index, t;

	while (d->B_elem)
	{
		next = go_el(d->B, search_next(d, chunksize));
		move = move_selector(d->B_elem, next, d);
		while (TRUE != \
		is_pushable(d, ((t_content *)next->content)->order, d->B_elem, FALSE))
			move(&d->B);
		push_A(d);
	}
}

t_bool 	is_ordered(t_stack *stack)
{
	if (((t_content *)stack->content)->number < \
			((t_content *)stack->next->content)->number)
		return (FALSE);
	return (TRUE);
}
