/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 18:08:42 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/26 10:25:31 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *big, const char *little, t_size ln)
{
	t_size	i;
	t_size	j;

	i = 0;
	j = 0;
	if (!little || !*little)
		return ((char *)big);
	while (big[i] != '\0' && i < ln)
	{
		while (big[i + j] == little[j] && i + j < ln)
		{
			if (little[++j] == '\0')
				return (&((char *)big)[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
