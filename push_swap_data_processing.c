#include "push_swap.h"

void	get_mmm(t_data *d, int size)
{
	int	i;

	i = 0;
	if	(d->min == NULL)
	{
		d->min = (t_content *)go_el_v(d->A, d->ordlist[0])->content;
		d->max = (t_content *)go_el_v(d->A, d->ordlist[size])->content;
		d->median = (t_content *)go_el_v(d->A, d->ordlist[size / 2])->content;
	}
	else
	{
		while (d->ordlist[i] != d->min->number)
			i++;
		d->min = (t_content *)go_el_v(d->A, d->ordlist[i])->content;
		d->max = (t_content *)go_el_v(d->A, d->ordlist[i + size])->content;
		d->median = (t_content *)go_el_v(d->A, \
				d->ordlist[(i + size) / 2])->content;
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
	int			index, ordind;
	t_content	*new_element_content;
	 
	d->A = NULL;
	index = 0;
	while (index < d->argc)
	{
		ordind = 0;
		while (d->ordlist[ordind] != d->toorder[index])
			ordind++;
		new_element_content = create_content(d->toorder[index], ordind, d);
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
		index++;
	}
	d->A_elem = index++;	
	return (TRUE);
}
