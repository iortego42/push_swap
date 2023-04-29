/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:53 by iortego-          #+#    #+#             */
/*   Updated: 2023/04/29 19:29:18 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*error_mess[ERROR + 1] = { 
	"Undefined Error", 
	"Unclassified", 
	"Parsing", 
	"Stack", 
	"Element", 
	"Wrong Input", 
	"Malloc", 
	"No element founded",
	"Empty stack",

	"ERROR",
};

void	delete_content(void *content)
{
	free(content);
	content = NULL;
}

void	spawn_error_message(const char *message)
{
	int	len;

	len = ft_strlen(message);
	if (ft_strncmp(message, "ERROR", 5))
		write(2, "[•] ERROR: ",11);
	write(2, message, len);
}

void	select_error(t_err_code code)
{
	int	size;

	size = sizeof(error_mess) / sizeof(error_mess[0]);
	if ((int)code >= size )
		spawn_error_message(error_mess[UNKNOWN]);
	else
		spawn_error_message(error_mess[code]);	
}

void	delete_data(t_data *d)
{
	if (d->ordlist != NULL)
		free(d->ordlist);
	if (d->toorder != NULL)
		free(d->ordlist);
	if (d->A != NULL)
		delete_stack(&d->A, delete_content);	
	if (d->B != NULL)
		delete_stack(&d->B, delete_content);
}

t_err_code	error(t_data *d, t_err_code error)
{
	if (error == OK)
	{
		error = UNKNOWN;
		if (d->A == NULL || d->B == NULL)
			error = STACK;
		else if (d->ordlist == NULL || d->toorder == NULL)
			error = PARSE;
	}
	delete_data(d);
	select_error(error);
	return (error);
}

