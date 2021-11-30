/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 12:31:57 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/23 10:31:44 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	t_size	len1;
	t_size	len2;

	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	out = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, s1, len1);
	ft_memcpy(out + len1, s2, len2);
	out[len1 + len2] = '\0';
	return (out);
}
