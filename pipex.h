/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:51:56 by uisroilo          #+#    #+#             */
/*   Updated: 2022/04/16 10:54:55 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		fd_infile;
	int		fd_outfile;
	char	*str_path;
	char	**str_split;
	char	**get_1cmd;
	char	*real_path1;
	char	**get_2cmd;
	char	*real_path2;
}	t_pipex;

char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
void	*ft_path_cmd(char **env);
// char	*ft_get_cmd(char *str);
void	free_split(char **split);
void	ft_putstr(char *file, char *str);
char	*get_path_access(char **str_split_path, char *get_cmd);

#endif
