/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/24 11:59:56 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/29 12:51:37 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * "Opens" a file by either just opening it or if its meant to be
 * the output, aka stdout, then create it.
 * 
 * @param path The file path to open.
 * @param isoutput Is the file meant to be an output file, aka written to.
 * @return The file descriptor.
 */
static t_i32	ft_openfile(char *path, t_bool isoutput)
{
	t_i32	fd;

	fd = -1;
	if (isoutput)
	{
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, \
		S_IRUSR | S_IWUSR | S_IROTH);
	}
	else
	{
		fd = open(path, O_RDONLY);
	}
	if (fd < 0)
		ft_assert("Unable to open file", EXIT_FAILURE);
	return (fd);
}

static void	ft_cleanup(char **out)
{
	t_u32	i;

	i = 0;
	while (out[i] != NULL)
		free(out[i++]);
	free(out);
	return ;
}

/**
 * Executes the given shell command.
 * Command can be given as an absolute path like "/bin/ls" or
 * by just typing "ls". If command does not exists
 * 
 * @param cmd The whole command with args.
 * @param envp Enviroment pointer.
 */
static void	ft_exec(char *cmd, char **envp)
{
	t_i32	i;
	char	*path;
	char	**args;

	i = 0;
	args = ft_split(cmd, ' ');
	if (args[0][0] == '/' || args[0][0] == '.' || \
		(args[0][0] == '.' && args[0][1] == '.'))
		path = args[0];
	else
		path = ft_getexec(args[0], envp);
	execve(path, args, envp);
	ft_cleanup(args);
	ft_assert("Command does not exist", NOT_FOUND);
}

/**
 * Executes a function by taking the input as source and
 * storing the output in stdout. Forking the process.
 * 
 * @param cmd The full command, with args,
 * @param envp Enviroment pointer.
 */
static void	ft_exec_child(char *cmd, char **envp)
{
	pid_t	pid;
	t_i32	fds[2];

	if (!ft_pipe(fds))
		ft_assert("Failed to create a pipe", EXIT_FAILURE);
	if (!ft_fork(&pid))
		ft_assert("A philospher dropped his fork...", EXIT_FAILURE);
	if (pid == 0)
	{
		close(fds[READ]);
		dup2(fds[WRITE], STDOUT_FILENO);
		ft_exec(cmd, envp);
	}
	else
	{
		close(fds[WRITE]);
		dup2(fds[READ], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

t_i32	main(int argc, char **argv, char **envp)
{
	t_i32	i;
	t_i32	in;
	t_i32	out;

	i = 2;
	if (argc - 1 < 4)
		ft_assert("Invalid use!\nUSAGE: ./pipex <in> <cmd1> <cmd2> <out>", \
		EXIT_FAILURE);
	in = ft_openfile(argv[1], false);
	out = ft_openfile(argv[argc - 1], true);
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	while (i < argc - 2)
		ft_exec_child(argv[i++], envp);
	ft_exec(argv[i], envp);
	close(in);
	close(out);
	exit(EXIT_SUCCESS);
}
