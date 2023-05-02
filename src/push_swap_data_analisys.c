#include "push_swap.h"

t_bool	check_numbers(char	**argv, t_data *d)
{
	int	x,y;

	x = 1;
	while (argv[x] != NULL)
	{
		y = 0;
		while (argv[x][y] != 0)
		{
			if (ft_isdigit(argv[x][y]) &&
			(ft_isspace(argv[x][y + 1]) || argv[x][y + 1] == 0))
				d->argc++;
			else if (!ft_isdigit(argv[x][y]) && !ft_isspace(argv[x][y]))
				return (FALSE);
			y++;
		}
		x++;
	}
	return (TRUE);
}

char	***args_split(char **argv, int argc)
{
	char	***list;
	int		index;

	index = 0;
	list = (char ***) malloc(sizeof(char **) * argc);
	if (list == NULL)
		return (NULL);
	list[argc - 1] = NULL;
	while (argc > 1 + index)
	{
		list[index] = ft_split(argv[index + 1], ' ');
		if (list[index] == NULL)
			return(clearlist(list), NULL);
		index++; 
	}
	return (list);
}

t_bool	get_toorder(char	***list, t_data	*d)
{
	int	x, y, index;
	
	index = 0;
	x = 0;
	d->toorder = (int *)malloc(sizeof(int) * d->argc);
	if (d->toorder == NULL)
		return (FALSE);
	while (list[x + 1] != NULL)
		x++;
	while (x >= 0)
	{
		y = 0;
		while (list[x][y + 1] != NULL)
			y++;
		while (y >= 0)
		{
			d->toorder[index] = ft_atoi(list[x][y]);
			index++;
			y--;
		}
		x--;
	}
	clearlist(list);
	/*ft_matrix_delete((void	**) list, 3);*/
	return (TRUE);
}

void ft_switch_int_values(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
t_bool get_ordered_list(t_data *d)
{
	int index, auxc;

	d->ordlist = (int *) ft_calloc(d->argc, sizeof(int));
	if (d->ordlist == NULL)
		return (FALSE);
	ft_memcpy(d->ordlist, d->toorder, sizeof(int) * d->argc);
	index =  1;
	while (d->argc > index)
	{
		auxc = index;
		if (d->ordlist[index] == d->ordlist[index - 1]) 
			return (FALSE);
		while (auxc > 0 && d->ordlist[auxc] > d->ordlist[auxc - 1])
		{
			ft_switch_int_values(&d->ordlist[auxc], &d->ordlist[auxc - 1]);
			auxc--;
		}
		index++;
	}
	return (TRUE);
}

t_err_code	analize_input(char **argv, int argc, t_data *d)
{
	char	***list;
	
	if (check_numbers(argv, d) != TRUE)
		return (INPUT);
	list = args_split(argv, argc);
	if (list == NULL)
		return (MALLOC);
	if (get_toorder(list, d) != TRUE || get_ordered_list(d) != TRUE)
		return (MALLOC);



	if (d->argc < 3)
		return (INPUT);
	return (OK);
}





