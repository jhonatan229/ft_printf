/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:45:05 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/31 17:21:20 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rslt;
	int		sizemax;

	sizemax = nmemb * size;
	rslt = malloc(sizemax);
	if (rslt == NULL)
		return (NULL);
	ft_bzero(rslt, sizemax);
	return (rslt);
}
