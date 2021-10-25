/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:56:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/25 19:15:17 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef enum e_behavior
{
	redir_out,
	redir_out_append,
	redir_in,
	here_doc,
	plain
}			t_behavior;

typedef struct s_redirect
{
	char		*text;
	t_behavior	type;
}				t_redirect;

typedef struct	s_cmd
{
	t_list	*arg;
	t_list	*lst_redir_in;
	t_list	*lst_redir_out;
}				t_cmd;

typedef struct s_env_var
{
	char	*key;
	char	*value;
}			t_env_var;

int		is_delimiter(char c);
int		is_space(char c);
size_t	count_spaces(char *line);
size_t	count_until_repeat(char *line);

void	split_in_cmds(char *line, t_list **last_cmd);
void	tokenize_cmd(char *cmd_txt, t_cmd *cmd_node);
void	free_cmd(void *elem);
void	free_redirect(void *elem);
void	print_cmd(void *elem);
void	print_redir(void *elem);
int		string_validator(char *line);
int		string_validator_pipes(char *line);
void	print_error(char *str);
void	builtint_echo(char **argv, char **env);
void	builtint_pwd(char **argv, char **env);
void	builtins_env(char **argv, char **env);

//Environment
void	*env_var_new(char *key_str, char *value_str);
void	env_var_new_value(t_env_var *node, char *new_val);
void	env_var_delete(t_env_var *var);
int		env_var_cmp(void *elem1, void *elem2);
#endif
