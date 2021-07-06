/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:10:36 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:10:36 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t numBytes)
{
	char	*pto;
	char	*pfrom;

	pto = (char *)to;
	pfrom = (char *)from;
	if (to == NULL && from == NULL)
		return (NULL);
	while (numBytes--)
	{
		*pto = *pfrom;
		pfrom++;
		pto++;
	}
	return (to);
}
