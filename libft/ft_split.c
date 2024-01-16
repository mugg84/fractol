/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:47:56 by mmughedd          #+#    #+#             */
/*   Updated: 2023/11/04 16:48:00 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static size_t	word_counter(char const *s, char sep)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && !is_sep(s[0], sep))
			counter++;
		else if (i > 0 && is_sep(s[i - 1], sep) && !is_sep(s[i], sep))
			counter++;
		i++;
	}
	return (counter);
}

static size_t	w_length(char const *s, char sep, int i)
{
	size_t	len;

	len = 0;
	while (s[i] && !is_sep(s[i], sep))
	{
		i++;
		len++;
	}
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	size;
	size_t	i;
	size_t	j;

	size = word_counter(s, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s) && s[i] && j < size)
	{
		if (is_sep(s[i], c))
			i++;
		else if (!is_sep(s[i], c))
		{
			arr[j] = (char *)malloc(sizeof(char) * (w_length(s, c, i)));
			ft_strlcpy(arr[j], &s[i], w_length(s, c, i));
			i += (w_length(s, c, i));
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
