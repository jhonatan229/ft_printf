/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:27:20 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 23:27:20 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t			pointer;
	unsigned char	*psrc;

	psrc = (unsigned char *) src;
	pointer = 0;
	if (n > 0)
	{
		while (pointer < n - 1 && psrc[pointer] != '\0')
		{
			dest[pointer] = psrc[pointer];
			pointer++;
		}
		dest[pointer] = '\0';
	}
	return (ft_strlen(src));
}
