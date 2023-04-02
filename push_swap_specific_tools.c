#include "push_swap.h"

t_stack	*go_el(t_stack *stack, int index)
{
	t_stack	*element;

	element = stack;
	while (((t_content *)element->content)->index != index && \
			element->next != NULL)
		element = element->next;
	if (((t_content *)element->content)->index != index)
		return (NULL);
	return (element);
}

t_stack *go_el_v(t_stack *stack, int value)
{
	t_stack *element;

	element = stack;
	while (((t_content *)element->content)->number != value && \
			element->next != NULL)
		element = element->next;
	if (((t_content *)element->content)->number != value)
		return (NULL);
	return (element);
}

t_bool 	is_ordered(t_stack *stack)
{
	if (((t_content *)stack->content)->number < 
			((t_content *)stack->next->content)->number)
		return (FALSE);
	return (TRUE);
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

t_bool	is_pushable(t_stack *top, int ordindex, int chunksize)
{
	if (((t_content *)top->content)->order < ordindex + chunksize)
		return TRUE;
	else
		return FALSE;
}
