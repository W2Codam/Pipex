/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 09:25:26 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/29 11:41:14 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/wait.h>
# define NOT_FOUND 127
# define GREEN "\x1b[32m"
# define RESET "\033[0m"
# define RED   "\x1b[31m"

//= Typedefs =//

typedef bool				t_bool;

typedef signed char			t_i8;
typedef unsigned char		t_u8;

typedef signed short		t_i16;
typedef unsigned short		t_u16;

typedef signed int			t_i32;
typedef unsigned int		t_u32;

typedef signed long long	t_i64;
typedef unsigned long long	t_u64;

typedef size_t				t_size;

/**
 * Refactored piping for ft_pipe.
 * 
 * I personally disagree with the idea that 1 is writing and 0 is reading.
 * For me it seems more natural that 0 (as input) is writing and 1 (as output)
 * is reading. Just as we first write stuff then read it, not the other way
 * around.
 */
typedef enum e_pipe
{
	WRITE = 0,
	READ = 1
}	t_pipe;

//= Source =//

void	ft_assert(const char *error, t_i32 exit_code);

//= Unix Utils =//

t_bool	ft_fork(pid_t *pid);
t_bool	ft_pipe(t_i32 fds[2]);
t_bool	ft_access(const char *path, t_i32 flags);
char	*ft_getexec(const char *cmd, char **envp);
char	*ft_getvar(const char *var, char **envp);

//= Libft Utils =//

t_size	ft_strlen(const char *str);
t_size	ft_strclen(const char *str, char c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
t_size	ft_strlcpy(char *dst, const char *src, t_size size);
char	*ft_substr(char const *s, t_u32 start, t_size len);
char	*ft_strnstr(const char *big, const char *little, t_size ln);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, t_size n);
#endif