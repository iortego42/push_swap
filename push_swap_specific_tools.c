#include "push_swap.h"

t_bool analize_input(char **argv, int argc)
{
	t_bool	iscorrect;
	char **list;
	iscorrect = TRUE;
	if (argc == 1)
	{
		list = ft_split(argv[0], ' ');
		
	}
	return (iscorrect);
}
t_bool	analize_number(char	*)
t_stack	*element(t_stack *stack, int index)
{
	t_stack	*copy;

	copy = stack;
	while (((t_content *)copy->content)->index != index && copy->next != NULL)
		copy = copy->next;
	if (((t_content *)copy->content)->index != index)
		return (NULL);
	return (copy);
}

