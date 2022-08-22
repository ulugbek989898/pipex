/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:18:40 by uisroilo          #+#    #+#             */
/*   Updated: 2022/04/14 08:58:33 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_word_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**push_words(char const *s, char **ptr, char c, size_t count)
{
	size_t	j;
	size_t	i;
	size_t	item_len;

	j = 0;
	i = 0;
	while (j < count)
	{
		item_len = 0;
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		while (s[i] != c && s[i])
		{
			item_len++;
			i++;
		}
		ptr[j] = ft_substr(s, i - item_len, item_len);
		j++;
	}
	ptr[count] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**ptr;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	ptr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	ptr = push_words(s, ptr, c, count);
	return (ptr);
}

/*
int	main()
{
	char	str[] = "  Hi   adeef  sdfsdf  Hellss    Boossi   ";
	ft_split(str, ' ');
	return (0);
}
*/