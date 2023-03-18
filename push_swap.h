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
	t_content	*min;
	// revisar si realmente necesito max y median
	t_content	*max;
	t_content	*media;
	int			*ordlist;
	int			*toorder;
	int			argc;
	int			A_elem;
	int			B_elem;
	t_stack		*A;
	t_stack		*B;
} t_data;
typedef enum {UNKNOWN, ERROR, PARSE, STACK} t_err_code;
typedef void (*f_action)(t_stack **);
//
//---[ DATA PROCESSING ]---
//
void	indexing_stack(t_stack *stack);
t_content	*create_content(int number, int ordind, int index, t_data *d);
//
//
//---[ DATA ANALISYS ]---
//
int			*get_ordered_list(int *numberlist, int size);
int 		get_rate_order(int *numberlist, int size, int *orderedlist);
char		***args_split(char **argv, int argc, t_data *d);
t_bool		get_toorder(char	***list, t_data	*d);
t_bool		check_numbers(char	**argv, int argc, t_data *d);
t_bool		analize_input(char **argv, int argc, t_data *d);
//
//---[ INITIALIZATION ]---
//
t_bool		charge_stack_A(t_data *d);
void		init(t_data *d);
//
//---[ ERROR ]---
//
void	spawn_error_message(const char *message);	
void	select_error(t_err_code code);
void	delete_content(void *content);
void	delete_data(t_data *);
void	error(t_data *d);
//
//
//---[ PRINCIPAL TOOLS ]---
// 
void		push_A(t_data 	*d);
void		push_B(t_data	*d);
void		swap_A(t_stack **stack_A);
void		swap_B(t_stack **stack_B);
void		swap_AB(t_stack **stack_A, t_stack **stack_B);
void		rotate_A(t_stack **stack_A);
void		rotate_B(t_stack **stack_B);
void		rotate_AB(t_stack **stack_A, t_stack **stack_B);
void		rev_rot_A(t_stack **stack_A);
void		rev_rot_B(t_stack **stack_B);
void		rev_rot_AB(t_stack **stack_A, t_stack **stack_B);
//
//---[ SPECIFIC TOOLS ]---
//
t_stack		*go_el(t_stack *stack, int index);
t_stack		*go_el_v(t_stack *stack, int value);
t_stack		*get_min(t_stack *stack, int size);
// revisar go_el_v es muy probable que no sea necesaria ya que ordlist es una lista de t_content y aunque este ordenada tiene los indices del stack sin ordenar.

#endif
