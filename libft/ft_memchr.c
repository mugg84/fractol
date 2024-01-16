/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:10:31 by mmughedd          #+#    #+#             */
/*   Updated: 2023/11/03 12:10:36 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	ch;

	src = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*src == ch)
			return (src);
		src++;
	}
	return (NULL);
}
