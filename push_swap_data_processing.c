#include "push_swap.h"

void	get_mmm(t_data *d, int size)
{
	static int index;
	
	index = 0;
	index += size;
	if (index + size > d->argc)
		size = d->argc - index;
	d->max = d->ordlist[index];
	d->min = d->ordlist[index];
	while (size > 1)
	{
		if (d->max->number < d->ordlist[index])
			d->max = (t_content *)go_el_v(d->A, d->ordlist[index])->content;
		else if (d->min->number > d->ordlist[index])
			d->min = (t_content *)go_el_v(d->A, d->ordlist[index])->content;
	}
}

t_content	*create_content(int number, int index, int *orderedlist)
{
	t_content *new_content;

	new_content = malloc(sizeof(t_content));
	if (new_content != NULL)
	{
		new_content->number = number;
		new_content->index = index;
		new_content->order = get_rate_order(&number, 1, orderedlist);
	}
	return (new_content);
}

t_bool	*charge_stack_A(int	*numberlist, int argc, int *orderedlist)
{
	int			index;
	t_stack		*stack;
	t_content	*new_element_content;
	 
	stack = NULL;
	index = 0;
	while (index < argc)
	{
		new_element_content = create_content(numberlist[index], index, orderedlist);
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
