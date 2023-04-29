#include "push_swap.h"


void 	init(t_data *d)
{
	d->A = (t_stack *) malloc(sizeof(t_stack));
	d->B = (t_stack *) malloc(sizeof(t_stack));
	d->argc = 0;
	d->ordlist = NULL;
	d->toorder = NULL;
	d->max = NULL;
	d->min = NULL;
}


