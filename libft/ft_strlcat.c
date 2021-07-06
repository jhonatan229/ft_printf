/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:33:57 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/18 13:33:57 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			counter;
	size_t			pnt;

	counter = 0;
	pnt = 0;
	while (dst[counter] != 0 && counter < size)
		counter++;
	while ((counter + pnt + 1) < size && src[pnt] != 0)
	{
		dst[counter + pnt] = src[pnt];
		pnt++;
	}
	if (counter < size)
		dst[counter + pnt] = '\0';
	return (counter + ft_strlen(src));
}
