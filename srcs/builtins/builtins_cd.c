/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:40:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/18 20:47:50 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Counts the number of arguments that are passed
*/

static int	count_arguments(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		i++;
		if (i == 3)
		{
			printf("to many arguments \n");
			return (-1);
		}
	}
	return (i);
}

/*
** Controls the behavior when you want to place the prompt in the
** 'HOME' and it does not exist or is not valid.
*/

static int	home(t_list *env_lst, char *pwd)
{
	set_key_value(env_lst, pwd, "OLDPWD");
	if (!get_current_path(env_lst, "HOME"))
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(get_current_path(env_lst, "HOME")) == -1)
	{
		perror("cd");
		return (1);
	}
	set_key_value(env_lst, get_current_path(env_lst, "HOME"), "PWD");
	return (0);
}

/*
** Moves the prompt one level up
*/

static void	go_up(t_list *env_lst, char *pwd)
{
	set_key_value(env_lst, pwd, "OLDPWD");
	chdir("..");
	free(pwd);
	pwd = getcwd(NULL, 4096);
	set_key_value(env_lst, pwd, "PWD");
}

/*
** Returns the prompt to the place it came from
*/

static void	back(t_list *env_lst, char *pwd, char *aux)
{
	aux = ft_strdup(get_current_path(env_lst, "OLDPWD"));
	set_key_value(env_lst, pwd, "OLDPWD");
	chdir(aux);
	set_key_value(env_lst, aux, "PWD");
	free(aux);
}

/*
** Moves the prompt between directory levels
*/

int	builtins_cd(char **argv, t_list **env_lst)
{
	char	*pwd;
	char	*aux;
	int		i;

	i = count_arguments(argv);
	aux = NULL;
	pwd = getcwd(NULL, 4096);
	printf("Numero de argumentos %d\n", i);
	if ((i == 1)
		|| (ft_strcmp(argv[0], "cd") == 0 && ft_strcmp(argv[1], "--") == 0))
	{
		free(pwd);
		return (home(*env_lst, pwd));
	}
	else if (ft_strcmp(argv[1], "..") == 0)
		go_up(*env_lst, pwd);
	else if (ft_strcmp(argv[1], "-") == 0)
		back(*env_lst, pwd, aux);
	else
	{
		if (chdir(argv[1]) == -1)
			perror("cd");
	}
	free(pwd);
	return (0);
}
