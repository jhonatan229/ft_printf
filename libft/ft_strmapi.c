/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:04:55 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/31 17:36:34 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*rslt;

	count = 0;
	rslt = malloc(ft_strlen(s) + 1);
	if (rslt == NULL)
		return (NULL);
	while (s[count] != 0)
	{
		rslt[count] = f(count, s[count]);
		count++;
	}
	rslt[count] = 0;
	return (rslt);
}
