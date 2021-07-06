/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:10:19 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:10:19 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, const void *from, int c, size_t numBytes)
{
	size_t	count;
	char	*pto;
	char	*pfrom;

	pto = (char *)to;
	pfrom = (char *)from;
	count = 0;
	while (count < numBytes)
	{
		pto[count] = pfrom[count];
		if (pfrom[count] == (char)c)
		{
			return (to + ++count);
		}
		count++;
	}
	return (NULL);
}
