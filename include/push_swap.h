/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:12:13 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/09 17:54:05 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "stack.h"
# include "libft.h"

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
	t_content	*max;
	int			*ordlist;
	int			*toorder;
	int			argc;
	int			A_elem;
	int			B_elem;
	t_stack		*A;
	t_stack		*B;
} t_data;
typedef enum {
	OK, 
	UNKNOWN, 
	PARSE, 
	STACK, 
	ELEMENT, 
	INPUT, 
	MALLOC,
	NO_ELEM,
	EMPTY,
	CONTENT,
	ORDER,
	STACK_LINK,
	ERROR, 
} t_err_code;
typedef void (*f_action)(t_stack **);
//
//---[ DATA PROCESSING ]---
//
void		indexing_stack(t_stack *stack);
t_content	*create_content(int number, int ordind, int index);
//
//
//---[ DATA ANALISYS ]---
//
t_bool		get_ordered_list(t_data *d);
char		***args_split(char **argv, int argc);
t_bool		get_toorder(char	***list, t_data	*d);
t_bool		check_numbers(char	**argv, t_data *d);
t_err_code	analize_input(char **argv, int argc, t_data *d);
//
//---[ INITIALIZATION ]---
//
t_err_code	charge_stack_A(t_data *d);
void		clearlist(char ***list);
void		init(t_data *d);
//
//---[ ERROR ]---
//
void		spawn_error_message(const char *message);	
void		select_error(t_err_code code);
void		delete_content(void *content);
void		delete_data(t_data *);
t_err_code	error(t_data *d, t_err_code error);
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
t_stack		*get_min(t_stack *stack, int totalsize);
t_stack		*get_max(t_stack	*stack, int stacksize);
int			search_next(t_data *d, t_stack *stack);
t_bool		is_pushable(t_stack *top, int ordindex, int chunksize);

//
//---[ ALGORITHM ]---
//
f_action move_selector(int *stacksize, t_stack *element, t_data *d);
t_err_code push_chunk(t_data *d, int chunksize, t_stack **stack, t_stack *next);
t_err_code	push_chunks(t_data *d, int chunksize, t_stack **stack);
t_err_code	algorithm(t_data *data);
// revisar go_el_v es muy probable que no sea necesaria ya que ordlist es una lista de t_content y aunque este ordenada tiene los indices del stack sin ordenar.

#endif
