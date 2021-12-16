/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 21:12:05 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	wait_children(size_t cmd_num, pid_t last_pid)
{
	int	status;

	cmd_num--;
	waitpid(last_pid, &status, 0);
	if (WIFEXITED(status))
		set_exit_status(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		set_exit_status(128 + WTERMSIG(status));
	while (cmd_num > 0)
	{
		wait(NULL);
		cmd_num--;
	}
}
