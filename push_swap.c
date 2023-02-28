#include "push_swap.h"

t_bool	analize_input(char **argv, int argc, t_data *d)
{
	char	***list;

	if (check_numbers(argv, argc, d) != TRUE)
		return (FALSE);
	list = args_split(argv, argc, d);
	if (list == NULL)
		return (FALSE);
	if (get_toorder(list, d) != TRUE)
		return (ft_matrix_delete((void **)list, 3), FALSE);
	d->ordlist = get_ordered_list(d->toorder, d->argc);
	if (d->ordlist == NULL)
		return (ft_matrix_delete((void **)list, 3), FALSE);
	if (get_rate_order(d->toorder, d->argc, d->ordlist) == 0)
		return (ft_matrix_delete((void **)list, 3), FALSE);
	ft_matrix_delete((void **)list, 3);
	return (TRUE);
}

int main(int argc, char **argv)
{
	t_data	*data;

	init(data);
	if (analize_input(argv, argc, data) != TRUE)
		error(data);
	else
		algorithm(data);
	return (0);
}
