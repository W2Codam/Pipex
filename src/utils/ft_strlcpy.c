/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 17:59:29 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/26 17:58:10 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Copies at most 'size' amount of bytes from src to dest.
 * Null terminating dst.
 * 
 * @param dst The target.
 * @param src The source.
 * @param size Size of source.
 * @return The amount of bytes attempted to copy over.
 */
t_size	ft_strlcpy(char *dst, const char *src, t_size size)
{
	t_size	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
