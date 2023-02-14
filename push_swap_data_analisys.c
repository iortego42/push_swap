#include "libft/libft.h"
#include "push_swap.h"

t_bool	analize_input(char **argv, int argc)
{
	int	index, argindex;

	argindex = 1;
	index = 0;
	while (argc > argindex)
	{
		while (ft_isdigit(argv[argindex][index]) ||	\
				ft_isspace(argv[argindex][index]))
			index++;
		argindex++;
	}
	if (argc == argindex)
		return (TRUE);
	return (FALSE);
}

t_bool	assign_number(char *numberstring, int *numberoutput)
{
	int		index;

	index = 0;
	while (numberstring[index] != 0)
	{
		if (!ft_isdigit(numberstring[index]))
			return (FALSE);
		index++;
	}
	*numberoutput = ft_atoi(numberstring);
	return (TRUE);
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
	return (orderrate)
}
