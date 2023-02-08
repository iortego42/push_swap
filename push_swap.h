#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#endif

# include <unistd.h>
# include <stdlib.h>
# include "libft/stack_files/stack.h"

//
//---[ TYPES ]---
//
typedef struct s_content
{
	int	number;
	int index;
	int order;
}	t_content;
//
//---[ DATA PROCESSING ]---
//

int	*analize_input(char **argv, int argc);
t_bool	analize_number(char	*numberstring, int *numberoutput);
t_content	*create_content(int number, int index);
t_stack	*charge_stack_A(int	*numberlist, int argc);
//
//---[ PRINCIPAL TOOLS ]---
// 
t_content	*create_content(int number, int index);
void	delete_content(void *content);
//
//---[ SPECIFIC TOOLS ]---
//
void	push_A(t_stack **stack_A, t_stack **stack_B);
void	push_B(t_stack **stack_A, t_stack  **stack_B);
void	swap_AB(t_stack **stack_A, t_stack **stack_B);
void	rotate_AB(t_stack **stack_A, t_stack **stack_B);
void	rev_rot_AB(t_stack **stack_A, t_stack **stack_B);
//
//---[ ~ ]---
//
void	analizeInput(int	*numberlist);
