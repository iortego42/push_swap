#include "libft/libft.h"
#include "push_swap.h"

char	***args_split(char **argv, int argc, t_data *d)
{
	char	***list;
	char	**aux;
	int		index;

	index = 0;
	list = (char ***) malloc(sizeof(char **) * argc);
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
					(ft_isspace(argv[x][y + 1]) || argv[x][y]))
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

t_bool	get_toorder(char	***list, t_data	*d)
{
	int	x, y, z, index;
	
	index = d->argc;
	d->toorder = (int *) malloc(sizeof(int) * d->argc);
	if (d->toorder == NULL)
		return (FALSE);
	while (list[x + 1] != NULL)
	{
		while (list[y + 1] != NULL)
			y++;
		x++;
	}
	while (x > 0)
	{
		while (y > 0)
		{
			d->toorder[index] = ft_atoi(list[x][y]);
			index--;
			y--;
		}
		x--;
	}
	return (TRUE);
}

t_bool	analize_input(char **argv, int argc, t_data *d)
{

	if (check_numbers(argv, argc, d) != TRUE)
		return (FALSE);
	



	return (FALSE);
}


int	*get_ordered_list(int *numberlist, int size)
{
	int	*orderedlist, index, auxc, min, nextmin;

	auxc = 0;
	index = 0;
	orderedlist = ft_calloc(size, sizeof(int));
	if (orderedlist == NULL)
		return (NULL);
	while (index < size)
	{
		orderedlist[index] = numberlist[index]; 
		auxc = index;
		while (orderedlist[auxc] < orderedlist[auxc - 1])
		{
			ft_switch_values((long long *)&orderedlist[auxc], \
					(long long *)&orderedlist[auxc - 1]);	
			auxc--;
		}
		index++;
	}
	return (orderedlist);
}

int get_rate_order(int *numberlist, int size, int *orderedlist)
{
	int orderrate;
	int index1;
	int	index2;


	orderrate = 0;
	index2 = size;
	while (index2 > 0)
	{
		index1 = size;
		if (numberlist[index2] != orderedlist[index2])
		{
			while (numberlist[index1] != orderedlist[index2])
				index1--;
			orderrate += index1 - index2;
		}
		index2--;
	}
	return (orderrate);
}
