/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:52:33 by uisroilo          #+#    #+#             */
/*   Updated: 2022/04/16 13:59:56 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_path_cmd(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T')
		{
			return (env[i] + 5);
		}
		i++;
	}
	return (NULL);
}

// char	*ft_get_cmd(char *str)
// {
// 	char	**str_split;
// 	char	*get_1item;

// 	str_split = ft_split(str, ' ');
// 	get_1item = str_split[0];
// 	return (get_1item);
// }

char	*get_path_access(char **str_split_path, char *get_cmd)
{
	int		i;
	char	*join_slash_path;
	char	*temp;

	if (access(get_cmd, X_OK) == 0)
		return (get_cmd);
	i = 0;
	while (str_split_path[i])
	{
		temp = ft_strjoin(str_split_path[i], "/");
		join_slash_path = ft_strjoin(temp, get_cmd);
		free(temp);
		if (access(join_slash_path, X_OK) == 0)
			return (join_slash_path);
		free(join_slash_path);
		i++;
	}
	write(1, get_cmd, ft_strlen(get_cmd));
	write(1, ": command not found", 19);
	write(1, "\n", 1);
	return (NULL);
}

void	ft_putstr(char *file, char *str)
{
	write(2, str, ft_strlen(str));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, "\n", 1);
	exit (1);
}