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

t
