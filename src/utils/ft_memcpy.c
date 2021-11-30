/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 11:02:32 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/26 10:25:22 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dst, const void *src, t_size n)
{
	t_size	i;

	i = 0;
	while (i < n)
	{
		((t_u8 *)dst)[i] = ((t_u8 *)src)[i];
		i++;
	}
	return (dst);
}
