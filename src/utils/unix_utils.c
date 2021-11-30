/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unix_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 09:25:28 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/26 13:43:14 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Gets the environment variable string depending on
 * which one is requested. (basically getvar)
 * 
 * @param var The variable.
 * @param envp The environment variable ptr.
 * @return The variable including the name.
 */
char	*ft_getvar(const char *var, char **envp)
{
	t_size	var_len;
	char	*out;

	out = NULL;
	var_len = ft_strlen(var);
	while (*envp)
	{
		if (ft_strnstr(*envp, var, var_len))
			break ;
		envp++;
	}
	return ((*envp) + var_len + 1);
}

/**
 * Get the absolute executable path of a command.
 * 
 * @param cmd The command like 'ls' or 'grep'.
 * @param envp The environment variable pointer.
 * @return The absolute path to the cmd executable.
 */
char	*ft_getexec(const char *cmd, char **envp)
{
	char	*path;
	char	*temp;
	char	**paths;
	t_i32	path_index;

	path_index = -1;
	paths = ft_split(ft_getvar("PATH", envp), ':');
	while (paths[++path_index])
	{
		temp = ft_strjoin(paths[path_index], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (ft_access(path, F_OK & X_OK))
			break ;
		free(path);
	}
	path_index = -1;
	while (paths[++path_index])
		free(paths[path_index]);
	free(paths);
	return (path);
}

/** 
 * Simplified wrapper for access to return proper boolean.
 * @param path The path to the file.
 * @param flags The flags to use for checking.
 * @returns Depending on the flag wether the condition is met or not.
 */
t_bool	ft_access(const char *path, t_i32 flags)
{
	if (access(path, flags) != -1)
		return (true);
	return (false);
}

/** 
 * Creates a unidirectional pipe.
 * @param fds Int arr of size 2.
 * @param fd0 WRITE
 * @param fd1 READ
 * @note On error check errno! Also pipes are more logically reveresed,
 * 0 was reading and 1 was writing.
 */
t_bool	ft_pipe(t_i32 fds[2])
{
	t_i32	temp;

	if (pipe(fds) == -1)
		return (false);
	temp = fds[0];
	fds[0] = fds[1];
	fds[1] = temp;
	return (true);
}

/** 
 * Creates a new process by duplicating the calling process.
 * @param pid The new process id.
 * @returns Wether the execution was sucessfull.
 * @note Use errorn!
 */
t_bool	ft_fork(pid_t *pid)
{
	t_i32	output;

	output = fork();
	if (output == -1)
		return (false);
	*pid = output;
	return (true);
}
