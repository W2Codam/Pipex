/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:58:47 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/23 09:41:53 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Gives the length of a string until terminator or c.
 * 
 * @param str The string to get the length from.
 * @param c The secondary delimiter.
 * @return Length of the string until c or terminator.
 */
t_size	ft_strclen(const char *str, char c)
{
	t_size	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}
