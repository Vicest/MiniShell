/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:09:26 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/23 21:46:39 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	count_spaces(char *line)
{
	char	*end;
	char	aux;

	aux = *line;
	end = line;
	while (aux && is_space(aux))
	{
		end++;
		aux = *end;
	}
	return (end - line);
}