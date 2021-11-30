/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 17:46:49 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/23 09:42:34 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Retrieves the length of a string
 * 
 * @param str The string to get the length from.
 * @return The length.
 */
t_size	ft_strlen(const char *str)
{
	t_size	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
