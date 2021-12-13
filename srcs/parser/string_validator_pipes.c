/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:05:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/13 19:37:20 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	string_validator_pipes(char *line)
{
	int	text;
	int	pipe;
	int	i;

	text = 0;
	pipe = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			pipe = 1;
			if (!text)
				break ;
			text = 0;
		}
		else if (line[i] != ' ')
			text = 1;
		i++;
	}
	if (pipe && !text)
		print_error("parse error near `|'");
	return (1);
}
