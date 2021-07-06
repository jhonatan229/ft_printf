/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:10:44 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:10:44 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t numBytes)
{
	char	*pto;
	char	*pfrom;

	pto = (char *)to;
	pfrom = (char *)from;
	if (to == NULL && from == NULL)
		return (NULL);
	if (ft_memcmp(to, from, numBytes) == 0)
		return (to);
	if (to < from)
		ft_memcpy(pto, pfrom, numBytes);
	else
		while (numBytes--)
			pto[numBytes] = pfrom[numBytes];
	return (to);
}
