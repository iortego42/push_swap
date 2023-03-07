#include "push_swap.h"

t_stack	*get_min(t_stack	*stack, int	size)
{
	t_stack	*min;
	int	steps;

	min = NULL;
	steps = size;

	while (stack->next != NULL && steps > 0)
	{
		if (min == NULL || ((t_content *)stack->content)->index < \
				((t_content *)min->content)->index)
			min = stack;
		stack = stack->next;
		steps--;
	}
	if (steps == size && stack->next == NULL)
		while (stack->prev != NULL && steps > 0)
		{
			if (min == NULL || ((t_content *)stack->content)->index < \
					((t_content *)min->content)->index)
				min = stack;
			stack = stack->prev;
			steps--;
		}
	return (min);
}

void	get_mmm(t_data *d, int size)
{
	int	i;

	i = 0;
	if (d->min == NULL)
	{
		d->min = (t_content *)go_el_v(d->A, d->ordlist[0])->content;
		d->max = (t_content *)go_el_v(d->A, d->ordlist[size])->content;
	}
	else
	{
		while (d->ordlist[i] != d->min->number)
			i++;
		d->min = (t_content *)go_el_v(d->A, d->ordlist[i])->content;
		d->max = (t_content *)go_el_v(d->A, d->ordlist[i + size])->content;
	}
}

t_content	*create_content(int number, int ordind ,int index, t_data *d)
{
	t_content *new_content;

	new_content = malloc(sizeof(t_content));
	if (new_content != NULL)
	{
		new_content->number = number;
		new_content->index = index;
		new_content->order = ordind;
	}
	return (new_content);
}

t_bool	charge_stack_A(t_data *d)
{
	int			index, ordind;
	t_content	*new_elem_content;
	 
	d->A = NULL;
	index = 0;
	while (index < d->argc)
	{
		ordind = 0;
		while (d->ordlist[ordind] != d->toorder[index])
			ordind++;
		new_elem_content = create_content(d->toorder[index], ordind, index, d);
		if (new_elem_content == NULL)
		{
			if (d->A != NULL)
				delete_stack(&d->A, delete_content);	
			return (FALSE);
		}
		if (d->A == NULL)
			d->A = new_stack_element(new_elem_content);
		else
			d->A->next = new_stack_element(new_elem_content);
		index++;
	}
	d->A_elem = index++;	
	return (TRUE);
}
