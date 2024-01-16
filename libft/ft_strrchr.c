/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:52:50 by mmughedd          #+#    #+#             */
/*   Updated: 2023/11/02 16:52:52 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == '\0')
	{
		s += len;
		return ((char *)s);
	}
	while (len-- > 0)
	{
		if (s[len] == (char)c)
		{
			s += len;
			return ((char *)s);
		}
	}
	return (NULL);
}
