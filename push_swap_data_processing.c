#include "push_swap.h"

int	*analize_input(char **argv, int argc)
{
	int		*numberlist;
	int		index;	
	char	**list;

	if (argc == 2)
		list = ft_split(argv[1], ' ');
	else
		list = ft_argvdup(argv, argc);
	numberlist = (int *)malloc(sizeof(int) * argc);
	while (list[index] != NULL)
	{
		if (analize_number(list[index], &numberlist[index]) == TRUE)
			index++;
		else
		{
			ft_matrix_delete((void	**)list, 2);
			free(numberlist);
			return (NULL);
		}
	}
	ft_matrix_delete((void **)list, 2);
	return (numberlist);
}

t_bool	analize_number(char	*numberstring, int *numberoutput)
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

t_content	*create_content(int number, int index)
{
	t_content *new_content;

	new_content = malloc(sizeof(t_content));
	if (new_content != NULL)
	{
		new_content->number = number;
		new_content->index = index;
		new_content->order = 0;
	}
	return (new_content);
}

t_stack	*charge_stack_A(int	*numberlist, int argc)
{
	int			index;
	t_stack		*stack;
	t_content	*new_element_content;
	 
	stack = NULL;
	index = 0;
	while (index < argc)
	{
		new_element_content = create_content(numberlist[index], index);
		if (new_element_content == NULL)
		{
			if (stack != NULL)
				delete_stack(&stack, delete_content);	
			return (NULL);
		}
		if (stack == NULL)
			stack = new_stack_element(new_element_content);
		else
			stack->next = new_stack_element(new_element_content);
	}
	return (stack);
}
