#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#endif

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

//
//---[ PRINCIPAL TOOLS ]---
//
void	push(t_list stack_in, t_list stack_out);
void	swap(t_list stack);
void	rotate(t_list stack);

//
//---[ ~ ]---
//
void	analizeInput(int	*numberlist);
