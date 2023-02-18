#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/stack_files/stack.h"
# include "libft/libft.h"

//
//---[ TYPES ]---
//
typedef struct s_content
{
	int	number;
	int index;
	int order;
}	t_content;
typedef	struct s_data
{
	t_content	*max;
	t_content	*min;
	t_content	*median;
	t_content	**ordlist;
	int			argc;
	t_stack		*A;
	t_stack		*B;
	int			*toorder;
} t_data;
//
//---[ DATA PROCESSING ]---
//
t_content	*create_content(int number, int index, int *orderedlist);
t_stack		*charge_stack_A(int	*numberlist, int argc, int *orderedlist);
void		get_mmm(t_data *d, int size);
//
void		delete_content(void *content);
//
//---[ DATA ANALISYS ]---
//
int			*get_ordered_list(int *numberlist, int size);
int 		get_rate_order(int *numberlist, int size, int *orderedlist);
t_bool		analize_input(char **argv, int argc);
t_bool		assign_number(char	*numberstring, int *numberoutput);
//
//---[ INITIALIZATION ]---
//
t_data 		*init(int	**argv, int argc);
//
//---[ PRINCIPAL TOOLS ]---
// 
void		push_A(t_stack **stack_A, t_stack **stack_B);
void		push_B(t_stack **stack_A, t_stack  **stack_B);
void		swap_AB(t_stack **stack_A, t_stack **stack_B);
void		rotate_AB(t_stack **stack_A, t_stack **stack_B);
void		rev_rot_AB(t_stack **stack_A, t_stack **stack_B);
//
//---[ SPECIFIC TOOLS ]---
//
t_stack		*go_el(t_stack *stack, int index);
t_stack		*go_el_v(t_stack *stack, int value);
// revisar go_el_v es muy probable que no sea necesaria ya que ordlist es una lista de t_content y aunque este ordenada tiene los indices del stack sin ordenar.
void		push_element_n_A(t_stack **stack_A, t_stack **stack_B, int index);
void		push_element_n_B(t_stack **stack_A, t_stack **stack_B, int index);
void		ordernating(t_stack **stack_A, t_stack **stack_B);
int			*get_numbers(t_stack);
#endif
