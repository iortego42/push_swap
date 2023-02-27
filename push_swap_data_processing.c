#include "push_swap.h"

void	get_mmm(t_data *d, int size)
{
	static int index;
	
	index = 0;
	index += size;
	if (index + size > d->argc)
		size = d->argc - index;
	d->max->number = d->ordlist[index];
	d->min->number = d->ordlist[index];
	while (size > 1)
	{
		if (d->max->number < d->ordlist[index])
			d->max = (t_content *)go_el_v(d->A, d->ordlist[index])->content;
		else if (d->min->number > d->ordlist[index])
			d->min = (t_content *)go_el_v(d->A, d->ordlist[index])->content;
	}
}

t_content	*create_content(int number, int index, t_data *d)
{
	t_content *new_content;

	new_content = malloc(sizeof(t_content));
	if (new_content != NULL)
	{
		new_content->number = number;
		new_content->index = index;
		new_content->order = get_rate_order(&number, 1, d->ordlist);
	}
	return (new_content);
}

t_bool	charge_stack_A(t_data *d)
{
	int			index;
	t_content	*new_element_content;
	 
	d->A = NULL;
	index = 0;
	while (index < d->argc)
	{
		new_element_content = create_content(d->toorder[index], index, d);
		if (new_element_content == NULL)
		{
			if (d->A != NULL)
				delete_stack(&d->A, delete_content);	
			return (FALSE);
		}
		if (d->A == NULL)
			d->A = new_stack_element(new_element_content);
		else
			d->A->next = new_stack_element(new_element_content);
	}
	
	return (TRUE);
}
