/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_assert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 09:32:16 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/29 12:51:42 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Assertion function for critical errors.
 * 
 * @param error An alternative error message in-case errno is not set.
 * @param exit_code The exit code to exit the process.
 */
void	ft_assert(const char *error, t_i32 exit_code)
{
	write(STDERR_FILENO, RED, sizeof(RED));
	if (errno)
		perror("Pipex error");
	else
	{
		write(STDERR_FILENO, "Pipex error: ", 13);
		write(STDERR_FILENO, error, ft_strlen(error));
		write(STDERR_FILENO, "\n", 1);
	}
	write(STDERR_FILENO, RESET, sizeof(RESET));
	exit(exit_code);
}
