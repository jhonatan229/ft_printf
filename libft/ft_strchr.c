/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/18 15:00:46 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != 0)
	{
		if (s[count] == (char)c)
			return ((char *)s + count);
		count++;
	}
	if (s[count] == (char)c)
		return ((char *)s + count);
	return (NULL);
}
