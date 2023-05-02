#include "push_swap.h"


void	clearlist(char ***list)
{
	int x,y;

	x = 0;
	while (list[x] != NULL)
	{
		y = 0;
		while (list[x][y] != NULL)
		{
			free(list[x][y]);
			list[x][y] = NULL;
			y++;
		}
		free(list[x]);
		list[x] = NULL;
		x++;
	}
	free(list);
}
void 	init(t_data *d)
{
	d->A = NULL;
	d->B = NULL;
	d->argc = 0;
	d->ordlist = NULL;
	d->toorder = NULL;
	d->max = NULL;
	d->min = NULL;
	d->A_elem = 0;
	d->B_elem = 0;
}


