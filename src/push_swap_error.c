/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:53 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/19 18:37:56 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_content(void *content)
{
	if (content == NULL)
		return ((void)"42Madrid");
	free(content);
}

void	spawn_error_message(const char *message)
{
	if (ft_strncmp(message, "Error", 5))
		ft_putstr_fd("\033[33;1m[•]\033[31m ERROR:\033[0m ", 2);
	ft_putstr_fd((char *)message, 2);
}

void	select_error(t_err_code code)
{
	const char	*error_mess[EC_SIZE] = {
		"\033[35mUndefined\033[0m\n",
		"Unclassified\n",
		"Parsing\n",
		"Stack not founded\n",
		"Stack pointer pointing to wrong stack\n",
		"Wrong Input\n",
		"Malloc\n",
		"No element founded\n",
		"Empty stack\n",
		"No content\n",
		"Ordering list\n",
		"Stack not linked correctly\n",
		"Error\n",
	};

	if (code >= EC_SIZE)
		spawn_error_message(error_mess[EC_UNKNOWN]);
	else
		spawn_error_message(error_mess[code]);
}/*
void	select_error(t_err_code code)
{
	code = ERROR;
	spawn_error_message(g_error_mess[code]);
}*/

void	delete_data(t_data *d)
{
	if (d->ordlist != NULL)
		free(d->ordlist);
	if (d->toorder != NULL)
		free(d->toorder);
	if (d->a != NULL)
		delete_stack(&d->a, delete_content);
	if (d->a != NULL)
		delete_stack(&d->b, delete_content);
	d->sp = NULL;
	d->sec = NULL;
}

t_err_code	error(t_data *d, t_err_code error)
{
	if (error == EC_ORDER)
		return (OK);
	if (error == OK)
	{
		error = EC_UNKNOWN;
		if (d->a == NULL || d->b == NULL)
			error = EC_STACK;
		else if (d->ordlist == NULL || d->toorder == NULL)
			error = EC_PARSE;
	}
	delete_data(d);
	select_error(error);
	return (error);
}
