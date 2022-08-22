/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:39:16 by uisroilo          #+#    #+#             */
/*   Updated: 2022/04/09 10:16:43 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start > (size_t)ft_strlen(s))
		new_str = (char *)malloc(1);
	else if (len > (size_t)ft_strlen(s))
		new_str = (char *)malloc((size_t)(ft_strlen(s) - start));
	else
		new_str = (char *)malloc(len + 1);
	if (!s || !(new_str))
		return (0);
	i = start;
	j = 0;
	while (i < (size_t)ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
