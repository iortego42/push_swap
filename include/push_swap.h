/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:31:48 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/19 18:38:38 by iortego-         ###   ########.fr       */
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
	int	index;
	int	order;
}	t_content;
typedef struct s_data
{
	int			*ordlist;
	int			*toorder;
	int			argc;
	int			chunksize;
	int			aelem;
	int			belem;
	t_stack		*a;
	t_stack		*b;	

	t_stack		**sp;
	int			*sec;
}	t_data;
typedef enum s_err_code{
	OK,
	EC_UNKNOWN,
	EC_PARSE,
	EC_STACK,
	EC_NO_STACK,
	EC_INPUT,
	EC_MALLOC,
	EC_NO_ELEM,
	EC_EMPTY,
	EC_CONTENT,
	EC_ORDER,
	EC_STACK_LINK,
	EC_ERROR,
	EC_SIZE
}	t_err_code;
typedef void	(*t_action)(t_stack **);
//
//---[ DaTa PROCESSING ]---
//
void		indexing_stack(t_stack *stack);
t_content	*create_content(int number, int ordind, int index);
//
//
//---[ DaTa aNaLISYS ]---
//
t_bool		get_ordered_list(t_data *d);
char		***args_split(char **argv, int argc);
t_bool		get_toorder(char	***list, t_data	*d);
t_bool		is_ordered(int	*list, int argc);
t_bool		check_number(const char	*number, t_data	*d);
t_bool		check_numbers(char	**argv, t_data *d);
t_err_code	analize_input(char **argv, int argc, t_data *d);
//
//---[ INITIaLIZaTION ]---
//
t_err_code	charge_stack_a(t_data *d);
void		clearlist(char ***list);
void		init(t_data *d);
//
//---[ ERROR ]---
//
void		spawn_error_message(const char *message);	
void		select_error(t_err_code code);
void		delete_content(void *content);
void		delete_data(t_data *d);
t_err_code	error(t_data *d, t_err_code error);
//
//---[ PRINCIPaL TOOLS ]---
// 
void		push_a(t_data	*d);
void		push_b(t_data	*d);
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_ab(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_ab(t_stack **stack_a, t_stack **stack_b);
void		rev_rot_a(t_stack **stack_a);
void		rev_rot_b(t_stack **stack_b);
void		rev_rot_ab(t_stack **stack_a, t_stack **stack_b);
//
//---[ SPECIFIC TOOLS ]---
//
t_stack		*go_el(t_stack *stack, int index);
t_stack		*go_el_v(t_stack *stack, int value);
t_stack		*get_min(t_stack *stack, int totalsize);
t_stack		*get_max(t_stack	*stack, int stacksize);
t_bool		is_pushable(t_stack *top, int ordindex, t_data *d);
//
//---[ aLGORITHM ]---
//
t_action	move_selector(t_stack *element, t_data *d);
t_err_code	push_chunk(void (*pushfun)(t_data *), t_action move, t_data *d,
				t_stack *next);
t_err_code	push_chunks(t_data *d);
t_err_code	algorithm(t_data *data);
void		case_min_bot(t_data *d);
void		case_min_mid(t_data *d);
void		case_min_top(t_data *d);
void		order_3(t_data *d);
void		order_5(t_data *d);
#endif
