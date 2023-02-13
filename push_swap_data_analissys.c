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

int	*get_ordered_list(int *numberlist, int counter)
{
	int	*orderedlist, index, auxc, min, nextmin;

	auxc = 0;
	index = 0;
	orderedlist = ft_calloc(counter, sizeof(int));
	while (auxc < counter)
	{
		if (numberlist[auxc] > nextmin || auxc == 0)
			nextmin = numberlist[auxc];
		auxc++;
	}
	while (index < counter)
	{
		min = orderedlist[index];
		while (auxc < counter)
		{
			if (min < numberlist[auxc] && numberlist[auxc] < nextmin)
				nextmin = numberlist[auxc];
			auxc++;
		}
		index++;
		orderedlist[index] = min;
	}
}

t_bool get_rate_order(int *numberlist, int counter)
{
	
}
