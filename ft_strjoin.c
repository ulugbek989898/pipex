/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:43:47 by uisroilo          #+#    #+#             */
/*   Updated: 2022/04/14 08:59:07 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str1;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str1[i] = s2[j];
		j++;
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
