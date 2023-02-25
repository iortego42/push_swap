#include "libft/libft.h"
#include "push_swap.h"

t_bool	argcount(char **argv, int argc, t_data *d)
{
	int i;

	i = 0;
	d->argc = 1;
	while (argc > 0)
	{
		while (argv[argc][i] != 0)
		{
			if(ft_isdigit(argv[argc][i]) && (ft_isspace(argv[argc][i + 1]) || \
						argv[argc][i + 1] == 0))
				d->argc++;
			else if (!ft_isdigit(argv[argc][i]) && !ft_isspace(argv[argc][i]))
				return (FALSE);
			i++;
		}
		argc--;
	}
}
void	argalloc(char **argv, int argc, t_data *d)
{
	char	**list;
	int		i;

	i = 0;
	while	
}

t_bool	analize_input(char **argv, int argc, t_data *d)
{
	int	index, argindex;

	argindex = 1;
	index = 0;
	d->ordlist = (int *)malloc(d->argc * sizeof(int));
	while (argc > argindex)
	{
		d->argc++;
		while (argv[argindex][index] != 0)
		{
			if (!ft_isdigit(argv[argindex][index]) && \
				!ft_isspace(argv[argindex][index]))
				return (FALSE);
			if (ft_isspace(argv[argindex][index]))
				d->argc++;
			index++;
		}
		argindex++;
	}
	if (argc == argindex)
		return (TRUE);
	if (get_rate_order(d->toorder, d->argc, d->ordlist) == 0)
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
