/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:53:36 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/29 12:03:22 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_u32	ft_wcount(const char *str, char c)
{
	t_u32	w;
	t_size	i;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			w++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (w);
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

static t_bool	ft_allocate(char **out, t_u32 wcount, char const *s, char c)
{
	t_size	windex;
	t_size	sindex;
	t_size	wlen;

	windex = 0;
	sindex = 0;
	while (windex < wcount)
	{
		while (s[sindex] == c)
			sindex++;
		wlen = ft_strclen(&s[sindex], c);
		out[windex] = ft_substr(s, sindex, wlen);
		if (!out[windex])
			return (false);
		windex++;
		sindex += wlen;
	}
	return (true);
}

/** 
 * Allocates and returns an array of strings obtained by 
 * splitting 's' using the character 'c' as a delimiter. 
 * The array ends with a NULL pointer.
 * @param s The string to be split.
 * @param c The char delimiter.
 * @returns A string array.
 */
char	**ft_split(char const *s, char c)
{
	char	**out;
	t_u32	wcount;
	t_bool	isempty;

	wcount = ft_wcount(s, c);
	isempty = (wcount == 0);
	if (isempty)
		wcount++;
	out = (char **)malloc((wcount + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	out[wcount] = NULL;
	if (!*s || isempty)
		return (out);
	if (!ft_allocate(out, wcount, s, c))
	{
		ft_cleanup(out);
		return (NULL);
	}
	return (out);
}
