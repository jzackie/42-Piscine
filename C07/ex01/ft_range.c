/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalon <masalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 04:24:25 by masalon           #+#    #+#             */
/*   Updated: 2025/07/12 04:24:26 by masalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*new;

	if (min >= max)
		return (NULL);
	len = max - min;
	new = (int *)malloc(sizeof(int) * len);
	if (!new)
		return (NULL);
	i = 0;
	while (min < max)
	{
		new[i] = min;
		min++;
		i++;
	}
	return (new);
}
