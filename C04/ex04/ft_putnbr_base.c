/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalon <masalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:29:18 by masalon           #+#    #+#             */
/*   Updated: 2025/07/05 05:02:41 by masalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	n;

	if (!is_valid_base(base))
		return ;
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	i = 0;
	while (base[i])
		i++;
	if (n >= i)
		ft_putnbr_base(n / i, base);
	ft_putchar(base[n % i]);
}
