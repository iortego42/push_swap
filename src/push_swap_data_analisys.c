#include "push_swap.h"

t_bool	check_numbers(char	**argv, int argc, t_data *d)
{
	int	x,y;

	x = 1;
	y = 0;
	while (argc > 1)
	{
		while (argv[x][y] != 0)
		{
			if (ft_isdigit(argv[x][y]) && \
					(ft_isspace(argv[x][y + 1]) || argv[x][y + 1] == 0))
				d->argc++;
			else if (!ft_isdigit(argv[x][y]) && !ft_isspace(argv[x][y]))
				return (FALSE);
			y++;
		}
		x++;
		argc--;
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
	while (argc > 1)
	{
		list[index] = ft_split(argv[index], ' ');
		if (list[index] == NULL)
			ft_matrix_delete((void **)list, 3);
		index++; 
	}
	return (list);
}

t_bool	get_toorder(char	***list, t_data	*d)
{
	int	x, y, index;
	
	index = 0;
	x = 0;
	y = 0;
	d->toorder = (int *)malloc(sizeof(int) * d->argc);
	if (d->toorder == NULL)
		return (FALSE);
	while (list[x + 1] != NULL)
		x++;
	while (x >= 0)
	{
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
	ft_matrix_delete((void	**) list, 3);
	return (TRUE);
}

t_bool get_ordered_list(t_data *d)
{
	int	*orderedlist, index, auxc;

	auxc = 0;
	index = 0;
	orderedlist = ft_calloc(d->argc, sizeof(int));
	if (orderedlist == NULL)
		return (FALSE);
	while (index < d->argc)
	{
		orderedlist[index] = d->toorder[index]; 
		auxc = index;
		while (orderedlist[auxc] < orderedlist[auxc - 1])
		{
			ft_switch_values((long long *)&orderedlist[auxc],
					(long long *)&orderedlist[auxc - 1]);	
			auxc--;
		}
		if (orderedlist[auxc] == orderedlist[auxc - 1])
			return (orderedlist = NULL, free(orderedlist), TRUE);
		index++;
	}
	return (TRUE);
}

t_err_code	analize_input(char **argv, int argc, t_data *d)
{
	char	***list;

	if (check_numbers(argv, argc, d) != TRUE)
		return (INPUT);
	list = args_split(argv, argc);
	if (list == NULL)
		return (MALLOC);
	if (get_toorder(list, d) != TRUE || get_ordered_list(d) != TRUE)
		return (MALLOC);
	return (OK);
}
