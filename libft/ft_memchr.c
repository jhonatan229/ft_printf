/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:09:41 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:09:41 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	*findc;

	ps = (unsigned char *) s;
	findc = NULL;
	while (n--)
	{
		if (*ps == (unsigned char)c)
		{
			findc = ps;
			break ;
		}
		ps++;
	}
	return (findc);
}
