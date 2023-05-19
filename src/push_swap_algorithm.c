/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:39 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/19 18:39:58 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_action	move_selector(t_stack *element, t_data *d)
{
	t_action	move;

	if (d->sec == &d->aelem)
	{
		if (((t_content *)element->content)->index > *d->sec / 2)
			move = rotate_a;
		else
			move = rev_rot_a;
	}
	else if (d->sec == &d->belem)
	{
		if (((t_content *)element->content)->index > *d->sec / 2)
			move = rotate_b;
		else
			move = rev_rot_b;
	}
	else
		return (NULL);
	return (move);
}

t_err_code	push_chunk(void (*pushfun)(t_data *),
				t_action move, t_data *d, t_stack *next)
{	
	t_stack		*top;
	int			step;

	top = peek(*d->sp);
	step = d->chunksize;
	while ((step > 0 || (step == 0 && 0 == d->chunksize)) && *d->sp != NULL)
	{	
		if (TRUE == is_pushable(top, ((t_content *)next->content)->order, d))
		{
			pushfun(d);
			step--;
		}
		else
			move(d->sp);
		top = peek(*d->sp);
		if (top == NULL && *d->sec != 0)
			return (EC_EMPTY);
	}
	return (OK);
}

t_err_code	push_manager(t_data *d, t_stack *next)
{
	void		(*pushfun)(t_data *);
	t_action	move;

	if (d->sp == &d->a)
		pushfun = push_b;
	else if (d->sp == &d->b)
		pushfun = push_a;
	else
		return (EC_UNKNOWN);
	move = move_selector(next, d);
	return (push_chunk(pushfun, move, d, next));
}

t_err_code	push_chunks(t_data *d)
{
	t_stack		*next;
	t_err_code	status;

	if (d->sp == &d->a)
		d->sec = &d->aelem;
	else if (d->sp == &d->b)
		d->sec = &d->belem;
	else
		return (EC_NO_STACK);
	status = OK;
	while (status == OK && *d->sec)
	{
		if (d->sp == &d->a)
			next = get_min(*d->sp, *d->sec);
		else
			next = get_max(*d->sp, *d->sec);
		if (next == NULL)
			return (EC_STACK_LINK);
		status = push_manager(d, next);
	}
	return (status);
}

t_err_code	algorithm(t_data *d)
{
	t_err_code	status;

	if (d->argc == 2)
		return (swap_a(&d->a), OK);
	else if (d->argc <= 5)
		return (order_5(d), OK);
	else if (d->argc <= 100)
		d->chunksize = d->argc / 4;
	else
		d->chunksize = d->argc / 12;
	d->sp = &d->a;
	status = push_chunks(d);
	if (status != OK)
		return (status);
	d->chunksize = 0;
	d->sp = &d->b;
	status = push_chunks(d);
	if (status != OK)
		return (status);
	return (OK);
}
