/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:10:59 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:10:59 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			counter;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	counter = 0;
	while (counter < n)
	{
		*p = (unsigned char) x;
		p++;
		counter++;
	}
	return (ptr);
}
