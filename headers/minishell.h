/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:56:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/03 17:20:33 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"

typedef enum e_behavior
{
	plain,
	redir_in,
	redir_out,
	redir_in_append,
	here_doc,
	dollar_var,
	pipe
}			t_behavior;

typedef struct s_token
{
	struct s_token	*next;
	char			*text;
	t_behavior		behavior;
}			t_token;

#endif
