/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 18:16:34 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/23 09:25:20 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	t_size	ln;

	ln = ft_strlen(s1);
	str = (char *)malloc(ln * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ln + 1);
	str[ln] = '\0';
	return (str);
}
