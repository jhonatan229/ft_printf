/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:12:00 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/18 16:12:00 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	phay;
	size_t	pneed;

	phay = 0;
	if (*needle == 0)
		return ((char *) haystack);
	while (haystack[phay] != 0)
	{
		pneed = 0;
		while (haystack[phay + pneed] == needle[pneed] && (phay + pneed) < len)
		{
			if (needle[pneed + 1] == 0)
				return ((char *) haystack + phay);
			pneed++;
		}
		phay++;
	}
	return (NULL);
}
